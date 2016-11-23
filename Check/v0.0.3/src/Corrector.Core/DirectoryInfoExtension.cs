using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public static class DirectoryInfoExtension
    {
        public static async void Traverse(this DirectoryInfo directory, 
                                          Func<DirectoryInfo, Task> action, 
                                          string label = "", int depth = int.MaxValue) {
            if (depth-- < 0 || directory.GetDirectories() == null) return;
            if (label == "" || directory.FullName.EndsWith(label)) await action(directory);
            //foreach (var dir in directory.GetDirectories()) {
            //    Traverse(dir, action, label, depth);
            //}
            Parallel.ForEach(directory.GetDirectories(), dir => Traverse(dir, action, label, depth));
        }

        public static List<FileInfo> FindFiles(
            this DirectoryInfo directory,
            string fileName = null, string suffixes = null,
            string label = "", int depth = int.MaxValue) {
            var fileList = new List<FileInfo>();
            Traverse(directory: directory, label: label, depth: depth, action: async dir => {
                await Task.Run(() => {
                    foreach (var file in dir.GetFiles())
                        if ((fileName == null || fileName == file.Name) &&
                            (suffixes == null || suffixes == file.Extension))
                                lock (fileList) fileList.Add(file);
                });
            });
            return fileList;
        }

        public static void Show(this DirectoryInfo directory, string label)
        {
            var container = new List<string>();
            Traverse(directory: directory, label: label, action: async dir => await Task.Run(() => Console.WriteLine(dir.FullName)));
            container.Sort();
            foreach (var item in container) Console.WriteLine(item);
        }
    }
}
