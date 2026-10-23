############ TRANSACTION STRUCTURE ###################

class Virement:
    def __init__(self,
        virement_id: str, 
        banque_source_id: str, 
        compte_source_id: str, 
        banque_destination_id: str, 
        compte_destination_id: str,
        montant_centimes: int
    ) -> None:
        if not virement_id.strip():
            raise ValueError("Erreur dans l'identifiant de virement fourni")
        if not compte_source_id.strip() or not compte_destination_id.strip():
            raise ValueError("Erreur dans l'identifiant de compte")
        if not banque_source_id.strip() or not banque_destination_id.strip():
            raise ValueError("Erreur dans l'identifiant de banque")
        if type(montant_centimes) is not int:
            raise TypeError("Erreur de type de montant")
        if montant_centimes <= 0:
            raise ValueError("Le montant du virement doit être positif")  
                           
        self.virement_id = virement_id.strip()
        self.banque_source_id = banque_source_id.strip()
        self.compte_source_id = compte_source_id.strip()
        self.banque_destination_id = banque_destination_id.strip()
        self.compte_destination_id = compte_destination_id.strip()
        self.montant_centimes = montant_centimes
        self.statut = "EN_ATTENTE"
        