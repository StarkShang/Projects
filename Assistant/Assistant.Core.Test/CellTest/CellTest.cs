using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
namespace Assistant.Core.Test.CellTest
{
    [TestClass]
    public class CellTest
    {
        Cell cell;
        Dictionary<DateTime, string> schedule = new Dictionary<DateTime, string>() {
                { new DateTime(2016,12,1), "proj01" },
                { new DateTime(2016,12,27), "proj02" },
                { new DateTime(2017,1,18), "proj03" },
                { new DateTime(2017,1,28), "proj04" }
            };
        public CellTest()
        {
            Cell.RootPath = @"C:\";
            cell = new Cell("1140209287");
        }

        [TestMethod]
        public void TestConstruct()
        {
            Assert.AreEqual(cell.CellPath, @"C:\1140209287");
        }

        [TestMethod]
        public void TestGetProjects()
        {
            var date = new DateTime(2017, 1, 1);
            var projects = cell.GetProjects(date, schedule);
            CollectionAssert.AreEqual(projects, new SortedList<int, string> {
                { 0, @"C:\1140209287\proj01" },
                { 1, @"C:\1140209287\proj02" }
            });
        }

        [TestMethod]
        public void TestGetLastProject()
        {
            var date = new DateTime(2017, 1, 1);
            var projects = cell.GetProjects(date, schedule);
            var lastProject = cell.GetLastProject();
            Assert.AreEqual(lastProject, @"C:\1140209287\proj02");
        }
    }
}
