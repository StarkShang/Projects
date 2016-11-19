using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ver_0_0_1
{
    class TreeNode
    {
        public FileSystemInfo Content { get; }
        private TreeNode parent;
        public TreeNode Parent { get { return parent; } }
        private List<TreeNode> children;
        public List<TreeNode> Children { get { return children; } }

        private TreeNode(FileSystemInfo content)
        {
            Content = content;
        }

        public void AddChild(TreeNode node)
        {
            if (children == null)
            {
                children = new List<TreeNode>();
            }
            node.parent = this;
            children.Add(node);
        }
        static public TreeNode CreateTree(DirectoryInfo directory)
        {
            TreeNode root = new TreeNode(directory);
            foreach (var file in directory.GetFiles())
            {
                root.AddChild(new TreeNode(file));
            }
            foreach (var dir in directory.GetDirectories())
            {
                root.AddChild(CreateTree(dir));
            }
            return root;
        }

        public void Traverse(Action<TreeNode> func) {
            func(this);
            if (children != null) {
                foreach (var child in children) {
                    child.Traverse(func);
                }
            }
        }

        public TreeNode ExtractSubTree(string id) {
            var path = Directory.CreateDirectory(Path.Combine((Content as DirectoryInfo).Parent.FullName, id));
            foreach (var child in children) {
                foreach (var item in child.children) {
                    if (item.Content.Name == id) {
                        Directory.Move(item.Content.FullName, Path.Combine(path.FullName, child.Content.Name));
                    }
                }
            }
            return CreateTree(new DirectoryInfo(path.FullName));
        }

        public List<TreeNode> GetLayer(int depth) {
            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(this);
            while (depth-- != 0)
            {
                int num = queue.Count;
                if (num == 0) { break; }
                for (int i = 0; i < num; i++) {
                    var node = queue.Dequeue();
                    foreach (var child in node.children) {
                        queue.Enqueue(child);
                    }
                }
            }
            return queue.ToList();
        }
        public List<TreeNode> GetNodeWithId(string id) {
            List<TreeNode> list = new List<TreeNode>();
            Traverse(node => {
                if (node.Content.Name == id) {
                    list.Add(node);
                }
            });
            return list;
        }
        public void showTree(TreeNode node, StringBuilder builder, int depth, bool isLast, string apart) {
            builder.Append(apart);
            builder.Append(isLast ? "\x2514" : "\x251C");
            builder.Append('\x2500');
            builder.Append(node.children == null || depth <= 0 ? "\x2500" : "\x252C");
            builder.AppendLine(node.Content.Name);

            if (node.children != null && depth > 0) {
                for (int i = 0; i < node.children.Count - 1; i++) {
                    showTree(node.children[i], builder, depth-1, false, apart + (isLast ? "  " : "\x2502 "));
                } {
                    showTree(node.children.Last(), builder, depth-1, true, apart + (isLast ? "  " : "\x2502 "));
                }
            }
        }
        public string ShowTree(int depth)
        {
            StringBuilder builder = new StringBuilder();
            builder.Append(children == null ? "\x2500" : "\x250C");
            builder.AppendLine(Content.Name);
            if (depth == 0)
            {
                return builder.ToString();
            }
            for (int i = 0; i < children.Count - 1; i++)
            {
                showTree(children[i], builder, depth-1, false, "");
            }
            {
                showTree(children.Last(), builder, depth-1, true, "");
            }

            return builder.ToString();
        }
        public string ShowTree() {
            return ShowTree(int.MaxValue);
        }
    }
}
