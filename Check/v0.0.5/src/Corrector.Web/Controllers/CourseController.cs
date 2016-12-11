using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using System.IO;

// For more information on enabling MVC for empty projects, visit http://go.microsoft.com/fwlink/?LinkID=397860

namespace Corrector.Web.Controllers
{
    public class CourseController : Controller
    {
        // GET: /<controller>/
        public IActionResult Index()
        {
            var cellRoot = new DirectoryInfo(@"E:\Coding\Projects\Check\Root\Container\2016\1140209287\第1次课后练习");
            ViewBag.Title = cellRoot.Name;
            ViewBag.Path = cellRoot;
            return View();
        }
    }
}
