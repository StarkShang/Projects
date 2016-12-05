using System.IO;
using System.Text;

namespace Corrector.Core
{
    public class Recorder
    {
        private string label;
        private StringBuilder builder = new StringBuilder();

        public void Log(string content) {
            builder.AppendLine($"{label} : {content}");
        }

        public void WriteFile(string filePath) {
            File.WriteAllText(path: filePath, contents: builder.ToString());
        }

        public Recorder(string label) {
            this.label = label;
        }
    }
}
