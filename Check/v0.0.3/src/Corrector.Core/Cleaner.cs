using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public class Cleaner
    {
        private static readonly string[] UselessSuffix = {
            ".log",".iobj",".ipdb",".obj",".pdb",".sdf"
        };

        public static async void DeleteFiles(string label, string fileName = null, string suffixes = null) {
            if (fileName == null && suffixes == null) return;
            suffixes = null;
            var root = new DirectoryInfo(ConfigInfo.RootMaps["cells"]);
            var directories = await root.FindDirectories(label: label);
            var fileList = new List<FileInfo>();
            foreach (var dir in directories) {
                var list = await dir.FindFiles(fileName: fileName, suffixes: suffixes);
                foreach (var item in list) {
                    fileList.Add(item);
                }
            }

            foreach (var file in fileList)
                if (file.Exists)
                    file.Delete();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath"></param>
        public static async void Clean(DirectoryInfo root) {
            foreach (var suffixes in UselessSuffix) {
                var files = await root.FindFiles(suffixes: suffixes);
                foreach (var f in files) f.Delete();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="projectPath"></param>
        public static async void CleanMFC(DirectoryInfo root) {
            var debugList = new List<DirectoryInfo>();
            await root.Traverse(label: "Debug", action: dir => {
                return new Task(() => { lock (debugList) debugList.Add(dir); });
            });
            foreach (var d in debugList) d.Delete(true);

            Clean(root);
        }
    }
}
