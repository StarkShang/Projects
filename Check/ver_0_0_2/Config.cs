using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ver_0_0_2
{
    static class Config
    {
        static public Dictionary<string, string> NameList;
        static Config()
        {
            NameList = new Dictionary<string, string>() { { "123", "123" } };
        }
    }
}
