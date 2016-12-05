using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Corrector.Core.Global;

namespace Corrector.Core
{
    public class Container
    {
        public static DirectoryInfo ContainerRoot { get; set; }

        public Cell GetCurrentCell() {
            var label = Schedule.GetCellLabel();
            foreach (var directory in ContainerRoot.GetDirectories())
                if (directory.Name == label)
                    return new Cell(directory);
            return null;
        }

        public Cell[] GetAllCells() {
            var cells = from directory in ContainerRoot.GetDirectories()
                        select new Cell(directory);
            return cells.ToArray();
        }
    }
}
