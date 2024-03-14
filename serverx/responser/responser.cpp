#include "responser.hpp"

std::string response(std::string request){
    Db db;
    int r_len = sentence_length(request);
    if(r_len == 0){
        return "error";
    }
    std::vector<std::string> splitted_request = split(request);
    std::string command = splitted_request[0];
    if(splitted_request.size() == 1){
        return db.resp_command(command, {});
    }
    if(splitted_request.size() >= 2){
        std::vector<std::string> send_data;
        if(splitted_request.size() == 2)
            return db.resp_command(command, {splitted_request[1]});
        else{
            std::string arg = join(splitted_request, " ", 2, splitted_request.size());
            send_data = {splitted_request[1], arg};
        }
        std::string d_dd = db.resp_command(command, send_data);
        return d_dd;
    }
    return "impossible";
}
