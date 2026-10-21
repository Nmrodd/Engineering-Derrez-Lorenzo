############## IMPLEMENTATION OF A BANK ACCOUNT ##############



### Rules ###

# Start with 0euros
# Verify the validity of the link of "parrainage"
# Register the promotional credit operation
# Process immediately of the transaction 

class Compte:
    def __init__(
        self,
        banque_id:str,
        compte_id:str,
        client_id:str,
        devise:str="EUR"
    ) -> None:
        if not banque_id.strip() or not client_id.strip() or not compte_id.strip() or not devise.strip():
            raise ValueError("Un des identifiants est invalide.")
        if devise.strip() != "EUR":
            raise ValueError("Erreur dans la devise")
        self.devise = devise.strip()
        self.client_id = client_id.strip()
        self.compte_id = compte_id.strip()
        self.banque_id = banque_id.strip()
        self.solde_centimes = 0

