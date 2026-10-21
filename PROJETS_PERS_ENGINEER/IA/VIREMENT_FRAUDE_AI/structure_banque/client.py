############## Implementation of Client ################

#### Session 01 ####

### Goals ###
# Définir les attributs nécessaires à un client;
# Créer le module client.py;
# Définir la classe Client et son constructeur;
# Créer deux clients fictifs aux identifiants différents;
# Vérifier les attributs grâce à un test;
# Importer Client depuis un autre module.

class Client:
    def __init__(self, client_id:str, nom:str) -> None:
        self.nom = nom.strip()
        if(client_id.strip() == ""):
            raise ValueError("ID Error")
        else:
            self.client_id = client_id.strip()
