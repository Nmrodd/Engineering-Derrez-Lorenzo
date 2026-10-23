############ OPERATIONS STRUCTURE ##############


from structure_banque.banque import Banque
from structure_banque.virement import Virement

def executer_virement(virement: Virement, banques: dict[str, Banque]) -> None:
    if virement.banque_source_id not in banques or virement.banque_destination_id not in banques:
        virement.statut = "Refusé"
        raise KeyError("Erreur dans l'identifiant d'une des deux banques")
    if type(virement.montant_centimes) is not int:
        virement.statut = "Refusé"
        raise TypeError("Erreur dans le type du montant")
    if virement.montant_centimes <= 0:
        virement.statut = "Refusé"
        raise TypeError("Erreur dans le type du montant") 
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
        virement.statut = "Refusé"
        raise ValueError("Solde insuffisant")
    
