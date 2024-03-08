#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
int temp = 0x1772;
int main(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    const struct sockaddr_in addr = {
        AF_INET,
        0x7317,
        0
    };
    bind(fd, &addr, sizeof(addr));
    listen(fd, 5);
    printf("ACCEPTING\n");
    int client_fd = accept(fd, 0, 0);
    char buf[256] = {0};
    while(1){
        int k = recv(client_fd, buf, 256, 0);
        if(k == 0)
            break;
        printf("buff: %s\n", buf);
        send(client_fd, buf, 256, 0);
        *buf = "";
    }
}