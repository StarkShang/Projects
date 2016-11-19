using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Newtonsoft.Json;
using System.Data;
using System.Threading;

namespace ver_0_0_1
{
    class Program
    {
        static string workspace = @"..\作业情况\20161104";
        static IEnumerable<string> roster = File.ReadLines(@"..\Config\roster");
        static Dictionary<string, Action<TreeNode>> Command = new Dictionary<string, Action<TreeNode>>() {
            { "1", check },
            { "2", show  },
            { "3", wholecode },
            { "4", test }
        };

        [STAThread]
        static void Main(string[] args)
        {
            var dir = new DirectoryInfo(@"C:\Users\stark\Downloads\C++\20161104\上交作业");
            
            var root = TreeNode.CreateTree(dir);
            var tmp = root.GetNodeWithId("L01");
            string cmd = null;
            do {
                Console.Clear();
                showTip();
                cmd = Console.ReadLine().ToLower();
                if (Command.Keys.Contains(cmd))
                {
                    Console.WriteLine();
                    Command[cmd](root);
                }
            } while (cmd != "quit" && cmd != "q");
            Console.WriteLine("Quit the program!");
            //var newRoot = root.ExtractSubTree("L05");
            //Console.WriteLine(newRoot.ShowTree());
        }
        static void showTip() {
            Console.WriteLine("********************");
            Console.WriteLine("** 请选择所需功能 **");
            Console.WriteLine("** 1 点名         **");
            Console.WriteLine("** 2 显示文件地图 **");
            Console.WriteLine("** 3 生成完整代码 **");
            Console.WriteLine("** 4 测试代码     **");
            Console.WriteLine("********************");
            Console.WriteLine();
        }

        static void check(TreeNode root) {
            var query = from node in root.GetLayer(1)
                        select string.Join(",", node.Content.Name.Split('_').Skip(1));
            var absentList = string.Join("\r\n", roster.Except(query));
            File.WriteAllText(Path.Combine(workspace, "absentlist.txt"), absentList);
            Console.WriteLine(absentList);
            Console.ReadKey();
        }

        static void show(TreeNode root) {
            var str = root.ShowTree();
            File.WriteAllText(Path.Combine(workspace, "filemap.txt"), str);
            Console.WriteLine(str);
            Console.ReadKey();
        }

        static void wholecode(TreeNode root) {
            var path = Path.Combine(workspace, "codes");
            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            foreach (var child in root.Children)
            {
                StringBuilder builder = new StringBuilder();
                child.Traverse(node => {
                    builder.AppendLine(node.Content.Name);
                    if (File.Exists(node.Content.FullName))
                    {
                        builder.AppendLine(File.ReadAllText(node.Content.FullName));
                    }
                });
                File.WriteAllText(Path.Combine(path, child.Content.Name + ".txt"), builder.ToString());
            }
            Console.WriteLine("Ok!");
            Console.ReadKey();
        }

        class Data {
            public List<string> input = new List<string>();
            public List<string> output = new List<string>();
        }
        static void test(TreeNode root) {
            var outPath = Path.Combine(workspace, @"score.txt");
            File.Create(outPath).Close();
            DirectoryInfo path = new DirectoryInfo(@"..\Config\Template\第四次上机");
            
            foreach (var child in root.Children) {
                StringBuilder builder = new StringBuilder();
                builder.AppendLine(child.Content.Name);
                foreach (var dir in path.GetDirectories()) {
                    if (dir.Name == "L01" || dir.Name == "L02" || dir.Name == "L03") {
                        builder.AppendLine(dir.Name);
                        var list = child.GetNodeWithId(dir.Name);
                        list[0].Traverse(n => {
                            var match = Regex.Match(n.Content.Name, @"func\w*.cpp");
                            if (match.Success) {
                                list.Add(n);
                            }
                        });

                        if (File.Exists(@"..\Config\tmp.hpp")) {
                            File.Delete(@"..\Config\tmp.hpp");
                        }
                        if (File.Exists(@"..\Config\test.cpp")) {
                            File.Delete(@"..\Config\test.cpp");
                        }
                        if (File.Exists(@"..\Config\main.exe")) {
                            bool canDelete = false;
                            while (!canDelete) {
                                try {
                                    canDelete = true;
                                    File.Delete(@"..\Config\main.exe");
                                }
                                catch (Exception) {
                                    canDelete = false;
                                }
                            }
                        }

                        var node = list.Last();
                        string str = null;
                        if (File.Exists(node.Content.FullName))
                        {
                            str = File.ReadAllText(node.Content.FullName);
                            var match = Regex.Match(str, @"\bfunc\w+\b");
                            if (match.Success)
                            {
                                str = str.Replace(match.Value, "func");
                            }
                        }
                        File.WriteAllText(@"..\Config\tmp.hpp", str);
                        File.Copy(Path.Combine(dir.FullName, @"test.cpp"), @"..\Config\test.cpp", true);
                        Stack<Data> data = JsonConvert.DeserializeObject<Stack<Data>>(File.ReadAllText(Path.Combine(dir.FullName, @"data.json")));
                        /* 运行测试脚本 */
                        compile();
                        test(builder, data);
                        
                    }
                }
                string content = builder.AppendLine("\r\n").ToString();
                Console.WriteLine(content);
                File.AppendAllText(outPath, content);
            }
            if (File.Exists(@"..\Config\tmp.hpp")) {
                File.Delete(@"..\Config\tmp.hpp");
            }
            if (File.Exists(@"..\Config\test.cpp")) {
                File.Delete(@"..\Config\test.cpp");
            }
            if (File.Exists(@"..\Config\main.exe")) {
                File.Delete(@"..\Config\main.exe");
            }
        }
        static void compile() {
            Process process = new Process();
            process.StartInfo.FileName = @"..\Config\compile.bat";
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.CreateNoWindow = true;
            process.Start();
            process.WaitForExit();
            process.Close();
        }
        static void test(StringBuilder builder, Stack<Data> data) {
            if (!File.Exists(@"..\Config\main.exe"))
            {
                builder.AppendLine("Cannot build!");
                return;
            }
            bool flag = false;
            Process process = new Process();
            process.StartInfo.FileName = @"..\Config\main.exe";
            process.StartInfo.Arguments = data.Count.ToString();
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.RedirectStandardError = true;
            process.StartInfo.CreateNoWindow = true;
            process.OutputDataReceived += (object sender, DataReceivedEventArgs e) =>
            {
                var s = e.Data??"";
                if (s.StartsWith("[in]")) {
                    if (data.Count != 0) {
                        var d = data.Pop();
                        var str = string.Join(" ", d.input) + " " + string.Join(" ", d.output);
                        process.StandardInput.WriteLine(str);
                    }
                }
                else if (s.StartsWith("[out]")) {
                    builder.AppendLine(s.Substring(6));
                }
                else if (s.StartsWith("[summary]"))
                {
                    flag = true;
                    builder.AppendLine(s.Substring(10));
                }
            };
            process.Exited += (object sender, EventArgs e) =>
            {
                process.Dispose();
                process.Close();
                return;
            };
            process.Disposed += (object sender, EventArgs e) => { return; };
            process.Start();
            process.BeginOutputReadLine();
            process.BeginErrorReadLine();
            process.WaitForExit(5000);
            var time = DateTime.Now - process.StartTime;
            if (time.TotalMilliseconds > 5000) { builder.AppendLine("Time out!"); }
            if (!flag) { builder.AppendLine("Program crash!"); }
            process.Close();
            bool notOver = false;
            for (int i = 0; i < 5; i++) {
                notOver = false;
                var p_arry = Process.GetProcesses();
                foreach (var p in p_arry) {
                    if (p.ProcessName.ToLower() == "main") {
                        notOver = true;
                    }
                }
                if (notOver) {
                    Thread.Sleep(2000);
                    continue;
                }
                else {
                    break;
                }
            }
            if (notOver)
            {
                process.Close();
            }
        }
    }
}
