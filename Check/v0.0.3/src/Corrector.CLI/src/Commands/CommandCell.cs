using System.Collections.Generic;
using System.IO;
using Corrector.CLI.Global;
using Corrector.Core;
using System.Reflection;
using System;

namespace Corrector.CLI.Commands
{
    class CommandCell : ICommand
    {
        public CommandCell() {
            ClassType = typeof(Manager);
            CommandDic.Add("-s", new CommandParam() { Cmd = "Show", Param = new string[1], IsCalled = false });
            CommandDic.Add("default", new CommandParam() { IsCalled = false });
        }
    }
}
