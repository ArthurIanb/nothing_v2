import socket


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Подключаемся к localhostу на 6004 порте
    s.connect(("localhost", 6004))
    inp = input()
    # Пока пользователь не введет c или переход на новую строку или, каким то обарзом, нулевой символ
    while inp != 'c' and inp not in '\n\0':
        # Отправляем на сервак input 
        s.sendall(inp.encode())
        # Получаем ответ
        back = s.recv(256)
        for i in back:
            # Decoding ответ
            print(chr(i), end="")
            if i == 0:
                break
        print()
        inp = input()