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
            Loader.Init(json);

            Assert.AreEqual(Container.ContainerRoot.Name, "cell");
            Assert.AreEqual(Builder.CompilerExec.Name, "tool");
            Assert.AreEqual(Builder.LinkerExec.Name, "builder.exe");
            Assert.AreEqual(Tester.TestRoot.Name, "link.exe");
        }
    }
}
