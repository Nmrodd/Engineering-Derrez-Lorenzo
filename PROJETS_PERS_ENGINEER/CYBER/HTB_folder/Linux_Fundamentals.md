//// Prise de note du Module ////

//////// Linux Fundamentals ////////

# Pour avoir une courte description : 
apropos <keyword>

Cf : apropos sudo 

Un des premiers exos comportaient six questions et m'a permis d'utiliser les commandes suivantes : 

Connexion SSH avec un nom et un mdp donné par le site 

uname qui permet d'obtenir bcp d'infos sur la machine 

En particulier : 

uname -m donne le nom du machine hardware  (ici c'était x86_64)
uname -i donne le hardaware platform 

uname -r donne le kernel release, il fallait ensuite les trois premiers termes avec des . 


j'ai utilisé la commande echo $MAIL pour obtenir le chemin du mail de htb-student qui était ici : /var/mail/htb-student

Pour obtenir le type de shell utilisé j'ai du faire la commande : 
 echo $SHELL 

enfin pour la dernière question il fallait trouver le nom du réseau qui avait un MTU fixé à 1500. 
pour cela je me suis souvenu de quelque chose que j'ai appris ce matin dans un apprentissage parallèle pour la cybersécurité que j'ai mis en note dans un autre README.md 
J'ai pensé à utilisé la commande ip addr qui permet d'obtenir beaucoup d'informations donc le MTU fixé.

// A propos de la navigation sur Linux // 

ls -l permet d'afficher plus de données que ls avec une description comme celle ci :

Premièrement : total ___ -> total amount of blocks (1014-byte) used by the files and directories listed in the current directory. 

Exemple : Total 32 -> 32 blocks * 1024 bytes/block = 32,768 bytes of disk space.

![alt text](image-2.png)


Cependant cela ne permet pas de révéler toutes les infos. 
Pour cela, il faut utiliser la commande : 
    //        ls -la

Par rapport à un des exos : 

Commande pour voir un fichier caché : (-t permet également de trié par date de modification)
    ls -la 

Les fichiers cachés commencent par un . 

Pour voir l'index number d'un fichier : (inode number)

ls -i fichier


Ensuite il y a certaines commandes liées au mouvement dans les différents fichiers. 

il est possible d'ajouter -p pour créer directement des dossiers parents : 

mkdir -p Storage/local/user/documents 
![alt text](image-3.png)

![alt text](image-4.png)

![alt text](image-5.png)


On Linux systems : 

    - There are several files that can be tremendously beneficial for penetration testers
        // due to misconfigured permissions or insufficient security settings by the administrators

        // One such important file is the /etc/passwd file.

            - It contains essential information about the users on the system
            - (usernames, user IDs (UIDs), group IDs (GIDs) and home directories)
    
Prise de note par rapport à certains éditeurs de Linux : 


VIM : 

![alt text](image-6.png)


Commande "Which" : 
    - return the path to the file or link that should be executed. 

    - allow us to determine if specific programme like cURL, netcat, wget, python, gcc are available on operating system.

![alt text](image-7.png)

Commande 'Find' :

![alt text](image-8.png)


Exemple : 

![alt text](image-9.png)
![alt text](image-10.png)
SSS
Commande "Locate" : 

![alt text](image-11.png)

A propos des RegEx : 

![alt text](image-12.png)

![alt text](image-13.png)

![alt text](image-14.png)

![alt text](image-15.png)



A propos des SUID (Set User ID) et Set Group ID (SGID) :

![alt text](image-16.png)


![alt text](image-17.png)

![alt text](image-18.png)

![alt text](image-20.png)

![alt text](image-19.png)

![alt text](image-21.png)

![alt text](image-22.png)

![alt text](image-23.png)