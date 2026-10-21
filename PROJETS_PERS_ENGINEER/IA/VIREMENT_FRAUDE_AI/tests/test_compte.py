import pytest
from structure_banque.compte import Compte

######## TEST FOR ACCOUNTS ######## 

### FIRST TEST ###

def test_creation_compte() -> None:
    compte = Compte("BANK-A", "CPT-001", "CLIENT-001", "EUR")

    assert compte.banque_id == "BANK-A"
    assert compte.compte_id == "CPT-001"
    assert compte.client_id == "CLIENT-001"
    assert compte.solde_centimes == 0

def test_compte_zero() -> None:
    compte = Compte("BANK-A", "CPT-001", "CLIENT-001", "EUR")
    assert compte.solde_centimes == 0

def test_id_banque_refuse() -> None:
    with pytest.raises(ValueError):
        compte = Compte("    ", "CPT-001", "CLIENT-001", "EUR")


def test_id_compte_refuse() -> None:
    with pytest.raises(ValueError):
        compte = Compte("BANK-A", "    ", "CLIENT-001", "EUR")

def test_id_client_refuse() -> None:
    with pytest.raises(ValueError):
        compte = Compte("BANK-A", "CPT-001", "", "EUR")


def test_devise1() -> None:
    compte = Compte("BANK-A", "CPT-001","CLIENT-001")
    assert compte.devise == "EUR"

def test_devise2() -> None:
    with pytest.raises(ValueError):
        compte = Compte("BANK-A", "CPT-001", "CLIENT-001", devise="    ")

def test_devise_inconnue_refuse() -> None:
    with pytest.raises(ValueError):
        compte = Compte("BANK-A", "CPT-001","CLIENT-001", devise="XYZ")
