############ OPERATIONS STRUCTURE ##############


from structure_banque.banque import Banque
from structure_banque.virement import Virement
from structure_banque.credit import Credit

def executer_virement(virement: Virement, banques: dict[str, Banque]) -> None:
    if virement.banque_source_id not in banques or virement.banque_destination_id not in banques:
        virement.statut = "REFUSE"
        raise KeyError("Erreur dans l'identifiant d'une des deux banques")
    if type(virement.montant_centimes) is not int:
        virement.statut = "REFUSE"
        raise TypeError("Erreur dans le type du montant")
    if virement.montant_centimes <= 0:
        virement.statut = "REFUSE"
        raise ValueError("Erreur dans le type du montant") 
    banque_source = banques[virement.banque_source_id]
    banque_destination = banques[virement.banque_destination_id]

    try:
        compte_source = banque_source.obtenir_compte(
            virement.compte_source_id
        )
        compte_destination = banque_destination.obtenir_compte(
            virement.compte_destination_id
        )

    except KeyError:
        virement.statut = "REFUSE"
        raise
    
    if compte_source.solde_centimes < virement.montant_centimes:
        virement.statut = "REFUSE"
        raise ValueError("Solde insuffisant")
    
def executer_credit(
    credit: Credit, 
    banques: dict[str, Banque], 
    journal_credits: dict[str, Credit]
) -> None:

    if credit.banque_id not in banques:
        raise KeyError("Mauvais identifiant de banque") 
    if credit.statut == "EN_ATTENTE" and credit.credit_id not in journal_credits:
        recup_compte = banques[credit.banque_id].obtenir_compte(credit.compte_id)
        recup_compte.solde_centimes += credit.montant_centimes
        journal_credits[credit.credit_id] = credit 
        credit.statut = "EXECUTE"
    else:
        raise ValueError("Statut du crédit erronné")

