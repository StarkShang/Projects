using Corrector.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Corrector.CLI.Commands
{
    public class CommandClean : ICommand
    {
        public CommandClean()
        {
            ClassType = typeof(Cleaner);
            CommandDic.Add("-d", new CommandParam() { Cmd = "DeleteFiles", Param = new string[3], IsCalled = false });
            CommandDic.Add("default", new CommandParam() { IsCalled = false });
        }
    }
}
