Prise de note par rapport à la session 4 de la première semaine de découverte de cybersécurité 

Mon premier programme réseau : 


Création du fichier port_checker.py 

commande : python port_checker 127.0.0.1 8000

Le port 8000 ici sert comme port de développement pour lancer facilement un petit serveur Web local sans toucher au port HTTP standard 80. 

( Par exemple : python3 -m http.server 8000 signifie : lance un serveur http et fais le écouter sur le port 8000)


![alt text](image.png)



/// La première chose à faire pour la suite : 

    // Récupérer les arguments données dans le terminal 

Pour cela on remplace le contenu du fichier python par des instructions avec import sys et print(sys.argv)

Pour le moment on a cela dans le python : 
![alt text](image-1.png)

Puis en lancant la commande python3 port_checker 127.0.0.1 8000 à nouveau on récupère : 
![alt text](image-2.png)

sys.argv[0] → 'port_checker.py'
sys.argv[1] → '127.0.0.1'
sys.argv[2] → '8000'

Puis on peut modifier le code python pour obtenir quelque chose comme cela : 

Code python : 
![alt text](image-3.png)

Résultat après compilation de la meme commande : 

![alt text](image-4.png)

A ce stade le port 8000 est considéré comme du texte, il est alors possible de modifier cela dans le code pour récupérer l'entier correspondant au port : 

port = int(sys.argv[2])

A partir de cet exemple, on peut retenir que le programme est capable de récupérer les paramètres donnés par l'utilisateur 

///// Prochaine étape : socket TCP 

On ajoute dans le code python : 

import socket 

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

Explication : 
    - socket.AF_INET -> "je veux utiliser des addresses IPv4"
    - socket.SOCK_STREAM -> "je veux utiliser une socket de type flux, donc TCP"

Conceptuellement : 
    socket(AF_INET, SOCK_STREAM)
       │          │
       │          └── TCP
       └───────────── IPv4

Pour tenter une première connexion : 
![alt text](image-5.png)


Le code à ce stade devient  : 

![alt text](image-6.png)


Puis dans un premier terminal je lance la commande : 

python3 -m http.server 8000
![alt text](image-7.png)

On laisse le terminal ouvert puis dans le second, on fait : 

python3 port_checker.py 127.0.0.1 8000

Si cela fonctionne, ici on est censé obtenir Résultats = 0, comme ici : 
![alt text](image-8.png)

Ici : connexion réussie = 0 

On peut à présent Ctrl + C pour stopper le serveur HTTP 

On peut tenter de relancer la commande du second terminal pour observer un autre résultat : 

![alt text](image-9.png)


Sous Linux : 111 -> connexion refusée 

On peut alors modifier le port_checker en conséquence pour afficher dans le terminal une meilleure réponse : 

![alt text](image-10.png)

