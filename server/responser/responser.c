#include "responser.h"


char *response(char* request){
    int r_len = sentence_length(request);
    if(r_len <= 1){
        return "error";
    }
    int *argc = 0;
    char** splitted_request = parse_request(request);
    return db_commands(splitted_request, r_len);
}
