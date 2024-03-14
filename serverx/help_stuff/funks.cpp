#include "funks.hpp"

int min(int a, int b){
    if(a > b)   return b;
    return a;
}

std::string join(std::vector<std::string> list, const std::string sep, int start, int count){
    if(list.size() == 0) return "";
    std::string out = list[start];
    for(int i = start+1; i < min(start + count, list.size()); i++){
        out += sep + list[i];
    }
    return out;
}

int sentence_length(std::string sent){
    int out = 0;
    int i = 0;
    int last_space = 0;
    while(i < sent.length()){
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


std::vector<std::string> split(std::string str){
    std::string temp = "";
    std::vector<std::string> out;

    int i = 0;
    while(i < str.length()){
        while(str[i] != ' ' && i < str.length()){
            temp += str[i++];
        }
        while(str[i] == ' ')
            i ++;
        out.push_back(temp);
        temp = "";
    }
    return out;
}

