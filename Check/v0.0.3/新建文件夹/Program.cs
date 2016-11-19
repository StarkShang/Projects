using System;
using System.Linq;
using System.Text;
using ver_0_0_2.Commands;

namespace ver_0_0_2
{
    class Program
    {
        static void Main(string[] args)
        {
            const string prompt = "Stark.Shang> ";
            string instruction = null;
            string cmd = null;
            string par = null;
            while (cmd != "exit") {
                Console.Write(prompt);
                instruction = Console.ReadLine();
                int cursor = instruction.IndexOf(' ');
                cmd = instruction.Substring(0, cursor);
                par = instruction.Substring(cursor).Trim();
                
                if (cmd != null) CommandHelper.Run(cmd, par);
            }
        }
    }
}
