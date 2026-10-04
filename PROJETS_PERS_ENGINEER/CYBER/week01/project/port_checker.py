# SESSION 4 : Creation port_checker en Python

# import sys

# print(sys.argv)


import sys

ip = sys.argv[1]
port = int(sys.argv[2])

print("IP :", ip)
print("Port :", port)


# Prochaine etape : socket TCP 

import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

result = sock.connect_ex((ip,port))

if result == 0:
    print(f"Port {port} is OPEN")
else:
    print(f"Port {port} is CLOSED")

sock.close()