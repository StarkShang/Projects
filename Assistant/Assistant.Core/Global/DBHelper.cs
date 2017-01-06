using MongoDB.Bson;
using MongoDB.Driver;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assistant.Core
{
    public static class DBHelper
    {
        public static IMongoDatabase Database { get; set; }
        public static IMongoCollection<User> UserCollection { get; set; }
        
        /* 增加数据 */
        public static bool InsertUser(User user) {
            // 检查数据是否存在
            // 若存在该条数据, 则返回false
            if (QueryUser(user).Count > 0) return false;
            // 插入数据
            UserCollection.InsertOne(user);
            // 验证是否插入成功
            var query = QueryUser(user);
            return (query.Count == 1) && (query[0].Equals(user));
        }
        
        /* 删除数据 */
        public static bool DeleteUser(User user)
        {
            // 检查数据是否存在
            // 若不存在该条数据, 则返回false
            if (QueryUser(user).Count < 1) return false;
            // 删除数据
            var filter = Builders<User>.Filter.Eq(ob => ob.UserId, user.UserId);
            UserCollection.DeleteOne(filter);
            // 验证是否插入成功
            return QueryUser(user).Count == 0 ? true : false;
        }

        /* 更改数据 */
        public static bool UpdateUser(User user)
        {
            var filter = Builders<User>.Filter.Eq(ob => ob.UserId, user.UserId);
            var update = Builders<User>.Update
                .Set(ob => ob.UserName, user.UserName)
                .Set(ob => ob.Password, user.Password)
                .Set(ob => ob.UserMail, user.UserMail);
            var result = UserCollection.UpdateOne(filter, update);
            /* 验证结果 */
            var query = QueryUser(user);
            return (query.Count == 1) && (query[0].Equals(user));
        }

        /* 查询数据 */
        public static List<User> QueryUser(User user)
        {
            var filter = Builders<User>.Filter.Eq(ob => ob.UserId, user.UserId);
            return UserCollection.Find(filter).ToList();
        }

        static DBHelper()
        {
            Database = new MongoClient().GetDatabase("assistant");
            UserCollection = Database.GetCollection<User>("user");
        }
    }
}
