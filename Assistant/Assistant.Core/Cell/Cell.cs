using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace Assistant.Core
{
    public class Cell
    {
        static public string RootPath { get; set; }
        public string CellPath { get; }
        public SortedList<int, string> Projects { get; } = new SortedList<int, string>();

        public SortedList<int, string> GetProjects(DateTime date, Dictionary<DateTime, string> schedule)
        {
            var paths = from plan in schedule
                           where plan.Key < date
                           orderby plan.Key ascending
                           select Path.Combine(CellPath, plan.Value);
            int index = 0;
            foreach (var p in paths) { Projects.Add(index++, p); }
            return Projects;
        }

        public string GetLastProject()
        {
            return Projects.Last().Value;
        }

        public Cell(string stuId)
        {
            CellPath = Path.Combine(RootPath, stuId);
        }
    }
}
