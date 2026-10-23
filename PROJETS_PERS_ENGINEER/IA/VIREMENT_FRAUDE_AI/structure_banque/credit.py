##### CREDIT IMPLEMENTATION ######

class Credit:
    def __init__(self, 
        credit_id: str, 
        banque_id: str, 
        compte_id: str, 
        montant_centimes: int, 
        motif: str, 
        statut: str="EN_ATTENTE"
    ) -> None:
        if not banque_id.strip() or not credit_id.strip() or not compte_id.strip() or not motif.strip():
            raise ValueError("Erreur dans la saisie d'un des identifiants") 
        if type(montant_centimes) is not int:
            raise TypeError("Erreur dans la saisie du montant")
        if montant_centimes<=0:
            raise ValueError("Erreur dans la saisie du montant")
        self.credit_id = credit_id.strip()
        self.banque_id = banque_id.strip()
        self.compte_id = compte_id.strip()
        self.montant_centimes = montant_centimes
        self.motif = motif.strip()
        self.statut = "EN_ATTENTE"

