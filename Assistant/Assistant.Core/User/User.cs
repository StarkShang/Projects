using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Driver;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assistant.Core
{
    
    public class User
    {
        /* 账户登录 */
        public static bool SignIn(User user)
        {
            var query = DBHelper.QueryUser(user);
            if (query.Count < 1) return false;
            return query[0].Password == user.Password;
        }
        /* 注册账户 */
        public static bool SignUp(User user) {
            return DBHelper.InsertUser(user);
        }
        /* 注销账户 */
        public static bool Delete(User user)
        {
            return DBHelper.DeleteUser(user);
        }
        /* 修改账户 */
        public static bool Update(User user)
        {
            return DBHelper.UpdateUser(user);
        }
        /* 查询账户 */
        public static List<User> Query(User user)
        {
            return DBHelper.QueryUser(user);
        }

        [BsonId]
        public string UserId { get; set; }
        public string UserName { get; set; }
        public string Password { get; set; }
        public string UserMail { get; set; }

        public override bool Equals(object user)
        {
            base.Equals(user);
            var usr = user as User;
            return (UserId == usr.UserId) &&
                (UserName == usr.UserName) &&
                (Password == usr.Password) &&
                (UserMail == usr.UserMail);
        }
        public override int GetHashCode()
        {
            return UserId.GetHashCode() +
                UserName.GetHashCode() +
                Password.GetHashCode() +
                UserMail.GetHashCode();
        }
    }
}
