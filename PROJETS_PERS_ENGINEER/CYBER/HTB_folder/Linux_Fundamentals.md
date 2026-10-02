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

uname -r donne le kernbel release, il fallait ensuite les trois premiers termes avec des . 


j'ai utilisé la commande echo $MAIL pour obtenir le chemin du mail de htb-student qui était ici : /var/mail/htb-student

Pour obtenir le type de shell utilisé j'ai du faire la commande : 
 echo $SHELL 

enfin pour la dernière question il fallait trouver le nom du réseau qui avait un MTU fixé à 1500. 
pour cela je me suis souvenu de quelque chose que j'ai appris ce matin dans un apprentissage parallèle pour la cybersécurité que j'ai mis en note dans un autre README.md 
J'ai pensé à utilisé la commande ip addr qui permet d'obtenir beaucoup d'informations donc le MTU fixé.

