############## IMPLEMENTATION OF THE CLASS BANK ##############

from structure_banque.compte import Compte

class Banque:
    def __init__(self, banque_id:str) -> None:
        if not banque_id.strip():
            raise ValueError("erreur dans l'identifiant de la banque")
        self.banque_id = banque_id.strip()
        self.comptes: dict[str, Compte] = {}

    def ajouter_compte(self, compte:Compte) -> None:
        if self.banque_id != compte.banque_id:
            raise ValueError("Ajout d'un compte dans la mauvaise banque")
        if compte.compte_id in self.comptes:
            raise KeyError("Ajout d'un compte avec un identifiant déjà existant")
        self.comptes[compte.compte_id] = compte

    def obtenir_compte(self, compte_id: str) -> Compte:
        if compte_id not in self.comptes:
            raise KeyError("Identifiant inconnu")
        return self.comptes[compte_id]
