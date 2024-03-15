#include "responser/responser.hpp"


int main(){
    // Получаем файловый дескриптор для сокета
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // Семейство, порт
    const struct sockaddr_in addr = {
        AF_INET,
        // Этот порт соответсвует числу 0x1774 (6004)
        0x7417,
        0
    };
    // Биндим файловый дескриптор
    bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    // Получаем подключения
    listen(fd, 5);
    printf("ACCEPTING\n");
    // Файловый дескриптор пользователя
    int client_fd = accept(fd, 0, 0);
    // UNSAFE
    char* buf = (char*)malloc(256 * sizeof(char));
    while(1){
        // Получаем данные от пользоватея в buf
        // k - это кол-во байт, полученных от пользвателя
        int k = recv(client_fd, buf, 256, 0);
        if(k == 0)
            break;
        // Выводим команду, которую нам отправил пользователь
        printf("buff: %s\n", buf);
        std::string resp = response(buf);
        // resp - ответ
        // Отправляем ответ
        send(client_fd, resp.c_str(), 256, 0);
        // Очищаем буфер
        clear_char(buf, k);
    }

}
