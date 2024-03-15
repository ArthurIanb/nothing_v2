#include <sqlite3.h>
#include <iostream>
#include <vector>

// Класс для удобной работы с sqlite3
class Db{
    private:
        sqlite3 *db;
        // Выполнения sql запроса
        std::string exec_query(std::string query);
        // Создание пользователя в бд
        std::string create_user(std::string username, std::string bio);
        // Получение пользователя
        std::string get_user(std::string field, std::string value);
        // Ошистка бд
        std::string clear_db();
        // Удаление пользователя
        std::string rem_user(std::string field, std::string value);
    public:
        Db();
        // Функция отвечающая на команду command с аргументами data
        std::string resp_command(std::string command, std::vector<std::string> data);
        ~Db();
};