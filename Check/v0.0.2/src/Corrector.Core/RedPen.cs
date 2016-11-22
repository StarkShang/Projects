using Corrector.Core.Global;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;
using System.Diagnostics;
using System.Text.RegularExpressions;
using System.Text;

namespace Corrector.Core
{
    public static class RedPen {
        struct TestCase {
            public string InputData;
            public string OutputData;
        }
        public static void Test(string label) {
            List<string> whoNotSubmit = new List<string>();
            Cell.Traverse(depth: 1, action: dir => {
                var cellPath = Path.Combine(dir.FullName, label);
                if (dir == Cell.Root) return;
                // 检查是否已提交作业
                if (!Directory.Exists(cellPath)) {
                    lock (whoNotSubmit) whoNotSubmit.Add(dir.Name + "," + ConfigInfo.NameList[dir.Name]);
                    return;
                }
                // 已经提交作业
                // 开始批改作业
                StringBuilder recorder = new StringBuilder();
                foreach (var container in new DirectoryInfo(cellPath).GetDirectories()) {
                    // 判断是否是L__文件夹
                    if (Regex.Match(container.Name, @"L\d+").Success) Correct(container, recorder);
                    //if (Regex.Match(container.Name, @"MFC").Success) CorrectMFC(container);
                }
                File.WriteAllText(Path.Combine(cellPath, "record"), recorder.ToString());
            });

            // 作业情况总表记录
            var target = Path.Combine(Cell.Root.FullName, $"{label}.record");
            // 记录没交作业的
            StringBuilder builder = new StringBuilder();
            whoNotSubmit.Sort();
            builder.AppendLine("Who did not submit : ");
            foreach (var item in whoNotSubmit) {
                builder.AppendLine("\t" + item);
            }
            builder.AppendLine();
            // 整合批改作业记录
            foreach (var cell in Cell.Root.GetDirectories()) {
                var source = Path.Combine(cell.FullName, label, "record");
                builder.AppendLine(cell.Name);
                if (File.Exists(source)) builder.Append(File.ReadAllText(source));
                else builder.AppendLine("Have no record");
            }
            // 写文件
            File.WriteAllText(target, builder.ToString());
        }
        public static void TestMFC(string label) {
            foreach (var cell in Cell.Root.GetDirectories()) {
                var path = new DirectoryInfo(Path.Combine(cell.FullName, label, "MFC"));
                if (!path.Exists) continue;
                CorrectMFC(path);
            }
        }
        private static void Correct(DirectoryInfo container, StringBuilder recorder)
        {
            var path = $"{container.Parent.Name}\\{container.Name}";
            // 复制测试所需代码
            // 载入测试用例
            var contPath = container.FullName;
            var toolPath = ConfigInfo.RootMaps["tools"];
            var testPath = Path.Combine(ConfigInfo.RootMaps["tools"], container.Parent.Name, Regex.Match(container.Name, @"L\d+").Value);
            File.Copy(Path.Combine(toolPath, @"main.cpp"), Path.Combine(contPath, @"main.cpp"), true);
            File.Copy(Path.Combine(toolPath, @"builder.bat"), Path.Combine(contPath, @"builder.bat"), true);
            File.Copy(Path.Combine(toolPath, @"project.xml"), Path.Combine(contPath, @"project.xml"), true);
            File.Copy(Path.Combine(testPath, @"test.hpp"), Path.Combine(contPath, @"test.hpp"), true);
            var cases = JsonConvert.DeserializeObject<Queue<TestCase>>(File.ReadAllText(Path.Combine(testPath, @"case.json")));
            // 编译源码
            Process process = new Process();
            process.StartInfo.FileName = Path.Combine(contPath, @"builder.bat");
            process.StartInfo.Arguments = $"\"{contPath}\"";
            process.StartInfo.CreateNoWindow = true;
            process.Start();
            process.WaitForExit();
            // 若不存在 main.exe 则不存在, 则说明编译未通过
            var binPath = Path.Combine(contPath, @"main.exe");
            if (!File.Exists(binPath)) {
                recorder.AppendLine($"{path} : Compile failed!");
                return;
            }
            // 开始测试
            bool isOver = false;
            process.StartInfo.FileName = binPath;
            process.StartInfo.Arguments = cases.Count.ToString();
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.RedirectStandardError = true;
            process.StartInfo.CreateNoWindow = true;
            process.OutputDataReceived += (object sender, DataReceivedEventArgs e) => {
                if (e.Data == null) return;
                var m = Regex.Match(e.Data, @"\[[i,o,e]\]");
                if (m.Success) {
                    switch (m.Value) {
                        case "[i]":
                            var testcase = cases.Dequeue();
                            var param = string.Join(" ", new string[] { "-i", testcase.InputData, "-o", testcase.OutputData });
                            process.StandardInput.WriteLine(param);
                            break;
                        case "[o]":
                            isOver = true;
                            recorder.AppendLine($"{path} : {e.Data.Replace(@"[o] ", "")}");
                            break;
                        case "[e]":
                            recorder.AppendLine($"{path} : {e.Data.Replace(@"[e] ", "")}");
                            break;
                        default: break;
                    }
                }
            };
            process.Start();
            process.BeginOutputReadLine();
            process.BeginErrorReadLine();
            process.WaitForExit(5000);
            if (!process.HasExited) {
                process.Kill();
                recorder.AppendLine($"{path} : Run time out!");
                isOver = true;
            }
            if (!isOver) {
                recorder.AppendLine($"{path} : Run failed!");
            }
        }

        private static void CorrectMFC(DirectoryInfo container) {
            System.Console.WriteLine(container.FullName);
            var projectPath = new StringBuilder();
            Cell.Traverse(dir => {
                foreach (var file in dir.GetFiles())
                    if (Regex.Match(file.Name, @".*\.sln").Success)
                        lock (projectPath)
                            projectPath.Append(file.FullName);
            });
            if (projectPath.ToString() == "") return;
            Compiler.Build(projectPath.ToString());
            var execPath = new StringBuilder();
            Cell.Traverse(dir => {
                foreach (var file in dir.GetFiles())
                    if (Regex.Match(file.Name, @".*\.exe").Success)
                        lock (execPath)
                            execPath.Append(file.FullName);
            });
            if (projectPath.ToString() == "") {
                System.Console.WriteLine("Compile failed!");
                return;
            }
            var process = new Process();
            process.StartInfo.FileName = execPath.ToString();
            process.Start();
            process.WaitForExit();
            Compiler.CleanMFC(new FileInfo(projectPath.ToString()));
        }
    }
}
