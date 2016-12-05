using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Corrector.Core
{
    public class User
    {
        private static Dictionary<string, Student> studentList = new Dictionary<string, Student>();
        public static Dictionary<string, Student> StudentList { get { return studentList; } }

        public struct Student
        {
            public string Id { get; set; }
            public string Name { get; set; }
            public string Password { get; set; }
        }
    }
}
