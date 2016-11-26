using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public static class Manager
    {
        public static DirectoryInfo Root { get; } = ConfigInfo.CellPath;

        public static void InitCells() {
            Parallel.ForEach(ConfigInfo.StudentList.Keys,
                             Id => Root.CreateSubdirectory(Id.ToString()));
        }

        public static async void RemoveDirectory(string label) {
            var container = new List<DirectoryInfo>();
            await Root.Traverse(label: label,
                action: async directory => await Task.Run(() => { lock (container) container.Add(directory); }));
            foreach (var dir in container) dir.Delete(true);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="path">交作业的目录</param>
        public static void Dispatch(string path)
        {
            if (path == null) return;

            var directoryInfo = new DirectoryInfo(path);
            Parallel.ForEach(
                source: directoryInfo.GetDirectories(),
                body: dir => {
                    var id = Regex.Match(dir.Name, @"51\d+").Value;
                    var query = from child in dir.GetDirectories()
                                where Regex.Match(child.Name, @"L\d{2}").Success
                                select child;
                    foreach (var item in query) {
                        var q = from file in item.GetFiles()
                                where Regex.Match(file.Name, @"func\w*").Success
                                select file;
                        if (q.Count() != 0) {
                            var p = Path.Combine(Root.FullName, id, directoryInfo.Name, item.Name);
                            if (!Directory.Exists(p)) Directory.CreateDirectory(p);
                            File.Copy(q.First().FullName, Path.Combine(p, "func.hpp"), true);
                        }
                    }
                });
        }

        public static async void RollCall(string label) {
            var directories = await Root.FindDirectories(label: label);
            var query = from dir in directories
                        orderby dir.Name ascending
                        select dir.Parent.Name;
            foreach (var item in query)  Console.WriteLine(item);
            Console.WriteLine($"Total : {directories.Count}");
        }

        public static async void Correct(string label) {
            var cells = from dir in Root.GetDirectories()
                        where ConfigInfo.StudentList.ContainsKey(dir.Name)
                        select Cell.CellCreator(dir.Name);
            foreach (var cell in cells) {
                await cell.Correct(label);
            }
            // 合并批改记录
            var directories = await Root.FindDirectories(label);
            await Task.Delay(1000);
            var logList = new List<string>();
            foreach (var dir in directories) {
                var files = await dir.FindFiles(fileName: "record");
                foreach (var f in files) logList.Add(f.FullName);
            }
            logList.Sort();
            var logFilePath = $"{Root.FullName}\\{label}.log";
            if (File.Exists(logFilePath)) File.Delete(logFilePath);
            foreach (var item in logList) File.AppendAllText(logFilePath, File.ReadAllText(item) + "\r\n");
        }

        public static void CorrectMFC(string label)
        {
            var cells = from cell in Root.GetDirectories()
                        where ConfigInfo.StudentList.ContainsKey(cell.Name)
                        select new DirectoryInfo($"{cell.FullName}\\{label}\\MFC");
            // 编译到运行的管线
            var pipeline = new Queue<string>();
            // 设置编译线程
            Action compileEvent = async () => {
                foreach (var cell in cells) {
                    var compiler = new Builder();
                    var compileResult = await compiler.BuildMFC(cell);
                    if (compileResult.ExecFile != null) {
                        lock (pipeline) pipeline.Enqueue(compileResult.ExecFile.FullName);
                    }
                }
                lock (pipeline) pipeline.Enqueue("end");
            };
            // 设置运行线程
            Action executeEvent = async () => {
                var executableFile = "start";
                var redPen = new RedPen();
                while (executableFile != "end") {
                    if (File.Exists(executableFile)) redPen.CorrectMFC(new FileInfo(executableFile));
                    await Task.Run(()=> { while (pipeline.Count != 0) ; });
                    executableFile = pipeline.Dequeue();
                }
            };

            Parallel.Invoke(compileEvent, executeEvent);
        }

        public static async void Show(string label) {
            var list = new List<string>();
            await Root.Traverse(label: label, action: async directory => {
                await Task.Run(() => { lock (list) list.Add(directory.Parent.Name); });
            });
            list.Sort();
            foreach (var item in list) Console.WriteLine(item);
        }
    }
}
