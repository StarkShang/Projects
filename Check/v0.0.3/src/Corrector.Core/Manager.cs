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
        public static DirectoryInfo Root { get; }

        public static void InitCells()
        {
            Parallel.ForEach(ConfigInfo.NameList.Keys,
                             Id => Root.CreateSubdirectory(Id));
        }
        private static void test() { }
        public static void RemoveDirectory(string label) {
            var container = new List<DirectoryInfo>();
            Root.Traverse(label: label,
                action: async directory =>  await Task.Run(() => { lock (container) container.Add(directory); }));
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



        public static void Correct(string label)
        {
            var cells = from cell in Root.GetDirectories()
                        where ConfigInfo.NameList.ContainsKey(cell.Name)
                        select new Cell(cell.Name);

            Parallel.ForEach(source: cells, body: cell => cell.Correct(label));
            // 合并批改记录
            var logList = new List<string>();
            Root.Traverse(label: label, action: async dir => {
                await Task.Run(() => { lock (logList) logList.Add(dir.FullName); });
            });
            logList.Sort();
            var logFilePath = $"{Root.FullName}\\{label}.log";
            if (File.Exists(logFilePath)) File.Delete(logFilePath);
            foreach (var item in logList) File.AppendAllText(logFilePath, File.ReadAllText(item));
        }

        public static void CorrectMFC(string label)
        {
            var cells = from cell in Root.GetDirectories()
                        where ConfigInfo.NameList.ContainsKey(cell.Name)
                        select new DirectoryInfo($"{cell.FullName}\\{label}\\MFC");
            // 编译到运行的管线
            var pipeline = new Queue<string>();
            // 设置编译线程
            Action compileEvent = async () => {
                foreach (var cell in cells) {
                    var compiler = new Compiler();
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

        public static void Show(string label)
        {
            var list = new List<string>();
            Root.Traverse(label: label, action: async directory => {
                await Task.Run(() => { lock (list) list.Add(directory.Parent.Name); });
            });
            list.Sort();
            foreach (var item in list) Console.WriteLine(item);
        }

        static Manager() {
            if (ConfigInfo.RootMaps.ContainsKey("cells"))
                Root = new DirectoryInfo(ConfigInfo.RootMaps["cells"]);
        }
    }
}
