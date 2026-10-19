# Avant-propos — Pourquoi un cours séparé ?

Ce support est le **cours théorique** complémentaire du *Manuel IA — Édition Grands Défis 2026*. Le manuel fixe les échéances et les livrables ; ce document explique les mécanismes que tu dois réellement comprendre. Il vise un étudiant d'école d'ingénieurs connaissant déjà la programmation et les mathématiques de classes préparatoires, mais découvrant l'apprentissage automatique. Il ne remplace pas intégralement les manuels universitaires cités ; il en ordonne l'étude et fournit des démonstrations pédagogiques originales.

**Contrat scientifique.** Distingue toujours (i) une définition mathématique, (ii) une intuition, (iii) une hypothèse du modèle et (iv) un résultat expérimental. Les figures de ce document sont générées spécifiquement pour ce cours à partir de données synthétiques. Ce ne sont ni des résultats de recherche, ni des figures empruntées à un article. Chacune porte une légende et des références sur lesquelles repose son explication.

## Comment étudier chaque chapitre

1. **Avant lecture (5 min)** : réponds mentalement à « à quoi sert ce concept ? ». 2. **Lecture active (25–45 min)** : essaie de refaire chaque calcul, en notant les symboles. 3. **Expérience (20–60 min)** : exécute un script fourni, modifie une variable, explique l'écart. 4. **Restitution (10 min)** : écris une définition accessible à un lycéen, puis une définition précise avec formules. 5. **Réactivation** : reviens sur la notion à J+2 et J+7, et surtout au moment du projet correspondant.

Tu ne dois **pas** lire ce cours linéairement en quatre semaines. Le mois théorique couvre prioritairement les chapitres 1 à 12, puis des introductions guidées aux chapitres 13 à 19. Les chapitres spécialisés sur les Transformers, les solveurs et les risques deviennent centraux pendant les projets ou les grands défis. Considère ce document comme un **manuel de référence sur plusieurs mois** ; les 20–25 h par mois restent inchangées.

## Une règle contre l'illusion de compréhension

Après chaque notion, produis trois preuves : une explication sans notes, un mini-calcul que tu vérifies à la main, et une expérience qui échoue si tu retires un élément essentiel. Exemple : pour la descente de gradient, explique le gradient, calcule une dérivée, puis fais volontairement diverger l'optimisation en choisissant un pas trop grand.

## Bibliothèque minimale : ordre de priorité

**P1 — Livre central, statistique et Machine Learning :** Gareth James et al., *An Introduction to Statistical Learning, with Applications in Python* (2023), PDF officiel gratuit. Chapitres sur régression, classification, validation, arbres et apprentissage non supervisé. [R01]

**P1 — Fondations mathématiques :** Deisenroth, Faisal, Ong, *Mathematics for Machine Learning* (2020), PDF officiel accessible gratuitement. Étudie seulement les chapitres mathématiques pertinents lorsque tu bloques. [R02]

**P1 — Deep learning, équations et code :** Zhang et al., *Dive into Deep Learning*, livre interactif gratuit avec notebooks. [R03]

**P1 — NLP / LLM :** Jurafsky et Martin, *Speech and Language Processing*, manuscrit 2026 en ligne ; attention, il s'agit d'un **brouillon**. [R04]

**P2 — Approfondissement conceptuel en Deep Learning :** Simon J. D. Prince, *Understanding Deep Learning* (2023), en complément de [R03]. [R05]

**P2 — Recherche d'états et IA classique :** cours Berkeley CS188 + Russell et Norvig, *Artificial Intelligence: A Modern Approach* (livre commercial). [R06, R07]

**P3 — Ingénierie avancée des modèles de langage :** Stanford CS336, *Language Modeling from Scratch* (2026). Prérequis : PyTorch solide, optimisation et architecture Transformer. [R08]

Ces ressources ne sont pas à lire intégralement dans cet ordre : chaque chapitre ci-dessous donne **la section à cibler** pour limiter la dispersion. Les liens complets et leur nature (ouvrage, cours, documentation, article) figurent en fin de document.

## Carte conceptuelle

- **Mathématiques et données** → vecteurs, probabilités, features et jeux de données.
- **Apprentissage statistique** → modèle, perte, optimisation, généralisation, évaluation.
- **Deep learning** → couches différentiables, backpropagation, PyTorch.
- **Langage** → tokens, TF–IDF, embeddings, Transformers et LLM.
- **Recherche / décision** → graphes, états, heuristiques et éventuellement reinforcement learning.
- **Ingénierie fiable** → expériences traçables, données sûres, tests, dérive et limites.

# Partie I — Mathématiques et programmation scientifique

