#include "db.h"

int open_db(sqlite3** db){
    int rc = sqlite3_open("project.db", db);
    if(!(SQLITE_OK == rc)){
        printf("Cant open\nError: %s\n", sqlite3_errmsg(*db));
        return -1;
    }
    printf("Connected successfully\n");
    return 1;
}

int exec_query(const char* query, sqlite3** db){
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(*db, query, -1, &stmt, 0);
    if(rc != SQLITE_OK){
        printf("ERROR %d\n", rc);
        return -1;
    }
    rc = sqlite3_step(stmt);
    if(rc == SQLITE_DONE){
        printf("%s\n", query);
    }else if(rc == SQLITE_ROW){
        printf("%s=>\n", query);
        while(rc == SQLITE_ROW){
            printf("%s %s %s\n", sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2));
            rc = sqlite3_step(stmt);
        }
    
    }else{
        printf("%d", rc);
        printf("ERROR");
        sqlite3_finalize(stmt);
        return -1;
    }
    sqlite3_finalize(stmt);
    return 0;
}

int init_db(sqlite3** db){
    const char *query = "CREATE TABLE IF NOT EXISTS users ("\
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"\
        "username TEXT NOT NULL,"\
        "bio TEXT NOT NULL);";
    open_db(db);
    exec_query(query, db);
    return 0;
}

char *db_commands(char** req, int argc){
    char* command = req[0];
    if(strcmp(command, "add") == 0){
        if(argc >= 3){
            char* name = req[1];
            char* bio = join(req, " ", 2, argc-2);
            printf("We got %s\n%s\n", name, bio);
        }
        return "Add User\n";
    }
    return command;
}


char *str_user(struct User* u){

}