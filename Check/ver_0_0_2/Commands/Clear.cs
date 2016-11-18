using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ver_0_0_2.Commands
{
    class CLEAR : ICommand
    {
        public Dictionary<string, List<string>> Parse(string parameters)
        {
            throw new NotImplementedException();
        }

        public void Run(string parameters)
        {
            Console.Clear();
        }
    }
}
