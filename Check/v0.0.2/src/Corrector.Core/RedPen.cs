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
    public class RedPen {
        struct TestCase
        {
            string InputData;
            string OutputData;
        }
        public void Test(string label) {
            Cell.Traverse(dir => {
                var cellPath = Path.Combine(dir.FullName, label);
                var testPath = Path.Combine(ConfigInfo.RootMaps["tools"], label);
                File.Copy(Path.Combine(testPath, @"test.hpp"), Path.Combine(cellPath, @"test.hpp"));
                File.Copy(Path.Combine(testPath, @"main.cpp"), Path.Combine(cellPath, @"main.cpp"));
                File.Copy(Path.Combine(testPath, @"case.json"), Path.Combine(cellPath, @"case.json"));
                var cases = JsonConvert.DeserializeObject<TestCase[]>(File.ReadAllText(Path.Combine(cellPath, @"case.json")));

                Process process = new Process();
                process.StartInfo.FileName = "clang-3.5";
                process.StartInfo.Arguments = "-o main main.cpp";
                process.Start();
                process.WaitForExit();
                File.Delete(Path.Combine(cellPath, @"main.obj"));

                process.StartInfo.FileName = "main";
                process.StartInfo.Arguments = cases.Length.ToString();
                process.StartInfo.UseShellExecute = false;
                process.StartInfo.RedirectStandardInput = true;
                process.StartInfo.RedirectStandardOutput = true;
                process.StartInfo.RedirectStandardError = true;
                process.StartInfo.CreateNoWindow = true;
                process.Start();
                process.WaitForExit();
            });
        }
    }
}
