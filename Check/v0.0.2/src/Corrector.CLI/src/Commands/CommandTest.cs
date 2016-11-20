using Corrector.Core;
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
            return CommandHelper.Parse(parameters, option => {
                switch (option) {
                    default:
                        return 0;
                }
            });
        }

        public void Run(string parameters)
        {
            var options = Parse(parameters);
            foreach (var item in options) {
                switch (item.Key) {
                    default: RedPen.Test(options["param"][0]); break;
                }
            }
        }
    }
}
