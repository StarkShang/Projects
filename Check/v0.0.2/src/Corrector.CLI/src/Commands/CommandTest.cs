using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Corrector.CLI.Commands
{
    public class CommandTest : ICommand
    {
        public Dictionary<string, List<string>> Parse(string parameters)
        {
            throw new NotImplementedException();
        }

        public void Run(string parameters)
        {
            throw new NotImplementedException();
        }
    }
}
