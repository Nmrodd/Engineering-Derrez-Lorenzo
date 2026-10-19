#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
cat chapitres/00_avant_propos.md chapitres/01_maths.md chapitres/02_ml.md chapitres/03_dl.md chapitres/04_search_engineering.md chapitres/045_approfondissements.md chapitres/05_exercises_sources.md > Cours_theorique_IA.md
python3 code/generer_figures.py
python3 code/generer_figures_complements.py
pandoc Cours_theorique_IA.md --from markdown+tex_math_dollars+fenced_code_attributes \
  --metadata-file=config/metadata.yaml --include-in-header=config/header.tex \
  --pdf-engine=xelatex --top-level-division=chapter --toc --toc-depth=2 \
  --highlight-style=tango -o Cours_theorique_IA.pdf
python3 code/creer_couverture_pdf.py
