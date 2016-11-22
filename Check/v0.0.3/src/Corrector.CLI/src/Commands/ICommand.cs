using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Corrector.CLI.Commands
{
    interface ICommand
    {
        void Run(string parameters);
        Dictionary<string, List<string>> Parse(string parameters);
    }
}
