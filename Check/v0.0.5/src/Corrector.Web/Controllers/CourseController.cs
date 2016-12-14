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
            var ViewModel = new Dictionary<string, Dictionary<string, string>>();
            foreach (var project in cellRoot.GetDirectories()) {
                var dic = new Dictionary<string, string>();
                foreach (var file in project.GetFiles()) {
                    dic.Add(file.Name, System.IO.File.ReadAllText(file.FullName));
                }
                ViewModel.Add(project.Name, dic);
            }

            ViewBag.ViewModel = ViewModel;
            ViewBag.Title = cellRoot.Name;
            ViewBag.Path = cellRoot;
            return View(ViewModel);
        }
    }
}
