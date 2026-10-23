import pytest

from structure_banque.client import Client
from structure_banque.compte import Compte
from structure_banque.banque import Banque
from structure_banque.virement import Virement

#### FIRST TESTS #####

def test_creation_virement() -> None:
    vir1 = Virement("VIT-001", "BANK-A", "CPT-001","BANK-B", "CPT-001", 500000)

    assert(vir1.virement_id == "VIT-001")
    assert vir1.banque_source_id == "BANK-A"
    assert vir1.compte_source_id == "CPT-001"

    assert vir1.banque_destination_id == "BANK-B"
    assert vir1.compte_destination_id == "CPT-001"

    assert vir1.montant_centimes == 500000
    assert vir1.statut == "EN_ATTENTE"

def test_vir_refuse_montant_negatif() -> None:
    with pytest.raises(ValueError):
        Virement("VIT-001", "BANK-A", "CPT-001", "BANK-B", "CPT-001", -500000)
    

def test_identifiant_virement_vide_refuse() -> None:
    with pytest.raises(ValueError):
        Virement(
            "",
            "BANK-A",
            "CPT-001",
            "BANK-B",
            "CPT-002",
            5000
        )

def test_montant_decimal_refuse() -> None:
    with pytest.raises(TypeError):
        Virement(
            "VIT-002", "BANK-A", "CPT-001",
            "BANK-B", "CPT-002", 50.5
        )


def test_montant_booleen_refuse() -> None:
    with pytest.raises(TypeError):
        Virement(
            "VIT-003", "BANK-A", "CPT-001",
            "BANK-B", "CPT-002", True
        )

def test_montant_un_centime_accepte() -> None:
    virement = Virement(
        "VIT-004",
        "BANK-A",
        "CPT-001",
        "BANK-B",
        "CPT-002",
        1
    )

    assert virement.montant_centimes == 1
    assert virement.statut == "EN_ATTENTE"