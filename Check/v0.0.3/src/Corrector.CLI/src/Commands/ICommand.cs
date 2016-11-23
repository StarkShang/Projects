using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Corrector.CLI.Commands
{
    public class CommandParam
    {
        public string Cmd;
        public string[] Param;
        public bool IsCalled = false; 
    }
    public class ICommand
    {
        protected Dictionary<string, CommandParam> CommandDic = new Dictionary<string, CommandParam>();
        protected Type ClassType = null;
        public void Run(string parameters) {
            CommandHelper.Parse(parameters, CommandDic);
            foreach (var item in CommandDic) {
                var command = item.Value;
                if (command.IsCalled) {
                    ClassType.GetMethod(command.Cmd).Invoke(null, command.Param);
                }
            }
        }
    }
}
