using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace Corrector.Core.Global
{
    public static class DirectoryHelper
    {
        public static void Traverse(DirectoryInfo directory,Action<DirectoryInfo> action, int depth = int.MaxValue)
        {
            if (depth == 0)  return;
            if (directory.GetDirectories() == null) return;
            action(directory); depth--;
            Parallel.ForEach(directory.GetDirectories(), dir => Traverse(dir, action, depth));
        }
    }
}
