using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ver_0_0_2.Commands
{
    class Clear : ICommand
    {
        public void Run(string[] parameters)
        {
            Console.Clear();
        }
    }
}
