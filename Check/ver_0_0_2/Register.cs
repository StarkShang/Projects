using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ver_0_0_2
{
    class Register
    {
        public DirectoryInfo HomeDirectory { get; }
        public Register(string path)
        {
            HomeDirectory = new DirectoryInfo(path);
        }

        public string[] SignIn()
        {
            var ids = from dir in HomeDirectory.GetDirectories()
                      select dir.Name;
            var keys = Config.NameList.Keys;
            return ids.ToArray();
        }
    }
}
