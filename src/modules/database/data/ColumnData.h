#pragma once

#include <map>
#include <string>
#include <vector>

namespace faker
{

const std::vector<std::string> columnNames = {
    "id",    "title",    "name",     "email",   "username", "first_name", "last_name",      "phone",      "token",
    "group", "category", "password", "comment", "avatar",   "status",     "date_of_birth",  "created_at", "updated_at",
};

const std::vector<std::string> columnTypes = {
    "int",      "varchar",   "text",   "date",    "datetime", "tinyint", "time",     "timestamp",
    "smallint", "mediumint", "bigint", "decimal", "float",    "double",  "real",     "bit",
    "boolean",  "serial",    "blob",   "binary",  "enum",     "set",     "geometry", "point",
};

const std::map<std::string, std::string> columnNameTypeMap = {
    { "id", "int" },
    { "title", "varchar" },
    { "name", "varchar" },
    { "email", "varchar" },
    { "username", "varchar" },
    { "first_name", "varchar" },
    { "last_name", "varchar" },
    { "phone", "varchar" },
    { "token", "varchar" },
    { "group", "varchar" },
    { "category", "varchar" },
    { "password", "varchar" },
    { "comment", "varchar" },
    { "avatar", "blob" },
    { "status", "boolean" },
    { "date_of_birth", "date" },
    { "created_at", "datetime" },
    { "updated_at", "datetime" },
};

enum class DataGeneratorType {
    Integer = 0u,
    PersonTitle = 1u,
    PersonFullName = 2u,
    Email = 3u,
    UserName = 4u,
    PersonFirstName = 5u,
    PersonLastName = 6u,
    PhoneNumber = 7u,
    Token = 8u,
    AlphaNumeric = 9u,
    Crypto = 10u,
    Sentence = 11u,
    Avatar = 12u,
    Boolean = 13u,
    DateTime = 14u,
    DateOfBirth = 15u
};

const std::map<std::string, faker::DataGeneratorType> columnTypeGeneratorMap = {
    { "id", DataGeneratorType::Integer },
    { "title", DataGeneratorType::PersonTitle },
    { "name", DataGeneratorType::PersonFullName },
    { "email", DataGeneratorType::Email },
    { "username", DataGeneratorType::UserName },
    { "first_name", DataGeneratorType::PersonFirstName },
    { "last_name", DataGeneratorType::PersonLastName },
    { "phone", DataGeneratorType::PhoneNumber },
    { "token", DataGeneratorType::Token },
    { "group", DataGeneratorType::AlphaNumeric },
    { "category", DataGeneratorType::AlphaNumeric },
    { "password", DataGeneratorType::Crypto },
    { "comment", DataGeneratorType::Sentence },
    { "avatar", DataGeneratorType::Avatar },
    { "status", DataGeneratorType::Boolean },
    { "date_of_birth", DataGeneratorType::DateOfBirth },
    { "created_at", DataGeneratorType::DateTime },
    { "updated_at", DataGeneratorType::DateTime },
};

};
