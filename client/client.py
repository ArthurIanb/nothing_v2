import socket


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect(("localhost", 6003))
    inp = input()
    while inp != 'c' and inp not in '\n\0':
        print(inp)
        s.sendall(inp.encode())
        back = s.recv(256)
        for i in back:
            print(chr(i), end="")
            if i == 0:
                break
        print()
        inp = input()