## 18. Graphe d'états, permutations et problèmes de recherche

**À lire d'abord :** [Berkeley CS188 — Introduction to AI (R06)](https://inst.eecs.berkeley.edu/~cs188/fa26/), UC Berkeley CS188 *Uninformed Search* ; [R07], Russell et Norvig, chapitre sur la résolution de problèmes. **Ensuite :** [R21], documentation du solveur en deux phases de Kociemba.

Un **état** décrit une configuration pertinente du monde ; une **action** fait passer d'un état à un autre par une **fonction de transition** $T(s,a)=s'$. L'**état initial** est le point de départ, l'**état but** satisfait une condition $G(s)=\mathrm{vrai}$. Le **graphe d'états** contient les états comme sommets et les transitions admissibles comme arêtes ; un chemin de ce graphe est une séquence d'actions.

Un Rubik's Cube n'est pas six grilles indépendantes. Son état possède des contraintes structurelles : les mouvements permutent des pièces et conservent certains invariants. Générer des couleurs de manière indépendante peut créer des configurations impossibles physiquement. Pour un mélange **garanti valide**, applique à l'état résolu une suite de rotations légales, en conservant une graine pseudoaléatoire.

### 18.1 Représenter les permutations

Une **permutation** réarrange des éléments de manière bijective. Elle possède un inverse. Une séquence $a_1,a_2,\ldots,a_k$ compose plusieurs permutations ; exécuter une rotation puis son inverse doit restaurer l'état. Dans le code, ce sont des **invariants testables** : $R\circ R^{-1}=\mathrm{id}$ et $R^4=\mathrm{id}$ pour un quart de tour de face 3×3.

### 18.2 Graphe d'états vs arbre de recherche

Le même état peut être accessible par plusieurs suites de mouvements. Un **arbre de recherche** développe des chemins possibles, éventuellement redondants ; un **graphe** reconnaît que plusieurs chemins peuvent pointer vers le même état. Mémoriser les états visités évite certaines répétitions, mais coûte de la mémoire. Le **branching factor** $b$ représente un nombre moyen d'actions possibles par étape ; explorer jusqu'à profondeur $d$ peut demander de l'ordre de $b^d$ nœuds dans le pire cas, ce qui explique l'explosion combinatoire.

![Arbre de recherche partiel : états illustratifs, sans prétention de représenter tout le cube. Figure originale ; cours Berkeley CS188 [R06].](figures/12_search_tree.png){width=84%}

**Exercice.** Avec 12 actions possibles par état et une profondeur de 5, calcule $12^5$. Pourquoi le nombre d'états distincts explorés peut-il être plus faible que le nombre de chemins ?

## 19. BFS, DFS, IDDFS, A* et heuristiques

**À lire d'abord :** [Berkeley CS188 — Introduction to AI (R06)](https://inst.eecs.berkeley.edu/~cs188/fa26/), cours *Uninformed Search* et *A* Search and Heuristics* ; [R07], *Informed Search*. **Ensuite :** [R21], algorithme Kociemba.

**BFS** (*breadth-first search*) explore les profondeurs successives. Dans un graphe non pondéré, il trouve un plus court chemin en nombre d'arêtes si les conditions habituelles sont satisfaites, mais consomme beaucoup de mémoire. **DFS** explore une branche avant de revenir ; il peut parcourir peu de mémoire par profondeur mais ne garantit pas un chemin minimal et peut ne pas terminer sur certains espaces infinis. **IDDFS** recommence une DFS avec des limites de profondeur croissantes : il échange des répétitions de calcul contre une meilleure empreinte mémoire.

### 19.1 La fonction d'évaluation de A*

**A*** classe les nœuds selon $f(n)=g(n)+h(n)$ : $g$ est le coût déjà parcouru, $h$ une estimation du coût restant. Une heuristique **admissible** ne surestime jamais le coût optimal restant ; dans les conditions classiques d'A* et avec gestion appropriée des doublons, cela aide à garantir l'optimalité. Une heuristique trop faible explore beaucoup d'états ; une heuristique trop optimiste au mauvais sens (qui surestime) peut compromettre l'optimalité.

### 19.2 IDA* et réduction de l'espace

**IDA*** (iterative deepening A*) effectue des recherches successives avec des limites sur $f$ plutôt que sur la profondeur seule. Les **pruning rules** éliminent des branches qui ne peuvent pas être utiles, par exemple des rotations inverses immédiatement consécutives. Une **pattern database** pré-calcule des coûts exacts pour une projection simplifiée de l'état, utilisée comme heuristique. La méthode de **Kociemba** réduit le cube en deux phases via des groupes d'états particuliers ; elle n'assure pas systématiquement un nombre minimal absolu de mouvements.

**Différence scientifique essentielle :** résoudre un cube avec une heuristique construite par raisonnement n'implique aucun entraînement. Si tu apprends une heuristique à partir de données, tu ajoutes alors un composant de ML à l'algorithme de recherche.

**Exercice.** Sur un graphe à poids uniformes, compare BFS et DFS si une solution courte existe mais qu'une branche très longue précède cette solution. Quel algorithme privilégierais-tu si la mémoire est très contrainte ?

## 20. Apprentissage par renforcement : extension, pas raccourci

**À lire d'abord :** [Sutton & Barto — Reinforcement Learning (R22)](http://incompleteideas.net/book/the-book-2nd.html), Sutton et Barto, chapitres d'introduction à l'apprentissage par renforcement ; [R06], cours Berkeley sur MDP et fonctions de valeur. **Ensuite :** [R23], *Deep RL Course* de Hugging Face.

Un **processus décisionnel de Markov** (MDP) formalise états $S$, actions $A$, transitions $P(s'\mid s,a)$, récompenses $r$ et facteur d'actualisation $\gamma\in[0,1]$. La **politique** $\pi(a\mid s)$ spécifie comment l'agent choisit ses actions. L'objectif est d'optimiser le retour attendu $G_t=\sum_{k\ge0}\gamma^kr_{t+k+1}$. La fonction **valeur** $V^\pi(s)$ estime le retour depuis un état sous une politique ; $Q^\pi(s,a)$ ajoute l'action initiale.

La **relation de Bellman** exprime une valeur en fonction d'une récompense immédiate et de valeurs futures. Dans le **Q-learning**, une mise à jour tabulaire classique est :

$$Q(s,a)\leftarrow Q(s,a)+\alpha\left[r+\gamma\max_{a'}Q(s',a')-Q(s,a)\right].$$

L'agent doit arbitrer entre **exploration** (tester des actions peu connues) et **exploitation** (choisir la meilleure action estimée). Ce cadre pourrait théoriquement servir à chercher des stratégies de cube, mais un 3×3 complet présente un espace d'états gigantesque. Pour un premier projet RL, commence par une grille ou un cube 2×2 simplifié avec une profondeur de mélange limitée.

**Exercice.** Avec $Q=2$, récompense $r=1$, $\gamma=0{,}9$, $\max Q(s',\cdot)=4$ et $\alpha=0{,}1$, effectue une mise à jour Q-learning. Pourquoi un mauvais design de la récompense peut-il apprendre un comportement indésirable ?

# Partie VI — Fiabilité, ingénierie et grands défis

## 21. Ingénierie expérimentale et reproductibilité

**À lire d'abord :** [scikit-learn — Common Pitfalls (R15)](https://scikit-learn.org/stable/common_pitfalls.html), scikit-learn *Common Pitfalls* ; [R17], PyTorch *Save/Load*. **Ensuite :** [R24], NIST AI RMF (cadre de gestion des risques).

Un prototype d'IA sérieux ne se réduit pas à `model.fit()`. Il doit préciser : la question scientifique, le protocole, la provenance des données, les unités, les hypothèses, les métriques, le matériel, les versions logicielles, les seeds et la méthode de comparaison. Une **baseline** donne un point de départ. Une **ablation study** supprime ou modifie un composant afin d'estimer son rôle ; elle doit conserver autant que possible les autres facteurs constants.

### 21.1 La fiche d'expérience

Rédige avant d'exécuter : « Hypothèse H1 : ajouter une variable d'historique améliore le rappel à précision fixée ». Ensuite, renseigne : jeu de données, split, variables disponibles en situation réelle, modèle, hyperparamètres, métriques, résultat, intervalle de variabilité ou répétitions, conclusion et suite. Cette habitude réduit les expériences opportunistes où l'on change simultanément données, paramètres et méthode d'évaluation.

### 21.2 Traçabilité du code

Utilise Git pour les changements de code, un environnement Python documenté, des tests unitaires pour les transformations de données, des tests d'intégration pour le pipeline, et des **tests de données** (colonnes requises, types, valeurs impossibles). Un README devrait permettre à un autre étudiant de réexécuter l'expérience. Lorsqu'un dataset possède une licence, respecte ses restrictions ; ne pousse pas de données confidentielles sur GitHub. Le notebook est pratique pour explorer, mais le code réutilisable gagne à être déplacé vers un module Python testé.

### 21.3 Mesurer l'incertitude des résultats

Un score observé est une réalisation dépendant du dataset, du tirage aléatoire et du protocole. Répéter certaines expériences avec différentes seeds et fournir des intervalles est plus informatif que d'annoncer trois décimales sur un petit test. Attention : les données temporelles, les groupes et les dépendances rendent certaines procédures de bootstrap ou de CV invalides si elles sont appliquées sans réflexion.

**Exercice.** Ton nouveau modèle gagne deux points de F1 sur un seul split aléatoire. Quels contrôles exigerais-tu avant d'écrire « amélioration confirmée » ?

## 22. Données réelles, déséquilibre, temps et changement de distribution

**À lire d'abord :** [An Introduction to Statistical Learning — Python (R01)](https://www.statlearning.com/), validation et évaluation ; [R15], problèmes de fuite ; [R24], management des risques. **Ensuite :** documentation spécialisée de ton domaine (énergie, banque, satellite).

Dans le monde industriel, la difficulté principale n'est pas toujours l'architecture du modèle. Les labels peuvent être retardés, bruités ou incomplets ; les populations changent ; les capteurs tombent en panne ; les coûts d'erreur varient. On distingue couramment un **covariate shift** (distribution des entrées $P(X)$ modifiée), un **label shift** ($P(Y)$ modifié dans certaines hypothèses) et un **concept drift** (relation entre entrées et sortie qui évolue). Ces étiquettes décrivent des cas théoriques distincts, pas toujours observables directement.

![Une relation prédictive qui change au fil du temps : série entièrement simulée, illustrant un concept drift. Références [R01, R24].](figures/13_drift.png){width=85%}

Un système d'alerte doit aussi gérer le **déséquilibre des classes** : une très petite proportion de fraudes, pannes ou incidents peut rendre l'accuracy peu informative. La présence d'un dataset synthétique est une aide pédagogique, pas une validation dans un contexte bancaire réel. Les métriques doivent être reliées à des conséquences : perte financière, délai de réponse, précision de localisation, énergie consommée, etc.

**Exercice.** Établis trois différences entre un benchmark offline et un service utilisé en continu. Que dois-tu contrôler si la proportion de fraude double six mois après l'entraînement ?

## 23. RAG, évaluation des assistants et cybersécurité des systèmes d'IA

**À lire d'abord :** [Hugging Face — LLM Course (R19)](https://huggingface.co/learn/llm-course/en/chapter1/1), cours Hugging Face pour modèles ; [R24], NIST AI RMF ; [R25], OWASP Top 10 for LLM Applications. **Ensuite :** [R08], Stanford CS336 (pour les fondements du modèle lui-même).

Un système **RAG** suit en général : collecte documentaire $\to$ découpage (*chunking*) $\to$ représentation/recherche $\to$ sélection de passages $\to$ génération avec contexte. Son évaluation sépare deux problèmes : **retrieval quality** (les bons documents sont-ils retrouvés ?) et **answer quality** (la réponse s'appuie-t-elle correctement sur ces documents ?). Mesures utiles : Recall@k sur documents attendus, précision des citations, taux d'abstention appropriée, taux de réponses non justifiées et temps de réponse.

Le **prompt injection** correspond à des instructions malveillantes placées dans du contenu non fiable, par exemple un document récupéré ou une page Web, pour détourner le comportement du système. Les documents doivent être traités comme **données**, jamais comme des directives de confiance équivalentes à celles de l'utilisateur et de l'application. Des politiques d'accès aux sources, la séparation des privilèges, les validations des actions externes et les tests adversariaux sont nécessaires.

**Projet ambitieux mais mesurable :** un assistant scientifique qui répond seulement à partir d'un corpus autorisé, cite les passages exacts, indique son incertitude et s'abstient si aucune preuve pertinente n'est présente. Un démonstrateur convaincant pourrait tester 100 questions réparties entre questions répondables, ambiguës et sans réponse. Il faudrait auditer les citations à la main sur un échantillon.

**Exercice.** Pourquoi une réponse avec cinq citations peut-elle malgré tout être fausse ? Conçois un protocole pour mesurer la proportion de citations réellement justificatives.

## 24. Robotique, énergie et vision : quelles théories avant un grand défi ?

**À lire d'abord :** spécialité choisie, documentation officielle et cours ciblés ; **ne cherche pas** à tout assimiler avant de produire une première simulation. Pour la robotique : [Berkeley CS188 — Introduction to AI (R06)](https://inst.eecs.berkeley.edu/~cs188/fa26/) pour planification, [R22] pour RL ; pour la vision : [R26], Stanford CS231n ; pour l'industrialisation : [R24].

### 24.1 Robots et contrôle

Un robot ajoute au ML une **dynamique physique** : l'état peut inclure position, vitesse, attitude et énergie disponible. Un **contrôleur** transforme un écart de consigne en actions, avec stabilité et contraintes. Un véhicule à décollage vertical hybride ne se résume pas à une IA qui « pilote » ; il exige la modélisation des forces, la gestion des transitions, des capteurs, des actionneurs et de nombreuses questions de sûreté. Une **simulation** constitue une première étape sûre et vérifiable ; elle ne prouve pas une aptitude au vol réel.

### 24.2 Énergie et prévision

Pour un micro-réseau, prédire une demande $d_t$ est distinct d'**optimiser** une décision de production et de stockage $u_t$ sous contraintes. L'optimisation peut chercher à minimiser le coût $\sum_tc_t(u_t)$ tout en respectant des contraintes comme l'état de charge d'une batterie, la puissance maximale ou la continuité de service. La performance n'est pas seulement une erreur prédictive : elle inclut coût, résilience et violations de contraintes.

### 24.3 Satellites et vision

Une image satellite combine données spatiales, canaux spectraux et métadonnées géographiques. Un modèle de segmentation produit une catégorie pour chaque pixel ; un **IoU** (*intersection over union*) vaut $|A\cap B|/|A\cup B|$ pour comparer une région prédite $A$ à une vérité terrain $B$. Attention aux différences d'illumination, de saison, de résolution, de couverture nuageuse et de localisation entre train et test. Une belle carte de prédiction n'est pas une validation scientifique.

**Exercice.** Pour chacun des trois domaines, propose une métrique de réussite, une contrainte de sécurité et une limite qu'un prototype purement logiciel ne permettra pas de lever.

## 25. Risques, limites et responsabilité de l'ingénieur IA

**À lire d'abord :** [NIST — AI Risk Management Framework (R24)](https://www.nist.gov/itl/ai-risk-management-framework), NIST AI RMF ; [R15], pièges expérimentaux ; [R25], sécurité des applications LLM. **Ensuite :** obligations légales et réglementaires applicables au pays, au contexte et au système concerné.

La **robustesse** décrit la sensibilité aux perturbations ; la **fiabilité** demande de tenir les performances dans le contexte attendu ; l'**équité** interroge les écarts de performance et de traitement selon des populations pertinentes ; la **confidentialité** concerne les données et informations potentiellement exposées ; l'**explicabilité** cherche des raisons interprétables des prédictions. Aucune de ces propriétés n'est automatiquement garantie par un score de précision élevé.

Le cadre NIST AI RMF 1.0 propose notamment les fonctions **Govern, Map, Measure, Manage**. Il s'agit d'un cadre de gestion des risques, pas d'une certification automatique. Pour un projet étudiant, retiens trois réflexes : documenter les populations et situations non couvertes, expliciter les coûts des erreurs, établir un processus de correction et de retrait du modèle si les résultats se détériorent.

**Cas limites :** un outil de détection de fraude peut bloquer des usagers légitimes ; un détecteur satellitaire peut ignorer certaines régions ; un assistant scientifique peut inventer une référence ; un robot peut échouer hors des conditions simulées. Le but n'est pas d'interdire la recherche, mais de rendre ses limites visibles et ses expériences honnêtes.

**Exercice.** Rédige une « model card » de dix lignes pour ton classificateur de fraude : tâche, données, population couverte, mesure, limites, risques et utilisation déconseillée.

## 26. Traduire la science en gestion de projet et leadership

**À lire d'abord :** [The Scrum Guide (R27)](https://scrumguides.org/), *The Scrum Guide* pour la terminologie produit et cycles ; [R24], cadre de risques NIST pour la gouvernance technique. **Ensuite :** [R28], *The Manager's Path* (ouvrage payant, facultatif).

Un responsable technique ne doit pas seulement écrire du code. Il doit clarifier le **problème** avant la solution, identifier les parties prenantes, expliciter le **périmètre**, définir des résultats mesurables et communiquer les incertitudes. Un *backlog* liste les éléments de travail ; un *milestone* est un jalon vérifiable ; un *risk register* rassemble risque, probabilité, impact et mitigation ; une *decision record* explique pourquoi une architecture a été choisie et avec quelles alternatives.

### 26.1 La note de cadrage en six questions

1. Quel problème utilisateur ou scientifique veut-on résoudre ? 2. Quelle preuve montrerait que le prototype progresse ? 3. Quelles contraintes de temps, données, sécurité et coût s'imposent ? 4. Quels sont les principaux risques ? 5. Quel livrable démontrable peut-on produire dans un mois ? 6. Quel signal nous dirait qu'il faut arrêter ou changer d'approche ?

### 26.2 Rituels compatibles avec tes études

- **Début de semaine (10 min)** : un objectif, une hypothèse, un résultat attendu.
- **Après une expérience** : entrée de journal avec ce qui a marché et échoué.
- **Fin de semaine (20 min)** : démonstration du programme, métriques, blocages, prochaine priorité.
- **Fin de mois (45 min)** : *review* du résultat, *retrospective* sur ta manière de travailler, décision de poursuite ou bifurcation.

Les « soft skills » ne se valident pas en lisant une théorie sur le leadership : entraîner-toi à présenter un compromis à un camarade, à expliquer une limitation sans jargon et à faire relire ton protocole. Être chef de projet n'est pas équivalent à être le meilleur programmeur ; c'est en partie **rendre les décisions collectives claires et les risques maîtrisables**.

**Exercice.** Rédige une décision d'architecture : « TF–IDF + régression logistique ou Transformer pré-entraîné pour classifier des avis ? » Compare données, calcul, métriques, maintenance, licences et délai.

# Partie VII — Exercices de synthèse et corrigés

