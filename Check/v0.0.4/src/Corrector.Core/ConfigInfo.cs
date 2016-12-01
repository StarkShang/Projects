﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Newtonsoft.Json;

namespace Corrector.Core
{
    public static class ConfigInfo
    {
        public static DirectoryInfo CellRoot { get; }
        public static DirectoryInfo ToolRoot { get; }
        public static DirectoryInfo CompilerRoot { get; }
        public static Dictionary<string, Student> NameList = new Dictionary<string, Student>();
        
        static ConfigInfo()
        {
            var info = JsonConvert.DeserializeAnonymousType(
                File.ReadAllText("config.json"),
                new { cellRoot = "", toolRoot = "", compilerRoot = "" });
            CellRoot = new DirectoryInfo(info.cellRoot);
            ToolRoot = new DirectoryInfo(info.toolRoot);
            CompilerRoot = new DirectoryInfo(info.compilerRoot);

            var query = from line in File.ReadLines(Path.Combine(CellRoot.FullName, "namelist.nl"))
                        select line.Split(',');
            foreach (var item in query) {
                NameList.Add(item[0], new Student() {
                    Id = item[0],
                    Name = item[1],
                    Password = item.Length > 2 ? item[2] : "sjtu"
                });
            }
        }
    }
}
