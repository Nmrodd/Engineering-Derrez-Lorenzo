############ TRANSACTION STRUCTURE ###################

from structure_banque.client import Client
from structure_banque.compte import Compte
from structure_banque.banque import Banque

class Virement:
    def __init__(self,
        virement_id: str, 
        banque_source_id: str, 
        compte_source_id: str, 
        banque_destination_id: str, 
        compte_destination_id: str,
        montant_centimes: int
    ) -> None:
        if not compte_source_id.strip() or not compte_destination_id.strip():
            self.statut = "Refusé"
        else:
            self.statut = "Accepté"
        if montant_centimes<=0:
            self.statut = "Refusé"
        else:
            self.statut = "Accepté"
        self.virement_id = virement_id.strip()
        self.banque_source_id = banque_source_id.strip()
        self.compte_source_id = compte_source_id.strip()
        self.banque_destination_id = banque_destination_id.strip()
        self.compte_destination_id = compte_destination_id.strip()
        self.montant_centimes = montant_centimes
                     