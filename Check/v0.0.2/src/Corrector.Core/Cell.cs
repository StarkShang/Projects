using Corrector.Core.Global;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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

        public static void Traverse(Action<DirectoryInfo> action) {
            Parallel.ForEach(Root.GetDirectories(), dir => action(dir));
        }



        static Cell() {
            if (ConfigInfo.RootMaps.ContainsKey("cells")) {
                Root = new DirectoryInfo(ConfigInfo.RootMaps["cells"]);
            }
        }
    }
}
