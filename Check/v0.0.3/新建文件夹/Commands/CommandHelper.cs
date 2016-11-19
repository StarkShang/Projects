using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Reflection;
using ver_0_0_2.Commands;
using System.Text.RegularExpressions;

namespace ver_0_0_2.Commands
{
    static class CommandHelper
    {
        static public void Run(string command, string parameters)
        {
            var ns = MethodBase.GetCurrentMethod().DeclaringType.Namespace;
            var cmd = ns + ".Commands." + command.ToUpper();
            try {
                var type = Type.GetType(cmd);
                if (type != null)
                    (Assembly.GetAssembly(type)
                             .CreateInstance(cmd) as ICommand)
                             .Run(parameters);
            } catch (Exception e) {
                Console.WriteLine(e.Data);
            }  
        }

        static public Dictionary<string, List<string>> Parse(string parameters, Action<string,List<string>, int> action)
        {
            var builder = new StringBuilder(parameters);
            var table = new Dictionary<string, List<string>>();
            var match = Regex.Match(parameters, @"-[a-zA-Z]+");
            while (match.Success)
            {
                builder.Replace(match.Value, "");
                table[match.Value] = table.ContainsKey(match.Value) ? table[match.Value] : new List<string>();
                var cursor = parameters.IndexOf(match.Value) + match.Value.Length + 1;
                action(match.Value, table[match.Value], cursor);
                match = match.NextMatch();
            }
            table["param"] = new List<string>() { builder.ToString().Trim() };
            return table;
        }
    }
}
