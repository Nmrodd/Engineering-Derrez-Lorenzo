<!-- Ceci est le fichier qui va servir à décomposer la structure de la banque -->

Les structures à envisager: 

    - Client: Id, nom, compte détenus -> Permet de représenter le titulaire
    - Compte: Id, titulaires, solde, devise -> Représente un compte
    - Virement: Id, émetteur, bénéficiaire, montant, date, statut -> Représenter une opération
    - Banque: Ensemble de clients et comptes, registre des opérations -> Coordonner le système


Premier exemple de visualisation:
    // 3 clients fictifs;
    // Chacun possède un compte;

    // Pour identifier un client:
        - Identifiant (unique/clé primaire), nom (facultatif si demande trop d'espace en mémoire), nombres de comptes qu'il détient, date pour savoir si le client est récent ou non. 
    // Pour identifier un virement:
        - Id, émetteur, bénéficiaire, montant, date, statut
    // Pour enregistrer un virement entre deux comptes: 
        - Stocker les informations du virement dans une structure particulière, status(si le virement a été annulé alors on l'enregistre dans une partie "Echec" et sinon "Aboutit", ou quelque chose comme ça)

