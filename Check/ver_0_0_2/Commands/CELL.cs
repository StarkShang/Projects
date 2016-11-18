using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using ver_0_0_2.Global;

namespace ver_0_0_2.Commands
{
    class CELL : ICommand
    {
        public Dictionary<string, List<string>> Parse(string parameters)
        {
            //var builder = new StringBuilder(parameters);
            //var table = new Dictionary<string, List<string>>();
            //var match = Regex.Match(parameters, @"-[a-zA-Z]+");
            //while (match.Success)
            //{
            //    table[match.Value] = table.ContainsKey(match.Value) ? table[match.Value] : new List<string>();
            //    var cursor = parameters.IndexOf(match.Value) + match.Value.Length + 1;
            //    builder.Replace(match.Value, "");
            //    switch (match.Value) {
            //        default:
            //            break;
            //    }
            //    match = match.NextMatch();
            //}
            //table["root"] = new List<string>() { builder.ToString().Trim() };
            //return table;
            return CommandHelper.Parse(parameters, (option, container, index) => {
                switch (option)
                {
                    default:
                        break;
                }
            });

        }

        public void Run(string parameters)
        {
            var options = Parse(parameters);
            foreach (var item in options)
            {
                switch (item.Key)
                {
                    case "-c": create(options["root"][0]); break;
                    default:
                        break;
                }
            }
        }

        private void create(string dir)
        {
            foreach (var id in ConfigInfo.NameList.Keys)
            {
                Directory.CreateDirectory(Path.Combine(dir, id));
            }
        }
    }
}
