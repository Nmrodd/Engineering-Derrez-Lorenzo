import pytest

from structure_banque.banque import Banque
from structure_banque.virement import Virement
from structure_banque.operations import executer_virement
from structure_banque.operations import executer_credit
from structure_banque.credit import Credit 
from structure_banque.client import Client
from structure_banque.compte import Compte

def test_creation_credit_parrainage() -> None:
    credit = Credit(
        "CR-001",
        "BANK-A",
        "CPT-001",
        10000,
        "PARRAINAGE"
    )

    assert credit.credit_id == "CR-001"
    assert credit.banque_id == "BANK-A"
    assert credit.compte_id == "CPT-001"
    assert credit.montant_centimes == 10000
    assert credit.motif == "PARRAINAGE"
    assert credit.statut == "EN_ATTENTE"

def test_credit_montant_negatif() -> None:
    with pytest.raises(ValueError):
        credit = Credit(
            "CR-001",
            "BANK-A",
            "CPT-001",
            -10000,
            "PARRAINAGE"
        )
    
def test_credit_montant_float() -> None:
    with pytest.raises(TypeError):
        credit = Credit(
            "CR-001",
            "BANK-A",
            "CPT-001",
            1000.50,
            "PARRAINAGE"
        )


def test_credit_suppression_espaces() -> None:
    credit = Credit(
        " CR-001 ", " BANK-A ", " CPT-001 ",
        10000, " PARRAINAGE "
    )

    assert credit.credit_id == "CR-001"
    assert credit.banque_id == "BANK-A"
    assert credit.compte_id == "CPT-001"
    assert credit.motif == "PARRAINAGE"

def test_credit_montant_booleen_refuse() -> None:
    with pytest.raises(TypeError):
        Credit(
            "CR-002", "BANK-A", "CPT-001",
            True, "PARRAINAGE"
        )

def test_credit_identifiant_vide_refuse() -> None:
    with pytest.raises(ValueError):
        Credit(
            "   ", "BANK-A", "CPT-001",
            10000, "PARRAINAGE"
        )

def test_credit_scenario() -> None:
    banque_a = Banque("BANK-A")
    client = Client("CT-001", "Alice")
    compte = Compte("BANK-A", "CPT-001", "CT-001")

    banque_a.ajouter_client(client)
    banque_a.ajouter_compte(compte)

    reseau = {"BANK-A": banque_a}
    journal_credits = {}

    credit = Credit(
        "CR-001",
        "BANK-A",
        "CPT-001",
        10000,
        "PARRAINAGE"
    )
    executer_credit(credit, reseau, journal_credits)
    assert compte.solde_centimes == 10000
    assert credit.statut == "EXECUTE"
    assert journal_credits["CR-001"] is credit

    with pytest.raises(ValueError):
        executer_credit(credit, reseau, journal_credits)

    credit_doublon = Credit(
    "CR-001",
    "BANK-A",
    "CPT-001",
    7000,
    "PARRAINAGE"
)

    with pytest.raises(ValueError):
        executer_credit(
            credit_doublon,
            reseau,
            journal_credits
        )

    assert compte.solde_centimes == 10000
    assert journal_credits["CR-001"] is credit
    assert len(journal_credits) == 1
    assert credit_doublon.statut == "EN_ATTENTE"
    
    assert compte.solde_centimes == 10000
    assert credit.statut == "EXECUTE"
    assert len(journal_credits) == 1

