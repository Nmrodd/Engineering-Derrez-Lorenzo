########### TESTS' FOR OPERATIONS ############

import pytest 

from structure_banque.client import Client
from structure_banque.compte import Compte
from structure_banque.banque import Banque
from structure_banque.virement import Virement

from structure_banque.operations import executer_virement

def test_refus_fonds_insuffisants() -> None:
    banque_a = Banque("BANK-A")
    banque_b = Banque("BANK-B")

    banque_a.ajouter_client(Client("CT-001", "Alice"))
    banque_b.ajouter_client(Client("CT-002", "Bob"))

    compte_a = Compte("BANK-A", "CPT-001", "CT-001")
    compte_b = Compte("BANK-B", "CPT-001", "CT-002")

    banque_a.ajouter_compte(compte_a)
    banque_b.ajouter_compte(compte_b)

    reseau = {
        "BANK-A": banque_a,
        "BANK-B": banque_b
    }

    virement = Virement(
        "VIT-001",
        "BANK-A", "CPT-001",
        "BANK-B", "CPT-001",
        4000
    )

    with pytest.raises(ValueError):
        executer_virement(virement, reseau)

    assert compte_a.solde_centimes == 0
    assert compte_b.solde_centimes == 0
    assert virement.statut == "REFUSE"

def test_virement_compte_inexistant() -> None:
    banque_a = Banque("BANK-A")
    banque_b = Banque("BANK-B")

    banque_a.ajouter_client(Client("CT-001", "Alice"))
    banque_b.ajouter_client(Client("CT-002", "Bob"))
    compte_a = Compte("BANK-A", "CPT-001", "CT-001")
    compte_b = Compte("BANK-B", "CPT-001", "CT-002")

    banque_a.ajouter_compte(compte_a)
    banque_b.ajouter_compte(compte_b)

    reseau = {
        "BANK-A": banque_a,
        "BANK-B": banque_b
    }

    virement = Virement(
        "VIT-001",
        "BANK-A", "CPT-001",
        "BANK-B", "CPT-999",
        4000
    )

    with pytest.raises(KeyError):
        executer_virement(virement, reseau)
    
    assert compte_a.solde_centimes == 0
    assert compte_b.solde_centimes == 0
    assert virement.statut == "REFUSE"


def test_virement_banque_inexistante() -> None:
    banque_a = Banque("BANK-A")
    banque_b = Banque("BANK-B")

    banque_a.ajouter_client(Client("CT-001", "Alice"))
    banque_b.ajouter_client(Client("CT-002", "Bob"))
    compte_a = Compte("BANK-A", "CPT-001", "CT-001")
    compte_b = Compte("BANK-B", "CPT-001", "CT-002")

    banque_a.ajouter_compte(compte_a)
    banque_b.ajouter_compte(compte_b)

    reseau = {
        "BANK-A": banque_a,
        "BANK-B": banque_b
    }

    virement = Virement(
        "VIT-003",
        "BANK-A", "CPT-001",
        "BANK-INCONNUE", "CPT-001",
        4000
    )

    with pytest.raises(KeyError):
        executer_virement(virement, reseau)
    
    assert compte_a.solde_centimes == 0
    assert compte_b.solde_centimes == 0
    assert virement.statut == "REFUSE"