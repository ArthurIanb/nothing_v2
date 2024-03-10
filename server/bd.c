#include <stdio.h>
#include <sqlite3.h> 

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
    if(rc != SQLITE_OK)
        return -1;
    rc = sqlite3_step(stmt);
    if(rc == SQLITE_DONE){
        printf("%s\n", query);
    }else if(rc == SQLITE_ROW){
        printf("%s => %s\n",query, sqlite3_column_text(stmt, 0));
    }else{
        printf("%d", rc);
        printf("ERROR");
        sqlite3_finalize(stmt);
        return -1;
    }
    return 0;
}

int init_db(sqlite3** db){
    const char *query = "CREATE TABLE IF NOT EXISTS users ("\
        "id INT PRIMARY KEY,"\
        "username TEXT NOT NULL,"\
        "bio TEXT NOT NULL);";
    open_db(db);
    exec_query(query, db);
    return 0;
}


int main(int argc, char* argv[]) {
    sqlite3 *db;
    init_db(&db);
    exec_query("SELECT 1+1;", &db);
    sqlite3_close(db);
}
