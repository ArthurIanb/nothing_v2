#include "funks.hpp"
 
int min(int a, int b){
    if(a > b)   return b;
    return a;
}

// Ошистка буфера типа char* с размером size
void clear_char(char* array, int size){
    for(int i = 0; i < size; i++){
        *(array + i) = '\0';
    }
}

// Соединение count слов в векторе list с разделителем sep начиная со start 
std::string join(std::vector<std::string> list, const std::string sep, int start, int count){
    if(list.size() == 0) return "";
    std::string out = list[start];
    for(int i = start+1; i < min(start + count, list.size()); i++){
        out += sep + list[i];
    }
    return out;
}

// Разделение строки str на слова
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

