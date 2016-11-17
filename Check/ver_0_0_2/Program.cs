using System;
using System.Text;

namespace ver_0_0_2
{
    class Program
    {
        static void Main(string[] args)
        {
            const string prompt = "Stark.Shang> ";
            StringBuilder cmd = new StringBuilder();
            while (cmd.ToString() != "exit")
            {
                Console.Write(prompt);
                cmd.Clear().Append(Console.ReadLine());
                CommandDispatcher.Run(cmd.ToString());
            }
        }
    }
}
