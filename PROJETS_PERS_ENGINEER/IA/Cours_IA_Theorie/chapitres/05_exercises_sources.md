## 27. Exercices corrigés, de la définition au calcul

Les exercices ci-dessous ne dispensent pas de coder : ils contrôlent surtout la cohérence des raisonnements. Pour chaque question, essaie de répondre **avant** de lire la correction, puis mets en œuvre un test Python.

### Exercice A — Dimensions d'une couche

**Question.** Un lot contient 64 observations, chacune avec 12 variables. Une couche linéaire produit 7 sorties. Quelle est la forme des poids et combien de paramètres possède-t-elle ?

**Correction.** Avec la convention PyTorch `Linear(in_features=12, out_features=7)`, la matrice des poids est de forme $(7,12)$ ; il y a $84$ poids et $7$ biais, soit **91 paramètres**. La sortie sur le lot a la forme $(64,7)$. Un écart entre ces dimensions indique une erreur dans le modèle ou la représentation des données.

### Exercice B — Une mise à jour de descente de gradient

**Question.** $L(w)=(w-5)^2$, $w_0=1$, $\eta=0{,}2$. Calcule $w_1$ et les deux pertes.

**Correction.** $L'(w)=2(w-5)$, donc $L'(1)=-8$ ; $w_1=1-0{,}2(-8)=2{,}6$. $L(w_0)=16$ et $L(w_1)=5{,}76$. Attention, un pas plus grand ne garantit pas toujours une descente ; teste $\eta=1{,}2$.

### Exercice C — Probabilités conditionnelles et fraude rare

**Question.** Une fraude apparaît dans 0,1 % des opérations, la sensibilité est 90 %, le taux de faux positifs 5 %. Quelle est la précision approximative ?

**Correction.** Sur 100 000 transactions, il y a 100 fraudes dont 90 détectées et 99 900 transactions légitimes dont 4 995 faussement signalées. Précision $=90/(90+4\,995)\approx1{,}77\%$. Le changement de prévalence transforme radicalement l'intérêt opérationnel du détecteur sans changer ses propriétés conditionnelles supposées.

### Exercice D — Classification et F1

**Question.** TP=18, FP=6, FN=12, TN=164. Calcule précision, rappel et F1.

**Correction.** Précision $18/24=0{,}75$, rappel $18/30=0{,}6$, F1 $=2(0{,}75)(0{,}6)/(1{,}35)=2/3\approx0{,}667$. L'accuracy vaut $182/200=0{,}91$ et cache une capacité limitée à détecter la classe positive.

### Exercice E — Dérivation en chaîne

**Question.** $L(w)=(2w-3)^2$. Calcule la dérivée et sa valeur en $w=1$.

**Correction.** Avec $u(w)=2w-3$, $L'=2u\,u'=4(2w-3)$. Donc $L'(1)=-4$. Vérification numérique : pour $h$ petit, $[L(1+h)-L(1-h)]/(2h)\approx-4$.

### Exercice F — Normalisation et fuite

**Question.** Tu veux normaliser une variable avec moyenne $\mu$ et écart-type $\sigma$. Tu calcules $\mu,\sigma$ sur l'ensemble train + test. Pourquoi est-ce problématique ?

**Correction.** Tu as utilisé une information statistique provenant du test pour construire la transformation, donc ton protocole ne reproduit plus une prédiction sur données réellement nouvelles. Ajuste $\mu,\sigma$ uniquement sur train, puis applique cette transformation inchangée à validation/test. Utilise un `Pipeline` si possible.

### Exercice G — Softmax sur deux scores

**Question.** Pour les logits $(0,\ln 3)$, calcule les probabilités softmax.

**Correction.** $e^0=1$, $e^{\ln3}=3$, donc $p=(1/4,3/4)=(0{,}25,0{,}75)$. La softmax renormalise les exponentielles, elle n'« ajoute » pas de probabilités prédéfinies aux logits.

### Exercice H — Nombre de paramètres d'un réseau

**Question.** Réseau dense $10\to16\to16\to2$, avec biais par couche.

**Correction.** Première couche : $10\times16+16=176$ ; deuxième : $16\times16+16=272$ ; sortie : $16\times2+2=34$. Total : **482 paramètres**.

### Exercice I — Matrice d'attention

**Question.** Combien de coefficients une tête d'attention dense calcule-t-elle pour une séquence de 128 tokens ? Et de 256 ?

**Correction.** $128^2=16\,384$, puis $256^2=65\,536$ coefficients. Le doublement de longueur multiplie cette partie par **4**. Les masques et optimisations modifient la manière de calculer ou stocker l'opération, pas les dépendances conceptuelles de la formule dense.

### Exercice J — Perplexité

**Question.** Un modèle attribue 0,8 puis 0,2 aux deux tokens cibles. Quelle est la perte moyenne en log naturel ?

**Correction.** $-\frac12(\ln0{,}8+\ln0{,}2)\approx0{,}9163$. Perplexité : $e^{0{,}9163}\approx2{,}5$. Ce chiffre dépend fortement du problème et des unités de tokenisation.

### Exercice K — Coût combinatoire d'une recherche

**Question.** Une recherche possède 12 actions par état et explore jusqu'à profondeur 5. Nombre approximatif de feuilles sans pruning ?

**Correction.** $12^5=248\,832$ feuilles, auxquels s'ajoutent les nœuds intermédiaires. La mémorisation d'états déjà vus et l'élimination de mouvements inverses peuvent réduire le nombre de branches réellement explorées.

### Exercice L — Q-learning

**Question.** $Q=2$, $r=1$, $\gamma=0{,}9$, $\max Q'=4$, $\alpha=0{,}1$. Nouvelle valeur ?

**Correction.** La cible temporelle est $1+0{,}9\times4=4{,}6$ ; l'erreur est $4{,}6-2=2{,}6$. Mise à jour $Q_{new}=2+0{,}1\times2{,}6=2{,}26$.

### Exercice M — Architecture et usage

**Question.** Pourquoi ne faut-il pas appliquer manuellement softmax aux logits avant `nn.CrossEntropyLoss` dans PyTorch ?

**Correction.** Cette fonction attend des **logits bruts** et combine numériquement `log_softmax` et negative log-likelihood de manière stable. Lui donner déjà des probabilités transforme l'entrée, change la fonction optimisée et peut dégrader l'apprentissage. Le piège est vérifiable en lisant [R17] et la référence officielle `nn.CrossEntropyLoss`.

### Exercice N — Recherche de source fiable

**Question.** Un assistant documentaire produit une phrase exacte, mais cite un passage qui ne la contient pas. Est-ce un échec de la réponse ?

**Correction.** C'est au minimum un échec de **traçabilité/citation**. La réponse peut être vraie pour d'autres raisons, mais elle n'est pas justifiée par la source indiquée. On doit donc séparer *answer correctness*, *citation support* et *retrieval completeness* dans les métriques.

### Exercice O — Différence entre projet et preuve scientifique

**Question.** Ton Rubik's Cube solveur a résolu 20 mélanges de 3 mouvements. Peut-on écrire « il résout n'importe quel cube 3×3 » ?

**Correction.** Non. Le domaine testé se limite à une famille restreinte de configurations. Il faut documenter profondeurs, méthode de tirage, états effectivement atteints, temps limites et taux de réussite. L'assertion devrait être : « sur ces 20 mélanges de profondeur 3 générés selon cette méthode, 20 ont été résolus ».

## 28. Fiches de synthèse : ce que tu dois savoir expliquer sans notes

| Notion | Niveau minimal attendu | Expérience discriminante |
|:---|:---|:---|
| Produit matriciel | Calculer les dimensions de sortie | Provoquer une erreur de dimension et la corriger |
| Gradient | Relier dérivée, sens de variation, pas | Faire diverger une parabole avec un grand pas |
| Bayes | Distinguer sensibilité et valeur prédictive | Varier la prévalence |
| Modèle supervisé | Définir X, y, paramètres, loss | Entraîner une baseline |
| Généralisation | Justifier train/validation/test | Observer l'effet du leakage |
| Précision / rappel | Calculer à partir des TP/FP/FN | Déplacer un seuil |
| Réseau neuronal | Compter paramètres et activations | Supprimer la non-linéarité |
| Backprop | Expliquer la chaîne de gradients | Inspecter `.grad` dans PyTorch |
| PyTorch | Suivre forward/loss/backward/step | Retirer `zero_grad()` et observer |
| TF–IDF | Expliquer la pondération des mots | Comparer unigrammes et bigrammes |
| Embeddings | Expliquer espace vectoriel et contexte | Mesurer cosinus sur petits vecteurs |
| Attention | Expliquer $QK^T$, softmax et $V$ | Faire une attention à deux tokens |
| LLM | Décrire le prochain-token et sampling | Générer avec un bigram |
| A* / IDA* | Justifier coûts, heuristique et mémoire | Comparer à BFS sur graphe simple |
| RL | Décrire politique, récompense, valeur | Effectuer une mise à jour Q-learning |
| Fiabilité | Distinguer score et déploiement | Simuler drift ou fuite |

## 29. Sources complètes et ordre de lecture

**Méthode de référencement.** Les identifiants [Rxx] apparaissent au début de chaque chapitre et dans les légendes des figures. Les URLs renvoient aux pages **officielles** de l'éditeur, des auteurs ou des projets. Les ressources payantes ne sont pas copiées dans l'archive. Les chapitres de ce document sont rédigés spécifiquement pour ton parcours et reformulent les notions ; les figures sont originales. Vérification des pages de référence : octobre 2026.

**[R01] PRIORITÉ 1 — James, Witten, Hastie, Tibshirani et Taylor.** *An Introduction to Statistical Learning, with Applications in Python*, Springer (2023). Page officielle avec PDF en accès libre, labs et ressources : <https://www.statlearning.com/>. **Lire en premier :** introduction, régression, classification, validation. Puis arbres et SVM pour le projet Fraude.

**[R02] PRIORITÉ 1 — Deisenroth, Faisal et Ong.** *Mathematics for Machine Learning*, Cambridge University Press (2020). Site officiel des auteurs avec PDF disponible gratuitement : <https://mml-book.github.io/>. **Cibler :** algèbre linéaire, calcul vectoriel, probabilités et optimisation ; il n'est pas nécessaire de lire tous les chapitres d'affilée.

**[R03] PRIORITÉ 1 — Zhang, Lipton, Li et Smola.** *Dive into Deep Learning*, livre ouvert, mathématiques + notebooks : <https://d2l.ai/>. **Cibler :** régression, MLP, backpropagation, attention. L'ouvrage est exécutable et convient à une progression théorie–code.

**[R04] PRIORITÉ 1 POUR NLP/LLM — Jurafsky et Martin.** *Speech and Language Processing* (3e éd., manuscrit en évolution, diffusion du 19 août 2026). <https://web.stanford.edu/~jurafsky/slp3/>. **Cibler :** introduction, tokens, n-grams, classification et Transformers. Le manuscrit n'est pas une édition finale stabilisée ; vérifie toujours le chapitre de la version consultée.

**[R05] PRIORITÉ 2 — Simon J. D. Prince.** *Understanding Deep Learning* (2023). Site de l'auteur : <https://udlbook.com/>. **Utiliser :** explications détaillées de l'optimisation, architectures et théorie après une première approche [R03]. Ne pas tenter de lire l'intégralité en quatre semaines.

**[R06] PRIORITÉ 1 POUR RUBIK — UC Berkeley.** *CS188: Introduction to Artificial Intelligence*, supports de cours (Fall 2026) : <https://inst.eecs.berkeley.edu/~cs188/fa26/>. **Cibler :** recherche non informée, A*, heuristiques, MDP. Supports de cours, pas certification autonome.

**[R07] PRIORITÉ 2 — Russell et Norvig.** *Artificial Intelligence: A Modern Approach*, Pearson, 4e édition (livre commercial). <https://aima.cs.berkeley.edu/>. **Utiliser :** cadre général de recherche, agents et planification ; source de fond, pas achat obligatoire.

**[R08] PRIORITÉ 3 — Stanford.** *CS336: Language Modeling from Scratch*, Spring 2026 : <https://cs336.stanford.edu/>. **À réserver :** phase LLM avancée après PyTorch et attention. Supports et exercices de niveau universitaire exigeant.

**[R09] PRIORITÉ 1 POUR PYTHON SCIENTIFIQUE — NumPy.** Guide officiel débutant : <https://numpy.org/doc/stable/user/absolute_beginners.html>.

**[R10] PRIORITÉ 1 — Google.** *Machine Learning Crash Course*, cours gratuit sur régression, classification et descente de gradient : <https://developers.google.com/machine-learning/crash-course>.

**[R11] PRIORITÉ 1 POUR MÉTRIQUES — scikit-learn.** *Model Evaluation*: <https://scikit-learn.org/stable/modules/model_evaluation.html>.

**[R12] PRIORITÉ 1 — pandas.** *Getting started tutorials*: <https://pandas.pydata.org/docs/getting_started/intro_tutorials/>.

**[R13] PRIORITÉ 2 — Matplotlib.** Documentation et galeries officielles : <https://matplotlib.org/stable/tutorials/index.html>.

**[R14] PRIORITÉ 1 POUR MODÈLES CLASSIQUES — scikit-learn.** Documentation officielle : <https://scikit-learn.org/stable/supervised_learning.html>.

**[R15] PRIORITÉ 1 POUR LE PROTOCOLE — scikit-learn.** *Common pitfalls and recommended practices* : <https://scikit-learn.org/stable/common_pitfalls.html>.

**[R16] PRIORITÉ 2 — scikit-learn.** *Precision-Recall*: <https://scikit-learn.org/stable/auto_examples/model_selection/plot_precision_recall.html>.

**[R17] PRIORITÉ 1 POUR DEEP LEARNING PRATIQUE — PyTorch.** *Learn the Basics* : <https://docs.pytorch.org/tutorials/beginner/basics/intro.html>.

**[R18] PRIORITÉ 1 POUR NLP CLASSIQUE — scikit-learn.** *Working with Text Data* : <https://scikit-learn.org/stable/tutorial/text_analytics/working_with_text_data.html>.

**[R19] PRIORITÉ 1 POUR OUTILS NLP/LLM — Hugging Face.** *LLM Course* : <https://huggingface.co/learn/llm-course/en/chapter1/1>. Familiarité préalable avec Python nécessaire.

**[R20] ARTICLE FONDATEUR — Vaswani et al.** *Attention Is All You Need*, NeurIPS 2017 : <https://arxiv.org/abs/1706.03762>. Lire sections 3.1–3.2 après les chapitres sur matrices et softmax.

**[R21] RÉFÉRENCE TECHNIQUE CUBE — Herbert Kociemba.** *The Two-Phase Algorithm* : <https://www.kociemba.org/twophase.htm>.

**[R22] PRIORITÉ 2 POUR RL — Sutton et Barto.** *Reinforcement Learning: An Introduction*, 2e édition (2018), page académique : <http://incompleteideas.net/book/the-book-2nd.html>.

**[R23] PRIORITÉ 3 — Hugging Face.** *Deep Reinforcement Learning Course* : <https://huggingface.co/learn/deep-rl-course/unit0/introduction>.

**[R24] PRIORITÉ 1 POUR RISQUES — NIST.** *AI Risk Management Framework 1.0* et ressources : <https://www.nist.gov/itl/ai-risk-management-framework>. Ce document est un cadre volontaire et peut connaître des révisions ; vérifier la version consultée.

**[R25] PRIORITÉ 2 POUR SÉCURITÉ LLM — OWASP.** *OWASP Top 10 for LLM Applications* : <https://genai.owasp.org/llm-top-10/>. Document de risque, non certificat de conformité.

**[R26] PRIORITÉ 2 POUR VISION — Stanford.** *CS231n: Deep Learning for Computer Vision* : <https://cs231n.stanford.edu/>.

**[R27] PRIORITÉ 2 POUR ORGANISATION — Schwaber et Sutherland.** *The Scrum Guide* (édition officielle) : <https://scrumguides.org/>. Cadre de processus, pas unique bonne manière de travailler.

**[R28] FACULTATIF — Camille Fournier.** *The Manager's Path* (O'Reilly, ouvrage commercial, 2017) : <https://www.oreilly.com/library/view/the-managers-path/9781491973882/>.

## 30. Feuille de lecture progressive : quoi ouvrir, et quand ?

| Moment | Une seule source prioritaire | Complément éventuel | Production attendue |
|:---|:---|:---|:---|
| Mois 1, S1 | [R02] notions mathématiques ciblées | [R09, R12] | Vecteurs, matrices, stats en code |
| Mois 1, S2 | [R01] régression/classification | [R10] | Descente de gradient sans ML library |
| Mois 1, S3 | [R03] perceptrons et backprop | [R17] | MLP PyTorch entraîné |
| Mois 1, S4 | [R11] métriques + [R04] tokens | [R19] | Fiche NLP/évaluation |
| Mois 2, Fraude | [R01] classification/arbres | [R15, R11] | Baseline, seuils, bilan d'erreurs |
| Mois 3, Avis | [R18] TF–IDF et classification | [R04] | Catégorie + sentiment |
| Mois 4, Cube | [R06] graphes, A*, heuristiques | [R21] | Solveur court + benchmark |
| Mois 5 optionnel | [R04] Transformers + [R19] | [R20, R08] | Petit LM et évaluation |
| Grand défi | Source technique du domaine choisie | [R24, R25, R26] | Revue de littérature + MVP mesuré |

**Règle pratique :** ne poursuis pas simultanément cinq ressources. Prends le **cours français présent**, la **source P1** du chapitre et, si une formule résiste, une ressource complémentaire. Note systématiquement ce que tu comprends *grâce* à la source et ce qui reste à tester.

