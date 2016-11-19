using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Corrector.CLI.Global;

namespace Corrector.CLI.Commands
{
    class CommandRollCall : ICommand
    {
        public Dictionary<string, List<string>> Parse(string parameters)
        {
            throw new NotImplementedException();
        }

        public void Run(string parameters)
        {
            var ids = from dir in new DirectoryInfo(parameters).GetDirectories()
                      select dir.Name;
            var keys = ConfigInfo.NameList.Keys.ToArray();
            keys.Except(ids);
        }
    }
}
