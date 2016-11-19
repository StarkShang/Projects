using System.Collections.Generic;
using System.IO;
using Corrector.CLI.Global;
using Corrector.Core;

namespace Corrector.CLI.Commands
{
    class CommandCell : ICommand
    {
        public Dictionary<string, List<string>> Parse(string parameters)
        {
            return CommandHelper.Parse(parameters, option => {
                switch (option)
                {
                    case "-c": return 2;
                    default:
                        return 0;
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
                    case "-c": create(options["param"][0]); break;
                    case "-d": Cell.Show(); break;
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
