using Corrector.CLI.Commands;
using Corrector.Core;

namespace Corrector.CLI.src.Commands
{
    public class CommandTest : ICommand
    {
        public CommandTest() {
            ClassType = typeof(Manager);
            CommandDic.Add("-m", new CommandParam() { Cmd = "CorrectMFC", Param = new string[1], IsCalled = false });
            CommandDic.Add("-g", new CommandParam() { Cmd = "Correct", Param = new string[1], IsCalled = false });
        }
    }
}
