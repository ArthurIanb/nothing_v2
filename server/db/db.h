
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../help_stuff/funks.h"

/*
    db.h - интефейс бд
*/

struct User{
    char *name;
    char *bio;
};

// Подключение к бд
int open_db(sqlite3**);

// Выполнение запросов к бд
int exec_query(const char*, sqlite3**);

// Инициализация бд
int init_db(sqlite3**);

//
char *db_commands(char**, int);

// 
char *str_user(struct User*);
