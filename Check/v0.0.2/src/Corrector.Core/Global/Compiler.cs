using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Corrector.Core.Global
{
    public static class Compiler
    {
        private const string VSCompiler = @"D:\Softwares\Microsoft\Microsoft Visual Studio 14.0\Common7\IDE\devenv";
        private const string NeedToClean = @".*\.log\b|.*\.iobj\b|.*\.ipdb\b|.*\.obj\b|.*\.pdb\b|.*\.sdf\b";
        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath"></param>
        public static void Build(string projectPath) {
            Exec(projectPath, "/Build \"Release|x64\"");
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath"></param>
        public static void Clean(FileInfo projectPath) {
            var directory = projectPath.Directory;
            foreach (var dir in directory.GetDirectories()) dir.Delete(true);
            foreach (var file in directory.GetFiles())
                if (Regex.Match(file.Name, NeedToClean).Success)
                    file.Delete();
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath"></param>
        public static void CleanMFC(FileInfo projectPath) {
            var dlist = new List<DirectoryInfo>();
            var flist = new List<FileInfo>();
            DirectoryHelper.Traverse(projectPath.Directory, d => {
                if (d.Name.ToLower() == "debug")
                    lock (dlist)
                        dlist.Add(d);
                foreach (var f in d.GetFiles()) {
                    if (Regex.Match(f.Name, NeedToClean).Success)
                        lock (flist)
                            flist.Add(f);
                }
            });

            foreach (var d in dlist) d.Delete(true);
            foreach (var f in flist) f.Delete();
        }
        private static void Exec(string projectPath, string parameters) {
            var process = new Process();
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.FileName = VSCompiler;
            process.StartInfo.Arguments = projectPath + " " + parameters;
            process.StartInfo.CreateNoWindow = true;
            process.Start();
            process.WaitForExit();
        }
    }
}
