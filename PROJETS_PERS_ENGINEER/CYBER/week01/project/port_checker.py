# SESSION 4 : Creation port_checker en Python

# import sys

# print(sys.argv)


# import sys

# # Verification lors de la compilation des arguments : 


# # Cette verif est à modifier par 4 si on veut tester l'étape du scan des plages détaillées dans le .md (CF regarder en bas du fichier python)
# if len(sys.argv) != 3:
#     print("Usage: python3 port_checker.py <ip> <port>")
#     sys.exit(1)

# ip = sys.argv[1]
# port = int(sys.argv[2])

# print("IP :", ip)
# print("Port :", port)


# # Prochaine etape : socket TCP 

# import socket

# sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# # Ajout d'un timeout pour éviter une connexion trop lente 
# sock.settimeout(1)

# result = sock.connect_ex((ip,port))

# if result == 0:
#     print(f"Port {port} is OPEN")
# else:
#     print(f"Port {port} is CLOSED")

# sock.close()

#### Pour la partie Bonus : Vérification des scan de plages 
import sys
import socket

if len(sys.argv) != 4:
    print("Usage: python3 port_checker.py <ip> <start_port> <end_port>")
    sys.exit(1)

ip = sys.argv[1]
start_port = int(sys.argv[2])
end_port = int(sys.argv[3])

for port in range(start_port, end_port + 1):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(1)

    result = sock.connect_ex((ip, port))

    if result == 0:
        print(f"Port {port} is OPEN")
    else:
        print(f"Port {port} is CLOSED")

    sock.close()

# Le but de cette section est de vérifié l'ouverture des ports dans une plage donnée en argument : 
#Exemple de sortie quand on fait la commande :  python3 port_checker.py 127.0.0.1 7995 8005
#Lorsque l'on a pas ouvert le port 8000 dans l'autre terminal :

# Port 7995 is CLOSED
# Port 7996 is CLOSED
# Port 7997 is CLOSED
# Port 7998 is CLOSED
# Port 7999 is CLOSED
# Port 8000 is CLOSED
# Port 8001 is CLOSED
# Port 8002 is CLOSED
# Port 8003 is CLOSED
# Port 8004 is CLOSED
# Port 8005 is CLOSED