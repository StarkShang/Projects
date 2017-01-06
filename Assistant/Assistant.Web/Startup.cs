using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;

namespace Assistant.Web
{
    public class Startup
    {
        // This method gets called by the runtime. Use this method to add services to the container.
        // For more information on how to configure your application, visit http://go.microsoft.com/fwlink/?LinkID=398940
        public void ConfigureServices(IServiceCollection services)
        {
            services.AddMvc();
            services.AddSession();
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IHostingEnvironment env, ILoggerFactory loggerFactory)
        {
            app.UseStatusCodePages();
            app.UseStaticFiles();
            app.UseSession();
            app.UseMvc(routes => {
                routes.MapRoute("default", "{controller=course}/{action=SignIn}");
                routes.MapRoute(
                    name: "train",
                    template: "train",
                    defaults: new { controller = "course", action = "train"});
                routes.MapRoute(
                    name: "signin",
                    template: "SignIn/{action}",
                    defaults: new { controller = "course", action = "signin" });
                routes.MapRoute(
                    name: "signup", 
                    template: "SignUp/{action}", 
                    defaults: new { controller = "course", action = "signup" });
            });
        }
    }
}
