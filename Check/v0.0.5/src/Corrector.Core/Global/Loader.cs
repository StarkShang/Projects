using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Newtonsoft.Json;

namespace Corrector.Core
{
    public static class Loader
    {
        public static void Init(string configData) {
            var info = JsonConvert.DeserializeAnonymousType(configData, 
                new {
                workshop = "",
                testroot = "",
                compiler = new { exec = "", includes = new List<string>() },
                linker = new { exec = "", libraries = new List<string>() }
            });

            Container.ContainerRoot = new DirectoryInfo(info.workshop);
            Builder.CompilerExec = new FileInfo(info.compiler.exec);
            Builder.IncludePath = info.compiler.includes.Select(item => new DirectoryInfo(item)).ToArray();
            Builder.LinkerExec = new FileInfo(info.linker.exec);
            Builder.LibraryPath = info.linker.libraries.Select(item => new DirectoryInfo(item)).ToArray();
            Tester.TestRoot = new DirectoryInfo(info.testroot);

            var nameListPath = Path.Combine(Container.ContainerRoot.FullName, @"namelist.json");
            var records = JsonConvert.DeserializeObject<List<User.Student>>(File.ReadAllText(nameListPath));
            foreach (var pair in records)
                User.StudentList.Add(pair.Id, pair);
        }
    }
}
