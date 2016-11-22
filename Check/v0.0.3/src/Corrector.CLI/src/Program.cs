using Corrector.CLI.Commands;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Corrector.Core.Global;

namespace Corrector.CLI
{
    public class Program
    {
        public static void Main(string[] args)
        {
            const string prompt = "Stark.Shang> ";
            string instruction = null;
            string cmd = null;
            string par = null;
            while (cmd != "exit")
            {
                Console.Write(prompt);
                instruction = Console.ReadLine();
                int cursor = instruction.IndexOf(' ');
                if (cursor == -1) {
                    cmd = instruction;
                    par = "";
                } else {
                    cmd = instruction.Substring(0, cursor);
                    par = instruction.Substring(cursor).Trim();
                }
                if (cmd != "") CommandHelper.Run(cmd, par);
            }
        }
    }
}
