using MongoDB.Bson;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assistant.Core
{
    public static class Configurator
    {
        public static void Init(string json)
        {
            var document = BsonDocument.Parse(json);
            ConfigCellRoot(document["cellRoot"].AsString);
            ConfigToolRoot(document["toolRoot"].AsString);
        }
        public static void ConfigCellRoot(string cellRoot)
        {
            Cell.RootPath = cellRoot;
        }
        public static void ConfigToolRoot(string toolRoot)
        {
            Tool.RootPath = toolRoot;
        }

    }
}
