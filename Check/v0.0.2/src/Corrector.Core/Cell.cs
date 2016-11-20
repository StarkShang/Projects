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

        public static void Show() {
            var names = new List<string>();
            Traverse(dir => {
                lock(names) names.Add(dir.Name);
            });
            names.Sort();
            Console.WriteLine($"共有{names.Count}个容器。");
            foreach (var item in names)
                Console.WriteLine(item);
            //Traverse(dir => Console.WriteLine(dir.Name));
        }

        public static void Remove(string path) {
            var container = new List<string>();
            Traverse(dir => {
                if (dir.FullName.EndsWith(path))
                    lock (container)
                        container.Add(dir.FullName);
            });
            foreach (var item in container) Directory.Delete(item, true);
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

        public static void Traverse(Action<DirectoryInfo> action, int depth = int.MaxValue) {
            DirectoryHelper.Traverse(Root, action, depth);
            //Parallel.ForEach(Root.GetDirectories(), dir => action(dir));
        }

        static Cell() {
            if (ConfigInfo.RootMaps.ContainsKey("cells")) {
                Root = new DirectoryInfo(ConfigInfo.RootMaps["cells"]);
            }
        }
    }
}
