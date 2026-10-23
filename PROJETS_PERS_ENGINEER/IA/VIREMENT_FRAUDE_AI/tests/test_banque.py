import pytest

from structure_banque.banque import Banque
from structure_banque.compte import Compte
from structure_banque.client import Client

############## FIRST TEST : MANAGE BANK & HIS ACCOUNT ##############


def test_ajouter_et_obtenir_compte() ->None:
    banque = Banque("BANK-A")
    compte = Compte("BANK-A", "CPT-001", "CT-001")
    client = Client("CT-001", "client1")

    banque.ajouter_client(client)
    banque.ajouter_compte(compte)
    compte_retrouve = banque.obtenir_compte("CPT-001")

    assert compte_retrouve is compte

def test_ajout_mauvaise_bank() -> None:
    banque = Banque("BANK-A")
    compte = Compte("BANK-B", "CPT-001", "CT-001")
    client = Client("CT-001", "CLIENT1")

    banque.ajouter_client(client)

    with pytest.raises(ValueError):
        banque.ajouter_compte(compte)

def test_ajout_meme_id_compte() ->None:
    banque = Banque("BANK-A")
    compte1 = Compte("BANK-A", "CPT-001", "CT-001")
    compte2 = Compte("BANK-A", "CPT-001", "CT-002")

    client1 = Client("CT-001", "CLIENT1")
    client2 = Client("CT-002", "CLIENT2")

    banque.ajouter_client(client1)
    banque.ajouter_client(client2)

    banque.ajouter_compte(compte1)

    with pytest.raises(KeyError):
        banque.ajouter_compte(compte2)
    
    assert banque.obtenir_compte("CPT-001") is compte1

def test_ajout_dans_deuxbanque() -> None:
    banque_A = Banque("BANK-A")
    banque_B = Banque("BANK-B")
    compte1 = Compte("BANK-A", "CPT-001", "CT-001")
    compte2 = Compte("BANK-B", "CPT-001", "CT-002")

    client1 = Client("CT-001", "CLIENT1")
    client2 = Client("CT-002", "CLIENT2")

    banque_A.ajouter_client(client1)
    banque_B.ajouter_client(client2)

    banque_A.ajouter_compte(compte1)
    banque_B.ajouter_compte(compte2)

    assert banque_A.obtenir_compte("CPT-001") is compte1
    assert banque_B.obtenir_compte("CPT-001") is compte2

    assert banque_A.comptes is not banque_B.comptes

def test_obtenir_compte_inexistant() -> None:
    banque = Banque("BANK-A")

    with pytest.raises(KeyError):
        banque.obtenir_compte("CPT-404")

###### Registre des clients ######

def test_ajouter_et_obtenir_client() -> None:
    banque = Banque("BANK-A")
    alice = Client("CT-001", "Alice")

    banque.ajouter_client(alice)

    client_retrouve = banque.obtenir_client("CT-001")

    assert client_retrouve is alice

def test_ajouter_client_meme_id() -> None:
    banque = Banque("BANK-A")
    alice = Client("CT-001", "Alice")
    bob = Client("CT-001", "Bob")

    banque.ajouter_client(alice)
    
    with pytest.raises(KeyError):
        banque.ajouter_client(bob)
    
    assert banque.obtenir_client("CT-001") is alice
    
def test_ajout_compte_client_inconnu() -> None:
    banque = Banque("BANK-A")

    compte = Compte(
        "BANK-A",
        "CPT-001",
        "CT-999"
    )

    with pytest.raises(KeyError):
        banque.ajouter_compte(compte)
