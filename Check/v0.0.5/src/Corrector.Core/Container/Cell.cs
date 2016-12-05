using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public class Cell
    {
        private Tester tester;
        private Builder builder;
        private Cleaner cleaner;
        private Recorder recorder;
        private DirectoryInfo cellRoot;

        public DirectoryInfo[] GetProjects()
        {
            return cellRoot.GetDirectories();
        }


        public Cell(DirectoryInfo cellRoot)
        {
            this.cellRoot = cellRoot;
        }
    }
}
