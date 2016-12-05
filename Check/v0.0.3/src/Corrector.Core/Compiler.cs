using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public class Compiler
    {
        private const string VSCompiler = @"D:\Softwares\Microsoft\Microsoft Visual Studio 14.0\Common7\IDE\devenv";

        public struct CompileResult {
            public FileInfo ExecFile { get; set; }
            public string Info { get; set; }
        }

        /// <summary>
        /// 构建非 MFC 工程
        /// </summary>
        /// <param name="workDirectory">工作目录</param>
        public async Task<CompileResult> Build(DirectoryInfo workDirectory) {
            if (!workDirectory.Exists) return new CompileResult() {
                ExecFile = null,
                Info = $"Cannot find the directory!"
            };
            var toolPath = ConfigInfo.RootMaps["tools"];
            var testPath = Path.Combine(toolPath, workDirectory.Parent.Name, Regex.Match(workDirectory.Name, @"L\d{2}").Value);
            File.Copy(Path.Combine(toolPath, @"main.cpp"), Path.Combine(workDirectory.FullName, @"main.cpp"), true);
            File.Copy(Path.Combine(toolPath, @"builder.bat"), Path.Combine(workDirectory.FullName, @"builder.bat"), true);

            // Get cpp files
            var cppFiles = from file in workDirectory.GetFiles()
                           where file.Extension == ".cpp"
                           select file.Name;
            string ProjectInfo = File.ReadAllText(Path.Combine(toolPath, @"project.vcxproj"));
            File.WriteAllText(Path.Combine(workDirectory.FullName, @"project.vcxproj"),
                              ProjectInfo.Replace(@"main.cpp", string.Join(";", cppFiles)));

            // File.Copy(Path.Combine(toolPath, @"project.vcxproj"), Path.Combine(workDirectory.FullName, @"project.vcxproj"), true);
            File.Copy(Path.Combine(testPath, @"test.hpp"), Path.Combine(workDirectory.FullName, @"test.hpp"), true);
            var projFile = new FileInfo($"{workDirectory.FullName}\\project.vcxproj");
            if (!projFile.Exists) new CompileResult() {
                ExecFile = null,
                Info = $"Cannont find vcxproj file!"
            };

            return await Compile(projFile, "/Build");
        }

        /// <summary>
        /// 构建 MFC 工程
        /// </summary>
        /// <param name="workDirectory">MFC目录</param>
        /// <returns></returns>
        public async Task<CompileResult> BuildMFC(DirectoryInfo workDirectory)
        {
            if (!workDirectory.Exists) return new CompileResult() {
                ExecFile = null,
                Info = $"Cannot find the directory!"
            };
            var projList = await workDirectory.FindFiles(suffixes: ".sln");
            switch (projList.Count) {
                case 0: return new CompileResult() {
                    ExecFile = null,
                    Info = $"Cannont find sln file!"
                };
                case 1: break;
                default: return new CompileResult() {
                    ExecFile = null,
                    Info = $"Find multiple sln files!"
                };
            }

            return await Compile(projList[0], "/Build");
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath">项目文件</param>
        /// <param name="parameters">编译参数</param>
        /// <returns></returns>
        private async Task<CompileResult> Compile(FileInfo projectPath, string parameters)
        {
            var rst = new CompileResult();
            var process = new Process();
            process.StartInfo.FileName = VSCompiler;
            process.StartInfo.Arguments = projectPath + " " + parameters;
            process.StartInfo.WorkingDirectory = projectPath.DirectoryName;
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.CreateNoWindow = true;
            process.Start();
            await Task.Run(async () => {
                process.WaitForExit();
                if (!process.HasExited) {
                    process.Kill();
                    rst.ExecFile = null; rst.Info = $"Compile failed -- Cannont find executable file!";
                } else {
                    var fileList = await projectPath.Directory.FindFiles(suffixes: ".exe");
                    switch (fileList.Count)
                    {
                        case 0: rst.ExecFile = null; rst.Info = $"Compile failed -- Cannont find executable file!"; break;
                        case 1: rst.ExecFile = fileList[0]; rst.Info = $"Compile success!"; break;
                        default: rst.ExecFile = null; rst.Info = $"Compile failed -- Find multiple executable files!"; break;
                    }
                }
            });
            return rst;
        }
    }
}
