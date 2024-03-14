#include "responser/responser.hpp"

int temp = 0x1774;

void clear_char(char* array, int size){
    for(int i = 0; i < size; i++){
        *(array + i) = '\0';
    }
}


int main(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    const struct sockaddr_in addr = {
        AF_INET,
        0x7417,
        0
    };
    bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(fd, 5);
    printf("ACCEPTING\n");
    int client_fd = accept(fd, 0, 0);
    char* buf = (char*)malloc(256 * sizeof(char));
    while(1){
        int k = recv(client_fd, buf, 256, 0);
        if(k == 0)
            break;
        printf("buff: %s\n", buf);
        std::string resp = response(buf);
        send(client_fd, resp.c_str(), 256, 0);
        clear_char(buf, k);
    }

}
