using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ver_0_0_2.Global;

namespace ver_0_0_2.Commands
{
    class ROLLCALL : ICommand
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
