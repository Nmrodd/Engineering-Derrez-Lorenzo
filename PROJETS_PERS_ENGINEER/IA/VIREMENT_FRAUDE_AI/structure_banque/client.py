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

        if not client_id.strip() or not nom.strip():
            raise ValueError("ID or Name Error")

        self.nom = nom.strip()
        self.client_id = client_id.strip()

