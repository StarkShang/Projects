using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Corrector.Core
{
    public static class ConfigInfo
    {
        public static Dictionary<string, string> RootMaps = new Dictionary<string, string>();
        public static Dictionary<string, string> NameList = new Dictionary<string, string>();
        static ConfigInfo() {
            GetRootMaps();
            GetNameList(Path.Combine(RootMaps["cells"], @"namelist.nl"));
        }
        private static void GetRootMaps() {
            foreach (var dir in new DirectoryInfo(@".").GetDirectories())
                RootMaps[dir.Name] = dir.FullName;
            if (RootMaps.ContainsKey("cells"))
                RootMaps["cells"] = Path.Combine(RootMaps["cells"], DateTime.Now.Year.ToString());
        }

        private static void GetNameList(string path) {
            var query = from line in File.ReadLines(path)
                        select line.Split(',');

            foreach (var pair in query) {
                NameList.Add(pair[0], pair[1]);
            }
        }
    }
}
