############## IMPLEMENTATION OF THE CLASS BANK ##############

from structure_banque.compte import Compte
from structure_banque.client import Client

class Banque:
    def __init__(self, banque_id: str) -> None:
        if not banque_id.strip():
            raise ValueError("erreur dans l'identifiant de la banque")
        self.banque_id = banque_id.strip()
        self.comptes: dict[str, Compte] = {}
        self.clients: dict[str, Client] = {}

    def ajouter_compte(self, compte: Compte) -> None:
        if self.banque_id != compte.banque_id:
            raise ValueError("Ajout d'un compte dans la mauvaise banque")
        if compte.compte_id in self.comptes:
            raise KeyError("Ajout d'un compte avec un identifiant déjà existant")
        if compte.client_id not in self.clients:
            raise KeyError("Ajout d'un compte avec un client inconnu")
        self.comptes[compte.compte_id] = compte

    def obtenir_compte(self, compte_id: str) -> Compte:
        if compte_id not in self.comptes:
            raise KeyError("Identifiant inconnu")
        return self.comptes[compte_id]
    
    def ajouter_client(self, client: Client) -> None:
        if client.client_id in self.clients:
            raise KeyError("Ajout d'un client avec un identifiant déjà existant")
        self.clients[client.client_id] = client
    
    def obtenir_client(self, client_id: str) -> Client:
        if client_id not in self.clients:
            raise KeyError("Identifiant de client inconnu")
        return self.clients[client_id]
    
