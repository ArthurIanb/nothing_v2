#include <sqlite3.h>
#include <iostream>
#include <vector>

class Db{
    private:
        sqlite3 *db;
        std::string exec_query(std::string query);
        std::string create_user(std::string username, std::string bio);
        std::string get_user(std::string field, std::string value);
        std::string clear_db();
        std::string rem_user(std::string field, std::string value);
    public:
        Db();
        std::string resp_command(std::string command, std::vector<std::string> data);
        ~Db();
};