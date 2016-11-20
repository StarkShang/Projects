using Corrector.Core.Global;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.Diagnostics;

namespace Corrector.Core
{
    public static class RedPen {
        struct TestCase
        {
            string InputData;
            string OutputData;
        }
        public static void Test(string label) {
            List<string> whoNotSubmit = new List<string>();
            Cell.Traverse(depth: 2, action: dir => {
                var cellPath = Path.Combine(dir.FullName, label);
                if (!Directory.Exists(cellPath)) {
                    lock (whoNotSubmit) whoNotSubmit.Add(dir.Name);
                    return;
                }

                // 已经提交作业
                foreach (var container in Directory.GetDirectories(cellPath)) {
                    var toolPath = ConfigInfo.RootMaps["tools"];
                    var testPath = Path.Combine(ConfigInfo.RootMaps["tools"], label);
                    File.Copy(Path.Combine(toolPath, @"main.cpp"), Path.Combine(container, @"main.cpp"));
                    File.Copy(Path.Combine(toolPath, @"builder.bat"), Path.Combine(container, @"builder.bat"));
                    File.Copy(Path.Combine(toolPath, @"project.xml"), Path.Combine(container, @"project.xml"));
                    File.Copy(Path.Combine(testPath, @"test.hpp"), Path.Combine(container, @"test.hpp"));
                    var cases = JsonConvert.DeserializeObject<TestCase[]>(File.ReadAllText(Path.Combine(testPath, @"case.json")));

                    Process process = new Process();
                    process.StartInfo.FileName = Path.Combine(container, @"builder.bat");
                    process.StartInfo.Arguments = Path.Combine(container, @"project.xml");
                    process.StartInfo.CreateNoWindow = true;
                    process.Start();
                    process.WaitForExit();

                    var binPath = Path.Combine(container, @"main.exe");
                    process.StartInfo.FileName = binPath;
                    process.StartInfo.Arguments = cases.Length.ToString();
                    process.StartInfo.UseShellExecute = false;
                    process.StartInfo.RedirectStandardInput = true;
                    process.StartInfo.RedirectStandardOutput = true;
                    process.StartInfo.RedirectStandardError = true;
                    process.StartInfo.CreateNoWindow = true;
                    process.Start();
                    process.WaitForExit();
                }
            });
        }
    }
}
