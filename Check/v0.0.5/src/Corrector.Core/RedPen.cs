using Newtonsoft.Json;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text.RegularExpressions;

namespace Corrector.Core
{
    public struct TestCase {
        public string InputData;
        public string OutputData;
    }

    public struct TestResult {
        public bool State { get; set; }
        public string Info { get; set; }
    }

    public class RedPen {
        private const string recordFileName = @"record.txt";
        //private DirectoryInfo cellRoot = null;
        
        /// <summary>
        /// Run not MFC project
        /// </summary>
        /// <param name="executableFile">Executable file handle</param>
        /// <param name="logger">Logger to record runtime information</param>
        public void Correct(FileInfo executableFile, Logger logger)
        {
            if (executableFile == null) logger.Log("Cannot file executable file");
            var testPath = Path.Combine(ConfigInfo.ToolPath.FullName, executableFile.Directory.Parent.Name, Regex.Match(executableFile.Directory.Name, @"L\d{2}").Value);
            var cases = JsonConvert.DeserializeObject<Queue<TestCase>>(File.ReadAllText(Path.Combine(testPath, @"case.json")));
            bool isOver = false;
            var process = new Process();
            process.StartInfo.WorkingDirectory = executableFile.DirectoryName;
            process.StartInfo.FileName = executableFile.FullName;
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
                    case "[i]":
                        var testcase = cases.Dequeue(); var param = $"-i {testcase.InputData} -o {testcase.OutputData}";
                        process.StandardInput.WriteLine(param); break;
                    case "[o]": isOver = true; logger.Log(e.Data.Replace(@"[o] ", "")); break;
                    case "[e]": logger.Log(e.Data.Replace(@"[e] ", "")); break;
                    default: break;
                }
            };
            process.Start();
            process.BeginOutputReadLine();
            process.BeginErrorReadLine();
            process.WaitForExit(50000);
            if (!process.HasExited) {
                process.Kill();
                logger.Log(@"Run time out!");
                isOver = true;
            }
            if (!isOver) logger.Log(@"Run failed!");
        }

        public void CorrectMFC(FileInfo executableFile) {
            if (executableFile == null) return;
            Process.Start(executableFile.FullName).WaitForExit();
        }
    }
}
