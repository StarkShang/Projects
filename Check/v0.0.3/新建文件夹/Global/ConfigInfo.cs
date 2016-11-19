using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ver_0_0_2.Global
{
    static class ConfigInfo
    {
        static public Dictionary<string, string> NameList = new Dictionary<string, string>();

        static ConfigInfo() {
            GetNameList(@"..\works\"+DateTime.Now.Year.ToString() + @"\namelist.nl");
        }

        private static void GetNameList(string path)
        {
            var query = from line in File.ReadLines(path)
                        select line.Split(',');

            foreach (var pair in query) {
                NameList.Add(pair[0], pair[1]);
            }
        }
    }
}
