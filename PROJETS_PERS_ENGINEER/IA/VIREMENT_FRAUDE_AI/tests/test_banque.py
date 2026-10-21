import pytest

from structure_banque.banque import Banque
from structure_banque.compte import Compte

############## FIRST TEST : MANAGE BANK & HIS ACCOUNT ##############


def test_ajouter_et_obtenir_compte() ->None:
    banque = Banque("BANK-A")
    compte = Compte("BANK-A", "CPT-001", "CT-001")

    banque.ajouter_compte(compte)

    compte_retrouve = banque.obtenir_compte("CPT-001")

    assert compte_retrouve is compte

def test_ajout_mauvaise_bank() -> None:
    banque = Banque("BANK-A")
    compte = Compte("BANK-B", "CPT-001", "CT-001")

    with pytest.raises(ValueError):
        banque.ajouter_compte(compte)

def test_ajout_meme_id_compte() ->None:
    banque = Banque("BANK-A")
    compte1 = Compte("BANK-A", "CPT-001", "CT-001")
    compte2 = Compte("BANK-A", "CPT-001", "CT-002")

    banque.ajouter_compte(compte1)

    with pytest.raises(KeyError):
        banque.ajouter_compte(compte2)
    
    assert banque.obtenir_compte("CPT-001") is compte1

def test_ajout_dans_deuxbanque() -> None:
    banque_A = Banque("BANK-A")
    banque_B = Banque("BANK-B")
    compte1 = Compte("BANK-A", "CPT-001", "CT-001")
    compte2 = Compte("BANK-B", "CPT-001", "CT-001")

    banque_A.ajouter_compte(compte1)
    banque_B.ajouter_compte(compte2)

    assert banque_A.obtenir_compte("CPT-001") is compte1
    assert banque_B.obtenir_compte("CPT-001") is compte2

    assert banque_A.comptes is not banque_B.comptes

def test_obtenir_compte_inexistant() -> None:
    banque = Banque("BANK-A")

    with pytest.raises(KeyError):
        banque.obtenir_compte("CPT-404")
