using Corrector.Core;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Corrector.Test
{
    [TestClass]
    public class ConfigInfoTest
    {
        [TestMethod]
        public void GetRootMapsTest()
        {
            var json = @"{  'cell': 'cell',
                            'tool': 'tool',
                            'compiler': 'builder.exe',
                            'linker': 'link.exe' }";
            ConfigInfo.GetRootMaps(json);

            Assert.AreEqual(ConfigInfo.CellPath, "cell");
            Assert.AreEqual(ConfigInfo.ToolPath, "tool");
            Assert.AreEqual(ConfigInfo.CompilerPath, "builder.exe");
            Assert.AreEqual(ConfigInfo.LinkerPath, "link.exe");
        }
    }
}
