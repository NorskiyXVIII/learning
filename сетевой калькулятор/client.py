import socket
import os



def isCommand(str: str) -> bool:
    return str.startswith("/")

def run():
    conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    conn.connect(("127.0.0.1", 9433))

    help = conn.recv(1024)
    print(help.decode("utf-8"))
    server_resp = b""

    while True:
        if server_resp.decode() == "COMMAND:EXIT":
            break
        if server_resp.decode() == "COMMAND:CLEAR_SCREEN":
            os.system("cls")
        
        if not isCommand(server_resp.decode()):
            print(server_resp.decode())
        resp = input(">>> ")
        conn.send(resp.encode())
        
        server_resp = conn.recv(1024)


    conn.close()


run()