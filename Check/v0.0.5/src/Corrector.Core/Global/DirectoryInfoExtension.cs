using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public static class DirectoryInfoExtension
    {
        public static async Task Traverse(this DirectoryInfo directory, 
                                          Func<DirectoryInfo, Task> action, 
                                          string label = "", int depth = int.MaxValue) {
            if (depth-- < 0 || directory.GetDirectories() == null) return;
            if (label == "" || directory.FullName.EndsWith(label)) await action(directory);
            Parallel.ForEach(directory.GetDirectories(), async dir => await Traverse(dir, action, label, depth));
        }

        public static async Task<List<DirectoryInfo>> FindDirectories(
            this DirectoryInfo directory, string label = "", int depth = int.MaxValue) {
            var directoryList = new List<DirectoryInfo>();
            await Traverse(directory: directory, label: label, depth: depth, action: async dir => {
                await Task.Run(() => { lock (directoryList) directoryList.Add(dir); });
            });
            return directoryList;
        }

        public static async Task<List<FileInfo>> FindFiles(
            this DirectoryInfo directory,
            string fileName = null, string suffixes = null,
            string label = "", int depth = int.MaxValue) {
            var fileList = new List<FileInfo>();
            if (fileName == null && suffixes == null) return fileList;

            await Traverse(directory: directory, label: label, depth: depth, action: async dir => {
                await Task.Run(() => {
                    foreach (var file in dir.GetFiles()) {
                        if ((fileName == null || fileName == file.Name.Remove(file.Name.IndexOf(file.Extension))) &&
                            (suffixes == null || suffixes == file.Extension))
                            lock (fileList) fileList.Add(file);
                    }

                });
            });
            return fileList;
        }

        public static DirectoryInfo GetSubdirectory(this DirectoryInfo directory, string subdirectoryName) {
            foreach (var dir in directory.GetDirectories()) {
                if (dir.Name == subdirectoryName) return dir;
            }
            return null;
        }

        public static FileInfo GetSubfile(this DirectoryInfo directory, string subFileName) {
            foreach (var file in directory.GetFiles()) {
                if (file.Name == subFileName) return file;
            }
            return null;
        }

        public static async void Show(this DirectoryInfo directory, string label)
        {
            var container = new List<string>();
            await Traverse(directory: directory, label: label, action: async dir => await Task.Run(() => Console.WriteLine(dir.FullName)));
            container.Sort();
            foreach (var item in container) Console.WriteLine(item);
        }
    }
}
