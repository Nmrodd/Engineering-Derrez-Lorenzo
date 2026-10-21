<!-- Ceci est le markdown de base pour la structuration du projet -->

Idée de base du projet : 

    - Créer un environnement IA capable de déterminer les virements frauduleux. 


Langage : 
    - Python pour utiliser l'IA : Pythorch

A propos de la banque: 

    - Commencement: 
        // structure classique en Python pour créer une banque 
        // une structure capable d'imiter "Dans l'idéal" mais avec des éléments python pour une première approche plus simple et centralisée.

    - Dans l'idéal: 
        // Base de données SQL avec un code python capable de faire les vérifications et les "Aller-retours" dans la base pour analyser les virements et les transactions

Implémentation de base des méthodes pour la banque:
    - Créer_banque()
    - Ajouter_compte()
    - ... (Déterminer les fonctions qui peuvent etre nécessaire en fonction de la structure)

Implémentation des méthodes de surveillance pour la banque:
    - analyser_virement()
    - ... déterminer les fonctions qui peuvent etre utiles en ce sens. 

Les éléments à rechercher & les fonctions à comprendre pour utiliser/créer un modèle IA:

    - implémentation de la banque
    - Déterminer le bon réseau de neuronne
    - Créer toute la structure 
    - comprendre chacun des éléments que l'on va ajouter, des fonctions et de leur sens, dans quel but on l'utilise...


Choix de la détection de la fraude : 
    - Avant l'acquisition du virement ?
    - Après l'acquisition du virement ?


// Pour le début : surement de l'analyse post-virement.


           BESOIN CLIENT
  Détecter les transactions suspectes
                  │
                  ▼
           ACQUISITION DATA
      Source, format, conformité
                  │
                  ▼
        PRÉPARATION DES DONNÉES
       Nettoyage, validation, variables
                  │
                  ▼
          MODÈLE DE DÉTECTION
       Baseline puis Machine Learning
                  │
                  ▼
          TESTS ET ÉVALUATION
     Précision, rappel, faux positifs
                  │
                  ▼
           RAPPORT AU CLIENT
      Résultats, limites, recommandations

