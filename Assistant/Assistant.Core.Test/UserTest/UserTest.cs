using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Assistant.Core;

namespace Assistant.Core.Test.UserTest
{
    [TestClass]
    public class UserTest
    {
        [TestMethod]
        public void TestUserDatabaseOperation()
        {
            User user = new User()
            {
                UserId = "1140209287",
                UserName = "stark",
                Password = "12345678",
                UserMail = "example@example.com"
            };
            // 清除测试数据
            User.Delete(user);
            var query = User.Query(user);
            Assert.AreEqual(query.Count, 0);
            // 测试增加数据
            var isSeccuss = User.SignUp(user);
            Assert.AreEqual(isSeccuss, true);
            // 测试查询数据
            query = User.Query(user);
            Assert.AreEqual(query.Count, 1);
            Assert.AreEqual(query[0], user);
            // 测试修改数据
            user.UserName = "shanghai";
            user.Password = "87654321";
            user.UserMail = "test@test.com";
            isSeccuss = User.Update(user);
            Assert.AreEqual(isSeccuss, true);
            query = User.Query(user);
            Assert.AreEqual(query.Count, 1);
            Assert.AreEqual(query[0], user);
            // 测试删除数据
            User.Delete(user);
            query = User.Query(user);
            Assert.AreEqual(query.Count, 0);
        }
    }
}
