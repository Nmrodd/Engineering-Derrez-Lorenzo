# Cours théorique IA — Dossier de travail

Ce dossier complète **le manuel de planification « Grands Défis 2026 »**. Il contient :

- `Cours_theorique_IA.pdf` : le cours consultable, sourcé et illustré ;
- `Cours_theorique_IA.md` : source éditable du document ;
- `chapitres/` : les sections Markdown séparées pour naviguer et annoter ;
- `figures/` : 16 graphiques originaux et reproductibles ;
- `code/` : 5 petites expériences exécutables et le script de figures ;
- `exercices/` : espace pour tes propres réponses (voir `exercices/README.md`).

## Ordre pratique

Pour le **mois de fondations** du programme, travaille les chapitres 1–12 comme socle prioritaire ; parcours les chapitres 13–17 comme introduction, puis reviens dessus lors du projet NLP/LLM. Les chapitres 18–20 deviennent prioritaires lors du projet Rubik's Cube ; les chapitres 21–26 t'accompagnent sur tous les projets et grands défis.

Chaque chapitre débute par ses **références classées** et contient des explications, des équations, des exemples et une question de vérification. Les figures sont illustratives/synthétiques : les références de principes apparaissent dans les légendes ; ce ne sont pas des données expérimentales publiées.

## Exécuter les scripts

```bash
python3 -m venv .venv
source .venv/bin/activate
python -m pip install -r requirements.txt
python code/regression_numpy.py
python code/bayes_prevalence.py
python code/attention_numpy.py
python code/bfs_graphe.py
python code/metriques.py
```

Le cours est autonome sur le plan de la lecture, mais ne remplace pas les ouvrages de référence P1. Aucun PDF tiers soumis à copyright n'est redistribué dans ce dossier : uniquement des URLs vers les sites officiels.

## Pour travailler ensemble dans la conversation

Donne-moi par exemple « Cours théorique, chapitre 15, attention : je ne comprends pas pourquoi la racine de d_k intervient », et nous ferons une dérivation et une expérience numérique. Un chapitre non compris n'est pas un échec : note exactement ce qui bloque et les hypothèses déjà testées.
