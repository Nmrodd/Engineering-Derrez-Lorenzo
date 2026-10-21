from structure_banque.client import Client

### First Test : Client.py ###

## Représenter deux personnes, avec identifiant et nom. 


def test_creation_client() -> None:
    bob = Client("CT-001", "Bob")

    assert bob.client_id == "CT-001"
    assert bob.nom == "Bob"


def test_independance_clients() -> None:
    bob = Client("CT-001", "Bob")
    alice = Client("CT-002", "Alice")

    assert bob is not alice