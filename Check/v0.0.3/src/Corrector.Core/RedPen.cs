using Corrector.Core.Global;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;
using System.Diagnostics;
using System.Text.RegularExpressions;
using System;

namespace Corrector.Core
{
    public static class RedPen {
        private const string recordFileName = @"record.txt";

        struct TestCase {
            public string InputData;
            public string OutputData;
        }

        public static void RollCall() {

        }

        public static void Test(string label) {
            var fileList = new List<string>();
            Cell.Traverse(label: label, action: directory => {
                Correct(container: directory);
                var recordFile = $"{directory.FullName}\\{recordFileName}";
                if (File.Exists(recordFile))
                    lock (fileList) fileList.Add(recordFile);
            });
            // 合并批改记录
            fileList.Sort();
            File.WriteAllText($"{Cell.Root.FullName}\\{label}.{recordFileName}", string.Join("\r\n", fileList));
        }
        /// <summary>
        /// 测试一次作业. eg. id\L11
        /// </summary>
        /// <param name="container">一次作业的根目录</param>
        public static void Correct(DirectoryInfo container)
        {
            Logger logger = new Logger($"{container.Parent.Name}\\{container.Name}");
            // 设置地址
            var cntrPath = container.FullName;
            var toolPath = ConfigInfo.RootMaps["tools"];
            foreach (var dir in container.GetDirectories()) {
                var testPath = Path.Combine(toolPath, container.Name, Regex.Match(dir.Name, @"L\d+").Value);
                File.Copy(Path.Combine(toolPath, @"main.cpp"), Path.Combine(dir.FullName, @"main.cpp"), true);
                File.Copy(Path.Combine(toolPath, @"builder.bat"), Path.Combine(dir.FullName, @"builder.bat"), true);
                File.Copy(Path.Combine(toolPath, @"project.vcxproj"), Path.Combine(dir.FullName, @"project.vcxproj"), true);
                File.Copy(Path.Combine(testPath, @"test.hpp"), Path.Combine(dir.FullName, @"test.hpp"), true);
                var cases = JsonConvert.DeserializeObject<Queue<TestCase>>(File.ReadAllText(Path.Combine(testPath, @"case.json")));
                Compiler.Build(Path.Combine(dir.FullName, @"project.vcxproj"));
                // 若没有找到 main.exe 程序则编译失败
                // 若找到 main.exe 程序则进行测试
                var binPath = Path.Combine(dir.FullName, @"main.exe");
                if (!File.Exists(binPath)) logger.Log(@"Compile failed!");
                else {
                    // 开始测试
                    bool isOver = false;
                    var process = new Process();
                    process.StartInfo.FileName = binPath;
                    process.StartInfo.Arguments = cases.Count.ToString();
                    process.StartInfo.UseShellExecute = false;
                    process.StartInfo.RedirectStandardInput = true;
                    process.StartInfo.RedirectStandardOutput = true;
                    process.StartInfo.RedirectStandardError = true;
                    process.StartInfo.CreateNoWindow = true;
                    process.OutputDataReceived += (object sender, DataReceivedEventArgs e) => {
                        if (e.Data == null) return;
                        var match = Regex.Match(e.Data, @"\[[i,o,e]\]");
                        if (!match.Success) return;
                        switch (match.Value) {
                            case "[i]": var testcase = cases.Dequeue(); var param = $"-i {testcase.InputData} -o {testcase.OutputData}";
                                process.StandardInput.WriteLine(param); break;
                            case "[o]": isOver = true; logger.Log(e.Data.Replace(@"[o] ", "")); break;
                            case "[e]": logger.Log(e.Data.Replace(@"[e] ", "")); break;
                            default: break;
                        }
                    };
                    process.Start();
                    process.BeginOutputReadLine();
                    process.BeginErrorReadLine();
                    process.WaitForExit(5000);
                    if (!process.HasExited) {
                        process.Kill();
                        logger.Log(@"Run time out!");
                        isOver = true;
                    }
                    if (!isOver) logger.Log(@"Run failed!");
                }
            }
            logger.WriteFile(Path.Combine(container.FullName, "logs.txt"));
        }

        public static void TestMFC(string label) {
            var exeList = new List<string>();
            Cell.Traverse(label: $"{label}\\MFC", action: directory => {
                var exePath = CorrectMFC(directory);
                if (exePath != null)
                    lock (exeList) exeList.Add(exePath);
            });
            foreach (var exe in exeList)
                if (exe != "")  Process.Start(exe).WaitForExit();
        }
        public static string CorrectMFC(DirectoryInfo container) {
            Console.WriteLine(container.FullName);
            // 查找 sln 解决方案文件
            var projectPath = new List<string>();
            Cell.Traverse(dir => {
                foreach (var file in dir.GetFiles())
                    if (file.Name.EndsWith(@".sln"))
                        lock (projectPath) projectPath.Add(file.FullName);
            });
            // 若没有 sln 解决方案文件则无法编译, 返回 null
            if (projectPath[0] == "") {
                Console.WriteLine("\tHave no sln file!");
                return null;
            }
            // 若存在 sln 解决方案文件则进行编译
            Compiler.Build(projectPath[0]);
            // 查找编译生成的 exe 文件
            var execPath = new List<string>();
            Cell.Traverse(dir => {
                foreach (var file in dir.GetFiles())
                    if (file.Name.EndsWith(@".exe"))
                        lock (execPath) execPath.Add(file.FullName);
            });
            // 若没有 exe 可执行文件则说明编译失败, 返回 null
            if (execPath[0] == "") {
                Console.WriteLine("\tCompile failed!");
                return null;
            }
            return execPath[0];
        }
    }
}
