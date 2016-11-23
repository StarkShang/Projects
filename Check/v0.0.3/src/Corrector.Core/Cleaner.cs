using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public class Cleaner
    {
        private static readonly string[] UselessSuffix = {
            "log","iobj","ipdb","obj","pdb",".sdf"
        };

        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath"></param>
        public static void Clean(DirectoryInfo root) {
            foreach (var suffixes in UselessSuffix) {
                var files = root.FindFiles(suffixes: suffixes);
                foreach (var f in files)  f.Delete();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath"></param>
        public static void CleanMFC(DirectoryInfo root)
        {
            var debugList = new List<DirectoryInfo>();
            root.Traverse(label: "Debug", action: dir => {
                return new Task(() => { lock (debugList) debugList.Add(dir); });
            });
            foreach (var d in debugList) d.Delete(true);

            Clean(root);
        }
    }
}
