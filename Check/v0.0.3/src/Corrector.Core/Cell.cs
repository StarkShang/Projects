using Corrector.Core.Global;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public static class Cell
    {
        public static DirectoryInfo Root { get; }

        public static void InitCells() {
            Parallel.ForEach(ConfigInfo.NameList.Keys, 
                             Id => Root.CreateSubdirectory(Id));
        }

        public static void Show(string label) {
            var container = new List<string>();
            Traverse(label: label, action: dir => Console.WriteLine(dir.FullName));
            container.Sort();
            foreach (var item in container) Console.WriteLine(item);
        }

        public static void Remove(string label) {
            var container = new List<DirectoryInfo>();
            Traverse(label:label, action: directory => {
                    lock (container) container.Add(directory);
            });
            foreach (var dir in container) dir.Delete(true);
        }

        public static void Dispatch(string path) {
            if (path == null) return;

            var directoryInfo = new DirectoryInfo(path);
            Parallel.ForEach(
                source: directoryInfo.GetDirectories(),
                body: dir => {
                    var id = Regex.Match(dir.Name, @"51\d+").Value;
                    DirectoryHelper.Traverse(dir, d => {
                        var query = from child in d.GetDirectories()
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
                });
        }

        public static void Clean() {

        }

        public static void Tidy(string pattern, string label = "") {
            Traverse(dir => {
                foreach (var file in dir.GetFiles()) {
                    var contents  = File.ReadAllText(file.FullName);
                    var match = Regex.Match(contents, @"\b" + pattern + @"\w+\b");
                    if (match.Success) {
                        contents = contents.Replace(match.Value, pattern);
                        File.WriteAllText(file.FullName, contents);
                    }
                }
            }, label: label);
        }

        private static void Traverse(DirectoryInfo directory, Action<DirectoryInfo> action, string label = "", int depth = int.MaxValue)
        {
            if (depth-- < 0 || directory.GetDirectories() == null) return;
            if (label == "" || directory.FullName.EndsWith(label)) action(directory);
            Parallel.ForEach(directory.GetDirectories(), dir => Traverse(dir, action, label, depth));
        }

        public static void Traverse(Action<DirectoryInfo> action, string label = "", int depth = int.MaxValue) {
            Traverse(Root, action, label, depth);
        }

        static Cell() {
            if (ConfigInfo.RootMaps.ContainsKey("cells")) {
                Root = new DirectoryInfo(ConfigInfo.RootMaps["cells"]);
            }
        }
    }
}
