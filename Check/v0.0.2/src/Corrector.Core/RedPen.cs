using Corrector.Core.Global;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.Diagnostics;
using System.Text.RegularExpressions;
using System.Text;

namespace Corrector.Core
{
    public static class RedPen {
        struct TestCase
        {
            public string InputData;
            public string OutputData;
        }
        public static void Test(string label)
        {
            List<string> whoNotSubmit = new List<string>();
            Cell.Traverse(depth: 1, action: dir =>
            {
                var cellPath = Path.Combine(dir.FullName, label);
                if (!Directory.Exists(cellPath))
                {
                    lock (whoNotSubmit) whoNotSubmit.Add(dir.Name);
                    return;
                }

                // 已经提交作业
                StringBuilder recorder = new StringBuilder();
                foreach (var container in new DirectoryInfo(cellPath).GetDirectories())
                {
                    var contPath = container.FullName;
                    var toolPath = ConfigInfo.RootMaps["tools"];
                    var testPath = Path.Combine(ConfigInfo.RootMaps["tools"], label, container.Name);
                    File.Copy(Path.Combine(toolPath, @"main.cpp"), Path.Combine(contPath, @"main.cpp"), true);
                    File.Copy(Path.Combine(toolPath, @"builder.bat"), Path.Combine(contPath, @"builder.bat"), true);
                    File.Copy(Path.Combine(toolPath, @"project.xml"), Path.Combine(contPath, @"project.xml"), true);
                    File.Copy(Path.Combine(testPath, @"test.hpp"), Path.Combine(contPath, @"test.hpp"), true);
                    var cases = JsonConvert.DeserializeObject<Queue<TestCase>>(File.ReadAllText(Path.Combine(testPath, @"case.json")));

                    Process process = new Process();
                    process.StartInfo.FileName = Path.Combine(contPath, @"builder.bat");
                    process.StartInfo.Arguments = contPath;
                    process.StartInfo.CreateNoWindow = true;
                    process.Start();
                    process.WaitForExit();

                    var binPath = Path.Combine(contPath, @"main.exe");
                    if (!File.Exists(binPath))
                    {
                        recorder.AppendLine($"{label}\\{container.Name} : Compile failed!");
                        continue;
                    }
                    bool isOver = false;
                    process.StartInfo.FileName = binPath;
                    process.StartInfo.Arguments = cases.Count.ToString();
                    process.StartInfo.UseShellExecute = false;
                    process.StartInfo.RedirectStandardInput = true;
                    process.StartInfo.RedirectStandardOutput = true;
                    process.StartInfo.RedirectStandardError = true;
                    process.StartInfo.CreateNoWindow = true;
                    process.OutputDataReceived += (object sender, DataReceivedEventArgs e) =>
                    {
                        var match = Regex.Match(e.Data, @"\[[i,o,e]\]");
                        if (match.Success)
                        {
                            switch (match.Value)
                            {
                                case "i":
                                    var testcase = cases.Dequeue();
                                    var param = string.Join(" ", new string[] { "-i", testcase.InputData, "-o", testcase.OutputData });
                                    process.StandardInput.WriteLine(param);
                                    break;
                                case "o":
                                    isOver = true;
                                    recorder.AppendLine($"{label}\\{container.Name} : {e.Data.Replace(@"[o] ", "")}");
                                    break;
                                case "e":
                                    recorder.AppendLine($"{label}\\{container.Name} : {e.Data.Replace(@"[e] ", "")}");
                                    break;
                                default: break;
                            }
                        }
                    };
                    process.ErrorDataReceived += (object sender, DataReceivedEventArgs e) =>
                    {

                    };
                    process.Start();
                    process.WaitForExit();
                    if (!isOver)
                    {
                        recorder.AppendLine($"{label}\\{container.Name} : Run failed!");
                    }
                }

                var recordPath = Path.Combine(cellPath, "record");
                if (File.Exists(recordPath)) File.Delete(recordPath);
                var query = from record in whoNotSubmit
                            orderby record ascending
                            select record + "\r\n";
                foreach (var item in query) {
                    File.AppendAllText(recordPath, recorder.ToString());
                }
                File.AppendAllText(recordPath, recorder.ToString());
            });

            foreach (var cell in Cell.Root.GetDirectories()) {
                var source = Path.Combine(cell.FullName, label, "record");
                var target = Path.Combine(Cell.Root.FullName, "record");
                if (File.Exists(source)) {
                    var content = File.ReadAllText(source);
                    File.AppendAllText(target, content);
                }
            }
        }
    }
}
