using System.Collections.Generic;
using System.IO;
using Corrector.CLI.Global;
using Corrector.Core;

namespace Corrector.CLI.Commands
{
    class CommandCell : ICommand
    {
        public Dictionary<string, List<string>> Parse(string parameters) {
            return CommandHelper.Parse(parameters, option => {
                switch (option) {
                    case "-d": return 1;
                    case "-i": return 0;
                    case "-r": return 1;
                    case "-s": return 1;
                    case "-t": return 2;
                    default:
                        return 0;
                }
            });
        }

        public void Run(string parameters) {
            var options = Parse(parameters);
            foreach (var item in options) {
                switch (item.Key) {
                    case "-d": Cell.Dispatch(options["-d"][0]); break;
                    case "-i": Cell.InitCells(); break;
                    case "-r": Cell.Remove(options["-r"][0]); break;
                    case "-s": Cell.Show(options["-s"][0]); break;
                    case "-t": Cell.Tidy(options["-t"][0], options["-t"][1]); break;
                    default: break;
                }
            }
        }
    }
}
