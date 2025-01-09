import socket

# TODO:
# занятся рефакторингом, а то весь код засран
# разбить все на более маленькие функции
# сделать tryNumericMode
# написать краткие объяснения к функциям
# сделать нормальные логи
# [ОПЦ]добавить возможность писать команды для клиента


calc_ver = "0.4"
help = '''
/help(/h) - выводит информацию о командах.
/clear(/cls) - очищает экран.
/exit - выходит из программы, закрывая соединение.
'''

def isCommand(str: str) -> bool:
    return str.startswith("/")

def parseCom(str: str) -> str:
    if not isCommand(str):
        return ""
    
    if str == "/help" or str == "/h":
        return "COMMAND:HELP"
    if str == "/clear" or str == "/cls":
        return "COMMAND:CLEAR_SCREEN" 
    if str == "/exit":
        return "COMMAND:EXIT"
    if str.startswith("/"):
        return "Неизвестная команда."

def getNum(string: str) -> (int, str):
    i = 0

    tmpStr = ""

    for ch in string:
        if ch.isdigit():
            tmpStr += ch
        else:
            break

    string = string.replace(tmpStr, "")
    
    #print(string)
    #print(f"NumBase = {tmpStr}, realNum = {int(tmpStr)}, type = {type(int(tmpStr))}")
    return (int(tmpStr), string)

def isOp(ch: str) -> bool:
    if (ch == "+" or ch == "*" or ch == "-" or ch == "/"):
        return True
    return False

def getOp(string: str) -> (str, str):
    tmpStr = ""

    for ch in string:
        #print("IsOp = ", isOp(ch), "operand = ", ch)
        if isOp(ch):
            tmpStr += ch
            break 

    string = string.replace(tmpStr, "")
    #print("Op string = ", string)
    #print("getted op = ", tmpStr, string)
    return (tmpStr, string)

def normalMode(resp: str) -> int:
    resp = resp.replace(" ", "")
    #print("trim= ", resp)

    if resp.isalpha() or resp.isspace() or not resp[0].isdigit():
        return "плохое выражение[]"
    firstNum, resp =  getNum(resp)
    #print("Getted num = ", firstNum)
    if resp == "":
        return firstNum
    operand, resp =   getOp(resp)
    if resp.isspace():
        return f"плохое выражение[{firstNum} {operand}]"

    #print("operand = ", operand)
    secondNum, resp = getNum(resp)
    #print("Getted num = ", secondNum)
    
    print(firstNum, operand, secondNum)

    if operand == "+":
        return firstNum + secondNum
    if operand == "-":
        return firstNum - secondNum
    if operand == "*":
        return firstNum * secondNum
    if operand == "/":
        return firstNum / secondNum
    if operand == "**":
        return firstNum ** secondNum

def tryNumericMode(resp: str, conn: socket.socket) -> int:
    if resp.isdigit():
        firstNum = 0
        secondNum = 0
        operand = "+"

        conn.send(b"COMMAND:NUMERIC_MODE")

def handleConnection(conn):
    resp = f'''Калькулятор по сети {calc_ver}.
    \t{help}
    '''

    conn.send(resp.encode())

    while True:
        client_resp = conn.recv(1024)
        client_resp_str = client_resp.decode("utf-8")

        print(client_resp_str)
        resp = parseCom(client_resp_str)
        print(resp)

        if resp.startswith("COMMAND:"):
            if resp == "COMMAND:HELP":
               conn.send(help.encode())
            if resp == "COMMAND:EXIT":
                conn.send(resp.encode())
                break
            if resp == "COMMAND:CLEAR_SCREEN":
                conn.send(resp.encode())
            continue
        
        print(client_resp_str.isalpha())
        if not client_resp_str.isalpha():
            #tryNumericMode(client_resp_str, conn)
            resp = normalMode(client_resp_str)
            resp = str(resp)
        else:
            resp = "Ошибка: неправильный ввод. Возможно вы ввели строку"
        


        conn.send(resp.encode())

    conn.close()    


def run():
    listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    listener.bind(("127.0.0.1", 9433))
    listener.listen(1)


    conn, _ = listener.accept()


    handleConnection(conn)

    listener.close()

run()