#include "funks.h"


char *join(char** list, const char* sep, int start, int count){
    // !!!! UNSAFE !!!!!
    char* out = (char*)malloc((count) * 10 * sizeof(char));
    strcat(out, list[start]);
    for(int i = start+1; i < start + count; i++){
        char *list_pt = *(list + i);
        int ll = sizeof(*list_pt);
        if(!*list_pt) break;
        strcat(out, sep);
        strcat(out, list[i]);
    }
    return out;
}

int sentence_length(char* sent){
    int out = 0;
    int i = 0;
    int last_space = 0;
    while(sent[i] != '\0'){
        if(last_space-1 && sent[i] == ' '){
            last_space = 1;
            out ++;
            i++;
            continue;
        }
        if(sent[i++] != ' '){
            last_space = 0;
        }    
    }
    if(sent[i-1] != ' '){
        out += 1;
    }
    return out;
}

char **parse_request(char* request){
    char **out = (char**)malloc(8 * sizeof(char) * 100);
    char *temp = (char*)malloc(128 * sizeof(char));

    int i = 0;
    int ti = 0;
    int argc = 0;

    while(*(request+i) != '\0'){
        while(*(request+i) != ' ' && *(request+i) != '\0'){
            *(temp+ti++) = request[i++];
        }
        while(*(request+i) == ' ')
            i++;
        *(out+argc++) = temp;
        temp = (char*)malloc(128);
        ti = 0;
    }
    return out;
}