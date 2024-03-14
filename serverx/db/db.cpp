#include "db.hpp"

std::string Db::exec_query(std::string query){
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(this->db, query.c_str(), -1, &stmt, 0);
    if(rc != SQLITE_OK){
        return "ERROR";
    }
    std::string out = "";
    rc = sqlite3_step(stmt);
    if(rc == SQLITE_DONE){
        out = "Done: " + query + '\n';
    }
    if(rc == SQLITE_ROW){
        while(rc == SQLITE_ROW){
            char* coll;
            int i = 0;
            while(1){
                coll = (char*)sqlite3_column_text(stmt, i++);
                if(!coll) break;
                out += std::string(coll) + ' ';
            }
            rc = sqlite3_step(stmt);
            out += '\n';
        }
    }
    sqlite3_finalize(stmt);
    return out;
}
Db::Db(){
    int rc = sqlite3_open_v2("project.db", &this->db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    if(!(SQLITE_OK == rc)){
        printf("Cant open\nError: %s\n", sqlite3_errmsg(db));
        return;
    }
    const char *query = "CREATE TABLE IF NOT EXISTS users ("\
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"\
    "username TEXT NOT NULL,"\
    "bio TEXT NOT NULL);";
    exec_query(query);
    // printf("Connected successfully\n");
}

std::string Db::create_user(std::string username, std::string bio){
    std::string query = "INSERT INTO users(username, bio) VALUES(\"" + username + "\", \"" + bio + "\");";
    std::string out = exec_query(query);
    return out;
}

std::string Db::get_user(std::string field, std::string value){
    if(field == "all" || value == "all")
        return exec_query("SELECT * FROM users;");
    if(field != "id" && field != "username" && field != "bio")
        return "No such field " + field;
    std::string query = "SELECT * FROM users WHERE " + field + "=\"" + value + "\";";
    return exec_query(query);
}

std::string Db::clear_db(){
    std::string query = "DELETE FROM users;";
    return exec_query(query);
}

std::string Db::rem_user(std::string field, std::string value){
    if(field != "id" && field != "username" && field != "bio")
        return "No such field " + field;
    std::string query = "DELETE FROM users WHERE " + field + "=\"" + value + "\";";
    printf("DELETED %s", get_user(field, value).c_str());
    return  exec_query(query);
}
std::string Db::resp_command(std::string command, std::vector<std::string> data){
    if(command == "add"){
        if(data.size() != 2)
            return "error, data should be 2";
        std::string username = data[0];
        std::string bio = data[1];
        return create_user(username, bio);
    }
    if(command == "rem"){
        if(data.size() != 2){
            return "error, data is not equal 2 2";
        }
        std::string field = data[0];
        std::string value = data[1];
        return rem_user(field, value);
    }
    if(command == "flush"){
        return clear_db();
    }
    if(command == "get"){
        if(data.size() == 1 && data[0] == "all")
            return get_user("all", "");
        if(data.size() != 2){
            return "Error, no enough data";
        }
        std::string field = data[0];
        std::string value = data[1];
        return get_user(field, value);
    }
    return "nonono";
}
Db::~Db(){
    sqlite3_close_v2(this->db);
}
