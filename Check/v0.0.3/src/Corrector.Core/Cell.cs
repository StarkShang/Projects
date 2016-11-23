using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public struct Result {
        public bool State { get; set; }
        public string Info { get; set; }
    }

    public class Cell
    {
        private DirectoryInfo Root = null;
        private Compiler compiler = new Compiler();
        private RedPen redPen = new RedPen();
        private const string recordFileName = @"record.txt";

        /// <summary>
        /// 测试非 MFC 项目
        /// </summary>
        /// <param name="label">测试 Cell 标签</param>
        public async void Correct(string label) {
            var workDirectory = new DirectoryInfo($"{Root.FullName}\\{label}");
            var logger = new Logger(Root.Name);
            if (!workDirectory.Exists) {
                workDirectory.Create();
                logger.Log(@"Cannot find the directory!");
                goto RECORD;
            }
            foreach (var dir in workDirectory.GetDirectories()) {
                if (dir.FullName.EndsWith(@"MFC")) continue;
                // 1. 编译
                var compileResult = await compiler.Build(dir);
                if (compileResult.ExecFile == null) {
                    logger.Log(compileResult.Info); continue;
                };
                // 2. 执行测试
                redPen.Correct(compileResult.ExecFile, logger);
            }
        RECORD:
            logger.WriteFile($"{workDirectory.FullName}\\{recordFileName}");
        }

        /// <summary>
        /// 测试 MFC 项目
        /// </summary>
        /// <param name="label">测试 Cell 标签</param>
        /// <returns></returns>
        public async Task<Result> CorrectMFC(string label) {
            // 1. 编译
            var compileResult = await compiler.BuildMFC(new DirectoryInfo($"{Root.FullName}\\{label}\\MFC"));
            // 2. 执行测试
            if (compileResult.ExecFile == null) return new Result() {
                State = false,
                Info = compileResult.Info
            };
            redPen.CorrectMFC(compileResult.ExecFile);
            return new Result() {
                State = true,
                Info = "Success!"
            };
        }

        

        public Cell(string id)
        {
            if (ConfigInfo.RootMaps.ContainsKey("cells")) {
                Root = new DirectoryInfo($"{ConfigInfo.RootMaps["cells"]}\\{id}");
            }
        }
    }
}
