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
        static public void Run(string command, string parameters) {
            var classname = "Corrector.CLI.Commands.Command" + command;
            try {
                var asm = Assembly.GetEntryAssembly();
                var cmd = asm.CreateInstance(classname, true) as ICommand;
                cmd.Run(parameters);
            } catch (Exception e) {
                Console.WriteLine(e.Data);
            }  
        }

        static public void Parse(string parameters, Dictionary<string, CommandParam> table) {
            LinkedList<string> tokens = new LinkedList<string>(parameters.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
            // 遍历数组
            // 找到命令选项以及选项参数
            var iterator = tokens.First;
            while (iterator != null) {
                if (iterator.Value.StartsWith("-")) {
                    var key = iterator.Value;
                    var prev = iterator; iterator = iterator.Next; tokens.Remove(prev);
                    if (!table.ContainsKey(key)) continue;
                    for (var num = 0; num < table[key].Param.Length;
                        prev = iterator, iterator = iterator.Next, tokens.Remove(prev)) {
                        if (iterator == null) {
                            Console.WriteLine("Not enough parameters!"); return;
                        } else {
                            table[key].Param[num++] = iterator.Value;
                        }
                    }
                    table[key].IsCalled = true;
                } else {
                    iterator = iterator.Next;
                }
            }
            // 剩下的作为命令本身的参数
            // 在table中存在Key:param对应的List里面
            iterator = tokens.First;
            var list = new List<string>();
            while (iterator != null) {
                list.Add(iterator.Value);
                iterator = iterator.Next;
            }
            if (table.ContainsKey("default")) table["default"].Param = list.ToArray();
        }
    }
}
