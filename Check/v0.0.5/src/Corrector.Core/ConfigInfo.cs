using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Newtonsoft.Json;
using static Corrector.Core.Builder;

namespace Corrector.Core
{
    public static class ConfigInfo
    {
        private static DirectoryInfo cellPath;
        public static DirectoryInfo CellPath { get { return cellPath; } }

        private static DirectoryInfo toolPath;
        public static DirectoryInfo ToolPath { get { return toolPath; } }

        private static Compiler compilerPath;
        public static Compiler CompilerPath { get { return compilerPath; } }

        private static Linker linkerPath;
        public static Linker LinkerPath { get { return linkerPath; } }

        private static Dictionary<string, Student> studentList = new Dictionary<string, Student>();
        public static Dictionary<string, Student> StudentList { get { return studentList; } }

        public static void GetRootMaps(string json) {
            var info = JsonConvert.DeserializeAnonymousType(json, new {
                cell = "", tool = "",
                builder = new {
                    root = "",
                    compiler = new { exec = "", incs = new List<string>() },
                    linker = new { exec = "", libs = new List<string>() },
                }
            });
            cellPath = new DirectoryInfo(info.cell);
            toolPath = new DirectoryInfo(info.tool);
            compilerPath = new DirectoryInfo(info.compiler);
            linkerPath = new DirectoryInfo(info.linker);
        }

        public static void GetNameList(string[] records) {
            foreach (var record in records) {
                var tokens = record.Split(',');
                try {
                    string id = tokens[0];
                    studentList.Add(id, new Student() {
                        Id = id,
                        Name = tokens[1],
                        Password = tokens.Length > 2 ? tokens[2] : string.Empty
                    });
                } catch (Exception e) {
                    Console.WriteLine(e);
                }
            }
        }

        static ConfigInfo() {
            GetRootMaps(File.ReadAllText("."));

            var nameList = Path.Combine(cellPath.FullName, @"namelist.nl");
            GetNameList(File.ReadAllLines(nameList));
        }
    }
}
