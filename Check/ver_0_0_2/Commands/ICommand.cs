using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ver_0_0_2.Commands
{
    interface ICommand
    {
        void Run(string parameters);
        Dictionary<string, List<string>> Parse(string parameters);
    }
}
