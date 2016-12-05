using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Corrector.Core.Global
{
    static public class Schedule
    {
        private struct ScheduleItem
        {
            public DateTime StartTime;
            public DateTime EndTime;
            public string CellLabel;
        }

        private static List<ScheduleItem> schedule = null;

        public static string GetCellLabel() {
            foreach (var item in schedule)
                if (DateTime.Now > item.StartTime && DateTime.Now < item.EndTime)
                    return item.CellLabel;
            return null;
        }

        static Schedule()
        {

        }
    }
}
