using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Reflection;
using ver_0_0_2.Commands;

namespace ver_0_0_2
{
    static class CommandDispatcher
    {
        static public void Run(string instruction)
        {
            var tmp = instruction.Split(' ');
            var ns = MethodBase.GetCurrentMethod().DeclaringType.Namespace;
            var cmd = ns + ".Commands." + Thread.CurrentThread.CurrentCulture.TextInfo.ToTitleCase(tmp[0]);
            var type = Type.GetType(cmd);
            var asm = Assembly.GetAssembly(type);
            var obj = asm.CreateInstance(cmd);
            var method = type.GetMethod("Run");
            var asd = tmp.Skip(1).ToArray();
            method.Invoke(obj, asd);
        }
    }
}
