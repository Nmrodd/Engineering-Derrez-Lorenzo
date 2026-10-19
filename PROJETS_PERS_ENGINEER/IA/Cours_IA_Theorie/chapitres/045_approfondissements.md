# Partie VI bis — Compléments conceptuels pour aller plus loin

Ces approfondissements ne constituent **pas** de nouvelles obligations pour le premier mois. Ils répondent à des questions qui apparaîtront en construisant les projets, et évitent que des concepts structurants restent au niveau de simples définitions.

## Approfondissement A — Régularisation, convexité et stabilité numérique

**Source prioritaire :** [Mathematics for Machine Learning (R02)](https://mml-book.github.io/), chapitres *Vector Calculus* et *Continuous Optimization* ; [R01], *Linear Model Selection and Regularization*. **Source secondaire :** [R03], optimisation.

### Pourquoi le minimum de la perte n'est pas le seul objectif

L'optimisation numérique tente de minimiser une fonction de coût ; l'apprentissage vise la **performance sur des observations nouvelles**. Ces deux objectifs ne coïncident pas toujours. Un modèle très souple peut réduire presque à zéro l'erreur d'entraînement, sans apprendre une relation qui se généralise. La **régularisation** ajoute une préférence pour certaines solutions : paramètres plus petits, modèle plus simple, poids moins nombreux ou moins instables.

La **ridge regression** ajoute une pénalité quadratique $\lambda\lVert w\rVert_2^2$ à la perte :

$$\min_{w,b}\frac1n\sum_i(y_i-w^\top x_i-b)^2+\lambda\lVert w\rVert_2^2.$$

La **lasso** utilise plutôt $\lambda\lVert w\rVert_1=\lambda\sum_j|w_j|$. Dans certains contextes, elle encourage des coefficients exactement nuls, ce qui peut simplifier l'interprétation. Il ne s'agit pas d'une preuve automatique qu'une variable est causalement inutile : la sélection dépend de corrélations, de pénalisation et de données.

### Convexité et Hessienne

Une fonction $f$ est **convexe** si $f(tx+(1-t)y)\le tf(x)+(1-t)f(y)$ pour $t\in[0,1]$ ; visuellement, le segment joignant deux points du graphe reste au-dessus du graphe. Pour une fonction deux fois dérivable, une **Hessienne** positive semi-définie est un critère classique suffisant de convexité sur un domaine convexe. Une régression linéaire entraînée par MSE correspond à un problème convexe en ses poids ; un réseau de neurones profond n'a généralement pas cette structure globale simple.

La **Hessienne**, matrice des dérivées secondes, décrit la courbure locale. Une courbure très différente selon les directions peut rendre l'optimisation sensible au learning rate. Une normalisation appropriée des entrées améliore souvent le conditionnement d'un problème ; elle n'est pas un simple détail de présentation.

**Exemple.** $L(w)=(w-3)^2+\lambda w^2$. La dérivée est $2(w-3)+2\lambda w$. Le minimum est $w^*=3/(1+\lambda)$. Lorsque $\lambda$ augmente, la valeur optimale se rapproche de zéro : la régularisation a introduit une préférence mesurable, au prix d'un certain biais.

**Petit test.** Résous le même problème pour $\lambda=0$, $1$ et $9$. Explique pourquoi le plus petit coefficient n'est pas forcément celui qui minimise la MSE sur les données d'entraînement.

## Approfondissement B — PCA, clustering et apprentissage non supervisé

**Source prioritaire :** [An Introduction to Statistical Learning — Python (R01)](https://www.statlearning.com/), chapitre *Unsupervised Learning*. **Source secondaire :** [R02], *Principal Component Analysis* ; [R14], scikit-learn.

### Réduire la dimension

Lorsque chaque observation possède des dizaines ou centaines de variables, il peut être utile de construire un espace plus petit qui conserve une grande partie des variations. L'**analyse en composantes principales (PCA)** calcule des directions orthogonales maximisant successivement la variance des données projetées. Les données doivent généralement être **centrées**, et parfois mises à l'échelle lorsque les unités des variables sont différentes.

La première direction principale correspond au vecteur propre associé à la plus grande valeur propre de la matrice de covariance, dans la formulation classique. Si $X$ est centré et que $v_1$ est cette direction, la première composante est $z_1=Xv_1$. La PCA est une transformation **linéaire non supervisée** : elle ignore les étiquettes de fraude ou de sentiment. Une forte variance conservée ne signifie donc pas nécessairement que les informations utiles à une classification ont été conservées.

![Une direction principale épouse la variance dominante des points : données synthétiques. Figure originale, méthode expliquée dans [R01, R02].](figures/14_pca.png){width=82%}

### Regrouper des observations

Le **clustering** cherche des groupes selon une métrique de similarité. L'algorithme **k-means** alterne affectation des observations au centre le plus proche, puis recalcul des centres. Il minimise typiquement la somme des distances quadratiques aux centres ; son résultat dépend du nombre de clusters $k$, de l'initialisation et de la géométrie des données. Des clusters **ne sont pas** des catégories métier découvertes avec certitude.

**Application prudente à la fraude.** Un cluster d'opérations rares n'est pas automatiquement un cluster de fraudes. Une transaction légitime atypique peut être parfaitement normale. Pour une alerte, il faut un protocole de validation avec des cas labellisés ou une expertise métier.

**Exercice.** Deux colonnes représentent un montant en euros et une durée en secondes. Pourquoi faire une PCA ou un k-means sans tenir compte des échelles peut-il fausser la géométrie ? Quel diagnostic ferais-tu avant de choisir $k$ ?

## Approfondissement C — CNN, vision et segmentation

**Source prioritaire :** [Dive into Deep Learning (R03)](https://d2l.ai/), chapitres de réseaux convolutifs ; [R26], Stanford CS231n. **Source secondaire :** [R17], tutoriels modèles d'image PyTorch.

Un **réseau convolutif** (*CNN*) exploite la structure spatiale d'une image en appliquant des filtres locaux partagés à de nombreuses positions. Dans un exemple 2D simple, un noyau $3\times3$ parcourt l'image et produit, par produit local/somme, une **carte de caractéristiques**. Par convention, nombre d'implémentations de CNN calculent en réalité une **corrélation croisée** (sans retourner le noyau), souvent appelée « convolution » dans la documentation. Les **poids partagés** permettent de détecter un motif à plusieurs positions avec le même petit ensemble de coefficients.

Un **stride** supérieur à un saute certaines positions ; un **padding** ajoute des valeurs au bord pour contrôler la taille de sortie. La **dilatation** espace les coefficients d'un noyau, étendant son champ de vision sans multiplier proportionnellement le nombre de paramètres. Le **pooling** réduit parfois la résolution des activations ; ce n'est pas un composant universel de toutes les architectures modernes.

![Un filtre 3x3 se déplace sur une grille 5x5 et produit une carte de réponses ; figure originale d'après les notions de convolution [R03, R26].](figures/15_convolution.png){width=80%}

Pour la **classification**, le modèle rend un label global ; pour la **segmentation**, il étiquette les pixels ou régions. La **détection d'objets** renvoie souvent des boîtes et des scores. Ces tâches ont des métriques différentes : accuracy sur labels, IoU/Dice sur régions, mesures de précision/rappel adaptées aux objets. En imagerie satellitaire, une séparation aléatoire par pixel produirait souvent une validation trop optimiste à cause de la forte dépendance spatiale : il faut plutôt construire des splits par scènes, lieux ou périodes.

**Exemple pratique.** En Python, prends une image synthétique de 5×5 et applique un noyau de détection de bord vertical. Observe la réponse quand tu inverses le contraste ; puis vérifie qu'un filtre appris ne détecterait pas forcément la même notion hors des images de son domaine d'entraînement.

## Approfondissement D — Séries temporelles et prévision de demande

**Source prioritaire :** [An Introduction to Statistical Learning — Python (R01)](https://www.statlearning.com/), chapitres sur prédiction et validation ; [R14], modèle sélection/cross-validation. **Source secondaire :** manuel spécialisé de prévision temporelle du domaine choisi.

Une **série temporelle** est une suite d'observations ordonnées $y_t$ où le temps et les dépendances passées importent. On distingue **tendance**, **saisonnalité**, fluctuations et événements exceptionnels. Des **lags** sont des observations passées utilisées comme entrées, par exemple $y_{t-1}$ et $y_{t-24}$ pour une consommation horaire. Une **fenêtre glissante** prend plusieurs observations passées pour prédire une ou plusieurs valeurs futures.

Les splits aléatoires usuels peuvent créer une fuite temporelle : on entraînerait sur des observations futures pour évaluer des prédictions du passé. Le **backtesting** ou la validation temporelle simulent une succession de moments où seules les informations passées sont disponibles. Une prévision *one-step ahead* (une période) n'est pas la même tâche qu'une prévision 24 heures à l'avance.

Une **baseline temporelle** utile est souvent la dernière observation (*naive forecast*) ou l'observation correspondant à la même heure du jour précédent (*seasonal naive*). Pour un réseau énergétique, battre une baseline naïve sur MAE ne suffit pas ; les erreurs pendant les pics peuvent être plus importantes que la moyenne.

**Exercice.** Tu disposes de consommations horaires $y_1,\ldots,y_{200}$. Décris un test qui prédit chaque heure des indices 151 à 200 avec uniquement des informations disponibles avant l'heure prédite.

## Approfondissement E — D'une représentation à une décision sous contraintes

**Source prioritaire :** [Mathematics for Machine Learning (R02)](https://mml-book.github.io/), optimisation ; [R06], recherche et MDP ; [R24], gestion des risques. **Source secondaire :** documentation de simulation du domaine (robotique ou énergie).

Dans les grands défis, un modèle d'IA est fréquemment une pièce d'une chaîne plus large : **observer**, **estimer**, **prévoir**, **décider**, **agir**, **surveiller**. Un système énergétique peut prédire une demande future, mais la décision finale de charge/décharge dépend aussi des contraintes physiques. Formellement, on peut écrire :

$$\min_{u_1,\dots,u_T}\ \sum_{t=1}^T c_t(u_t,\widehat d_t)\quad\text{sous contraintes }g_t(u_t,s_t)\le 0.$$

Ici $\widehat d_t$ est une prédiction, $u_t$ une décision et $s_t$ l'état du système. Une solution mathématiquement optimale **pour le modèle** peut être mauvaise si les prévisions sont fausses ou si des contraintes réelles n'ont pas été modélisées. La planification robuste considère explicitement des scénarios d'incertitude ou des marges de sécurité.

En robotique, la **commande en boucle fermée** mesure l'écart entre l'état souhaité et l'état observé, puis corrige l'action ; la boucle ouverte exécute une séquence sans tenir compte des perturbations mesurées. Un simulateur peut aider à étudier la stabilité et les marges, mais les performances simulées n'équivalent pas à des essais en matériel réel.

**Exercice.** Un modèle de consommation prédit 10 kWh avec une incertitude de ±3 kWh. Pourquoi programmer une batterie pour fournir exactement 10 kWh peut-il être fragile ? Propose une contrainte de sécurité mesurable.

## Approfondissement F — Transformer minimal : trajet des dimensions

**Source prioritaire :** [Vaswani et al. — Attention Is All You Need (R20)](https://arxiv.org/abs/1706.03762), Vaswani et al. ; [R04], chapitre Transformers ; [R03], *Attention Mechanisms and Transformers*. **Niveau avancé ensuite :** [R08], Stanford CS336.

Considérons un batch de taille $B$, une longueur de séquence $T$, une dimension de représentation $d_{model}$. Après tokenisation, les identifiants ont souvent la forme $(B,T)$. Une table d'embedding les transforme en tenseur $(B,T,d_{model})$. Pour une tête d'attention de dimension $d_k$, on calcule $Q$ et $K$ de forme $(B,T,d_k)$, et $V$ de forme $(B,T,d_v)$. Les scores $QK^\top$ (transposition des deux dernières dimensions) donnent une matrice $(B,T,T)$ ; le résultat après pondération des valeurs donne $(B,T,d_v)$.

![Trajet d'une séquence dans un bloc de Transformer : dimensions explicites, schéma original d'après [R20, R04].](figures/16_transformer_flow.png){width=95%}

En multi-head attention, plusieurs têtes produisent des sorties qui sont concaténées puis projetées vers $d_{model}$. Un **bloc résiduel** ajoute la sortie d'une sous-couche à une représentation compatible en dimension : $x\mapsto x+F(x)$. La **normalisation** stabilise certaines caractéristiques de l'entraînement ; sa position exacte (pré-normalisation ou post-normalisation) dépend de l'architecture. Chaque token traverse ensuite un réseau feed-forward (*MLP*) appliqué position par position, qui peut mélanger les canaux de représentation sans mélanger directement les positions.

Pour un **decoder-only causal**, un masque interdit à une position $i$ d'utiliser directement les positions futures $j>i$. À l'entraînement, toutes les positions d'une séquence peuvent être traitées simultanément dans un passage parallèle sous ce masque ; en génération autoregressive, chaque nouveau token dépend des tokens précédemment choisis.

L'étape finale projette les représentations dans une dimension égale à la taille du vocabulaire $V$, donnant $(B,T,V)$ logits. La cross-entropy compare les logits à la séquence **décalée d'une position** pour apprendre la prédiction du prochain token.

**Exercice.** Pour $B=8$, $T=128$, $d_{model}=256$, $d_k=64$ et $V=16\,000$, donne la forme de $Q$, de la matrice des scores et des logits de sortie. Explique le rôle du masque et pourquoi l'attention ne suffit pas, seule, à tout définir de l'architecture.

