using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Reflection;
using Corrector.CLI.Commands;
using System.Text.RegularExpressions;

namespace Corrector.CLI.Commands
{
    static class CommandHelper
    {
        static public void Run(string command, string parameters)
        {
            var classname = "Corrector.CLI.Commands.Command" + command;
            try {
                var asm = Assembly.GetEntryAssembly();
                var cmd = asm.CreateInstance(classname, true) as ICommand;
                cmd.Run(parameters);
            } catch (Exception e) {
                Console.WriteLine(e.Data);
            }  
        }

        static public Dictionary<string, List<string>> Parse(string parameters, Func<string, int> func)
        {
            LinkedList<string> tokens = new LinkedList<string>(parameters.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
            var table = new Dictionary<string, List<string>>();
            // 遍历数组
            // 找到命令选项以及选项参数
            var iterator = tokens.First;
            while (iterator != null) {
                if (iterator.Value.StartsWith("-")) {
                    var key = iterator.Value;
                    if (!table.ContainsKey(key)) table[key] = new List<string>();
                    var prev = iterator; iterator = iterator.Next; tokens.Remove(prev);
                    for (var num = func(key); num-- > 0;
                         prev = iterator, iterator = iterator.Next, tokens.Remove(prev)) {
                        if (iterator == null) {
                            Console.WriteLine("Not enough parameters!");
                            return null;
                        } else {
                            table[key].Add(iterator.Value);
                        }
                    }

                } else {
                    iterator = iterator.Next;
                }
            }
            // 剩下的作为命令本身的参数
            // 在table中存在Key:param对应的List里面
            iterator = tokens.First;
            while (iterator != null) {
                if (!table.ContainsKey("param")) table["param"] = new List<string>();
                table["param"].Add(iterator.Value);
                iterator = iterator.Next;
            }
            return table;
        }
    }
}
