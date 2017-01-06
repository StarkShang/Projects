using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assistant.Core.Test.GlobalTest
{
    [TestClass]
    public class ConfiguratorTest
    {
        [TestMethod]
        public void TestInit()
        {
            Configurator.Init("{\"cellRoot\":\"C:\",\"toolRoot\":\"D:\"}");
            Assert.AreEqual(Cell.RootPath, "C:");
            Assert.AreEqual(Tool.RootPath, "D:");
        }
    }
}
