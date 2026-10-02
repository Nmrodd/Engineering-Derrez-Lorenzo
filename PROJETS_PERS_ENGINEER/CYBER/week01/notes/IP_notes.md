//// Prise de note à propos des adresses IP //// 


Il est possible de faire la commande ip addr pour observer l'interface des différentes adresses IP 

A propos de la commande ip addr : 

    - affiche les adresses IP
    - affiche l'état des interfaces réseau 

![alt text](image-1.png)

127.0.0.1 désigne ma propre machine
Généralement, une adresse du type : 192.168.x.x correspond à un réseau local. 

Exemple après avoir fait ip addr : 

![alt text](image.png)


Selon ChatGPT_Plus, on peut avoir la description d'un exemple ip addr de la manière suivante ; 

![alt text](image-2.png)

lo -> loopback. C'est une interface réseau virtuelle permettant à la machine de communiquer avec elle meme. 

<LOOPBACK, UP, LOWER_UP> donne plusieurs drapeaux d'état. 
LOOPBACK indique que c'est une interface 