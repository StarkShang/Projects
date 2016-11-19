using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Corrector.CLI.Commands
{
    class CommandClear : ICommand
    {
        public Dictionary<string, List<string>> Parse(string parameters) {
            throw new NotImplementedException();
        }

        public void Run(string parameters) {
            Console.Clear();
        }
    }
}
