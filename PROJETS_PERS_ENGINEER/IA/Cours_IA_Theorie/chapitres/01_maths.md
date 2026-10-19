## 1. Vecteurs, matrices, tenseurs : le langage des données

**À lire d'abord :** [Mathematics for Machine Learning (R02)](https://mml-book.github.io/), chap. *Linear Algebra* ; [R09], *NumPy absolute basics*. **Ensuite :** [R03], chapitre sur les manipulations de données. **Prérequis :** opérations sur les réels et fonctions usuelles.

### 1.1 Du tableau Excel à l'espace vectoriel

Une **observation** peut être représentée par un vecteur $x\in\mathbb{R}^d$. Dans un problème de fraude, $x=(\text{montant},\text{heure},\text{ancienneté})$ peut représenter trois variables numériques. Pour $n$ observations, on empile les lignes dans une **matrice de données** $X\in\mathbb{R}^{n\times d}$. La notation $X_{ij}$ représente la valeur de la variable $j$ pour l'observation $i$. Un **scalaire** est un nombre, un **vecteur** est une collection ordonnée, une **matrice** possède deux axes, un **tenseur** généralise cette représentation à plusieurs dimensions. En programmation, « tenseur » désigne souvent un tableau multidimensionnel ; en géométrie différentielle, le mot possède un sens plus profond que nous ne mobilisons pas ici.

**Intuition :** chaque observation est un point dans un espace de $d$ dimensions. Un modèle cherche des régularités dans la position de ces points. Une image RGB de $32\times32$ pixels peut être vue comme un tableau $32\times32\times3$ ; un lot de 64 images devient $64\times32\times32\times3$ selon la convention d'axes utilisée.

### 1.2 Produit scalaire et produit matriciel

Pour deux vecteurs $u,v\in\mathbb R^d$, $u\cdot v=\sum_{j=1}^{d}u_jv_j$. Le produit scalaire mêle la longueur des vecteurs à leur orientation ; sous normalisation, il est relié à la similarité cosinus. Un modèle linéaire calcule $\hat y = w^\top x+b$. Pour traiter $n$ lignes simultanément : $\hat y=Xw+b\mathbf1$, avec $X\in\mathbb R^{n\times d}$ et $w\in\mathbb R^d$. Les **dimensions doivent être compatibles** : une matrice $(n,d)$ peut multiplier une matrice $(d,k)$ pour produire une matrice $(n,k)$.

**Exemple calculé.** Soit $x=(3,5)$, $w=(2,-1)$, $b=4$. Alors $w^\top x+b=2\times3-1\times5+4=5$. Le modèle n'« comprend » pas le nombre 5 : il effectue une transformation numérique dont les coefficients devront être appris.

Une **norme** mesure la grandeur d'un vecteur. La norme euclidienne est $\lVert x\rVert_2=\sqrt{\sum_jx_j^2}$. Une norme peut régulariser des paramètres pour limiter leur amplitude. Le produit de matrices et les normes reviennent dans les réseaux de neurones, la régression et les embeddings.

### 1.3 Broadcasting et dimensions

NumPy peut effectuer une opération entre des tableaux de formes différentes lorsque les dimensions sont compatibles selon ses règles de *broadcasting*. Par exemple un tableau $(100,3)$ auquel on soustrait un vecteur $(3,)$ : le vecteur est appliqué à chaque ligne. Le broadcasting n'est pas une preuve que le calcul représente la bonne opération mathématique. Une dimension erronée peut produire un résultat **sans erreur de code**, mais scientifiquement faux.

```python
import numpy as np
X = np.array([[1., 2.], [3., 4.]])  # forme (2, 2)
w = np.array([2., -1.])           # forme (2,)
b = 0.5
print(X @ w + b)                   # [0.5, 2.5]
print(X.shape, w.shape)
```

**Piège :** confondre $Xw$ avec une multiplication terme à terme $X*w$ ; l'un agrège les caractéristiques, l'autre multiplie élément par élément, potentiellement avec broadcasting.

**Vérifie-toi.** (a) Une matrice $(80,7)$ et un vecteur $(7,)$ produisent combien de prédictions ? (b) Une couche $7\to5$ requiert combien de poids hors biais ? (c) Pourquoi une image $28\times28$ représente-t-elle 784 intensités si on l'aplatit ?

## 2. Dérivées, gradients et règle de chaîne

**À lire d'abord :** [Mathematics for Machine Learning (R02)](https://mml-book.github.io/), *Vector Calculus* et *Continuous Optimization* ; [R03], section *Calculus*. **Ensuite :** [R10], Google ML Crash Course, *Gradient Descent*.

### 2.1 Une dérivée mesure une sensibilité locale

Pour une fonction d'une variable $f(x)$, la dérivée $f'(x)$ indique comment la fonction varie pour une petite variation de $x$. Géométriquement, c'est la pente de la tangente. Pour $f(x)=(x-3)^2$, on a $f'(x)=2(x-3)$ : pente négative à gauche de 3, nulle au minimum, positive à droite. Cette pente indique une direction locale de diminution de l'erreur.

![Pente locale, courbe quadratique et direction de mise à jour. Figure originale ; fondements : [R02, R10].](figures/01_gradient.png){width=82%}

### 2.2 Plusieurs paramètres : le gradient

Lorsque la perte dépend de $w_1,\ldots,w_d$, on utilise les dérivées partielles. Le **gradient** $\nabla L(w)$ est le vecteur des $d$ dérivées partielles $\big(\partial L/\partial w_1,\ldots,\partial L/\partial w_d\big)$. Dans un espace euclidien, il pointe dans la direction locale de croissance la plus rapide ; $-\nabla L$ est une direction de descente pour un pas suffisamment petit.

Pour $L(w,b)=(w-2)^2+(b+1)^2$, le gradient vaut $(2(w-2),2(b+1))$. Au point $(0,0)$, on obtient $(-4,2)$. Avec un pas $\eta=0{,}1$, la nouvelle estimation est $(0,0)-0{,}1(-4,2)=(0{,}4,-0{,}2)$. La perte initiale vaut 5 ; la nouvelle vaut $(1{,}6)^2+(0{,}8)^2=3{,}2$.

### 2.3 La règle de chaîne, fondement de la rétropropagation

Si $z=f(x)$ et $y=g(z)$, alors $\frac{dy}{dx}=\frac{dy}{dz}\frac{dz}{dx}$. Exemple : $z=wx+b$, $L=(z-y)^2$ ; alors $\partial L/\partial w=2(z-y)x$. Un réseau de neurones est une **composition de nombreuses fonctions**. La rétropropagation applique systématiquement cette règle de chaîne pour calculer les gradients de tous les paramètres en réutilisant les calculs intermédiaires.

**Points de vigilance.** Dérivée nulle ne veut pas toujours dire minimum global ; un minimum local peut ne pas être global ; un grand learning rate peut faire osciller ou diverger la fonction de coût. Les réseaux de neurones apprennent généralement avec des variantes stochastiques de ces calculs.

**Exercice.** Calcule $d((2w-3)^2)/dw$ puis évalue à $w=1$. Vérifie avec une différence finie $[L(w+h)-L(w-h)]/(2h)$ pour $h=10^{-4}$.

## 3. Probabilités, statistiques et incertitude

**À lire d'abord :** [Mathematics for Machine Learning (R02)](https://mml-book.github.io/), *Probability and Distributions* ; [R01], introduction à l'apprentissage statistique. **Ensuite :** [R03], *Probability and Statistics*.

### 3.1 Décrire les données

La **moyenne** $\bar x=\frac1n\sum_i x_i$ résume une tendance centrale ; la **médiane** est moins sensible aux valeurs extrêmes. La **variance** $s^2=\frac1{n-1}\sum_i(x_i-\bar x)^2$ (estimateur échantillonnal) mesure la dispersion quadratique ; l'écart-type $s$ revient à l'unité initiale. Une **distribution** décrit la fréquence ou la probabilité des valeurs, et ne se réduit pas à sa moyenne. Pour les transactions bancaires, une distribution de montants peut être très asymétrique.

### 3.2 Probabilités conditionnelles et Bayes

$P(A\mid B)=P(A\cap B)/P(B)$ lorsque $P(B)>0$. Le théorème de Bayes s'écrit $P(A\mid B)=\frac{P(B\mid A)P(A)}{P(B)}$. La distinction entre $P(\mathrm{alerte}\mid\mathrm{fraude})$ (sensibilité) et $P(\mathrm{fraude}\mid\mathrm{alerte})$ (probabilité qu'une alerte signale réellement une fraude) est fondamentale.

**Exemple de taux de base :** sur 10 000 transactions dont 1 % de fraude, un détecteur identifie 90 % des fraudes et émet à tort une alerte sur 5 % des opérations normales. On attend 90 vraies alertes et $0{,}05\times9\,900=495$ fausses alertes. La précision est $90/(90+495)\approx15{,}4\%$. Même un détecteur très sensible peut produire une majorité de fausses alertes lorsque la fraude est rare.

![Effet du taux de base sur la signification d'un test. Schéma original construit sur un exemple numérique synthétique ; références [R01, R11].](figures/02_base_rate.png){width=87%}

### 3.3 Corrélation, causalité et échantillonnage

La corrélation linéaire mesure une association, pas un mécanisme causal. Deux variables corrélées peuvent l'être par l'effet d'une troisième variable. **Échantillonner** signifie choisir une partie d'une population. Un échantillon de commodité ou non représentatif peut introduire un biais de sélection. Dans le monde réel, les phénomènes changent dans le temps : la distribution observée pendant l'entraînement peut diverger de celle rencontrée ensuite.

**Exercice.** Recalcule la précision de l'exemple pour une prévalence de 0,1 %. Explique la modification **sans** changer la sensibilité et le taux de fausses alertes.

## 4. Python scientifique, NumPy, pandas et visualisation

**À lire d'abord :** [NumPy — Guide officiel (R09)](https://numpy.org/doc/stable/user/absolute_beginners.html), guide NumPy débutant ; [R12], tutoriels pandas. **Ensuite :** [R13], tutoriels Matplotlib. La programmation Python « classique » (fonctions, listes, dictionnaires, boucles, fichiers) est présupposée.

### 4.1 Pourquoi un tableau NumPy n'est pas une simple liste

`numpy.ndarray` stocke des éléments homogènes et permet des opérations vectorisées efficaces. Les propriétés `shape`, `ndim`, `dtype` déterminent ce que contient le tableau. Une **vue** peut partager sa mémoire avec le tableau d'origine : modifier une vue peut modifier les données sources. Une **copie** crée de nouvelles données. Cette distinction devient critique dans le nettoyage de données ou la manipulation d'images.

### 4.2 pandas : un modèle de données tabulaire

Un `DataFrame` associe des colonnes nommées, potentiellement de types différents. `isna()` compte les valeurs manquantes ; `groupby()` organise des agrégats ; `merge()` joint des tables. Avant toute modélisation, pose les questions : une ligne correspond à quoi ? une colonne a-t-elle une unité ? qui a saisi les données ? à quel moment cette information était-elle disponible ? Une colonne techniquement présente dans un fichier n'est **pas nécessairement autorisée comme entrée du modèle**.

```python
import pandas as pd
transactions = pd.DataFrame({
    "type": ["TRANSFER", "PAYMENT", "TRANSFER"],
    "amount": [200., 12., 3400.],
    "fraud": [0, 0, 1]
})
print(transactions.groupby("type")["amount"].agg(["count", "mean"]))
print(transactions["fraud"].mean())  # prevalence, échantillon fictif
```

### 4.3 Visualiser pour poser de meilleures questions

Un **histogramme** montre une distribution, un **nuage de points** une relation, une **courbe** une évolution temporelle. Une matrice de corrélation peut générer des hypothèses mais n'établit jamais, seule, la causalité. Choisis les axes et unités honnêtement ; une échelle tronquée peut amplifier artificiellement les différences. Dans le code et le README, documente la source et la méthode de construction des figures.

**Exercice.** Crée un tableau de 100 montants fictifs dont cinq sont très élevés ; compare moyenne et médiane, puis trace l'histogramme en échelle linéaire et en échelle logarithmique.

# Partie II — Apprentissage statistique et rigueur expérimentale

