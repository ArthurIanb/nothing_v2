#include "responser.hpp"


std::string response(std::string request){
    Db db;
    // разделяем предложение на слова
    std::vector<std::string> splitted_request = split(request);
    if(splitted_request.size() == 0){
        return "ERROR";
    }
    // первое слово всегда команда
    std::string command = splitted_request[0];
    // Если в предложение только команда, то второй аргумент пустой vector
    if(splitted_request.size() == 1){
        return db.resp_command(command, {});
    }
    // Если кол-во слов больше = 2, то 2 слово это всегда имя пользователя или поле
    if(splitted_request.size() >= 2){
        std::vector<std::string> send_data;
        if(splitted_request.size() == 2)
            return db.resp_command(command, {splitted_request[1]});
        // arg - Объединенные слова с 2й позиции и до конда
        else{
            std::string arg = join(splitted_request, " ", 2, splitted_request.size());
            send_data = {splitted_request[1], arg};
        }
        return db.resp_command(command, send_data);
    }
    return "ERROR";
}
