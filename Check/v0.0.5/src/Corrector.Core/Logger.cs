using System.IO;
using System.Text;

namespace Corrector.Core
{
    public class Logger
    {
        public string Root { get; set; }
        public string Label { get; set; }
        private StringBuilder builder = new StringBuilder();

        public void Log(string content) {
            builder.AppendLine($"{Root}\\{Label} : {content}");
        }

        public void WriteFile(string filePath) {
            File.WriteAllText(path: filePath, contents: builder.ToString());
        }

        public Logger(string root) {
            Root = root;
        }
    }
}
