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
                    case "-i": return 0;
                    case "-s": return 1;
                    case "-d": return 1;
                    case "-r": return 1;
                    default:
                        return 0;
                }
            });
        }

        public void Run(string parameters) {
            var options = Parse(parameters);
            foreach (var item in options) {
                switch (item.Key) {
                    case "-i": Cell.InitCells(); break;
                    case "-s": Cell.Show(options["-s"][0]); break;
                    case "-d": Cell.Dispatch(options["-d"][0]); break;
                    case "-r": Cell.Remove(options["-r"][0]); break;
                    default: break;
                }
            }
        }
    }
}
