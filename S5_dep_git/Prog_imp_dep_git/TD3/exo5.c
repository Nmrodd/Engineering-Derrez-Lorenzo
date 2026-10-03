#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/// On essaye de faire le jeu de Morpion /// 

// Pour saisir un nombre dans la variable entière a : scanf("%d", &a); 

// x pour le joueur 1 
// o pour le joueur 2 

// Tour après tour : les deux joueurs posent un symbole dans l'une des cases libres de la grille

// Décomposition du problème en sous problème ; 

    // faire la grille de départ  
    // dire a qui est le tour 
    // poser x à la ligne i et colonne j 
        // si le coup est possible remplacer le . de la case vide par x
        // afficher la nouvelle grille
    // poser o à la ligne i et colonne j 
        // si le coup est possible remplacer le . de la case vide par o
        // afficher la nouvelle grille
    // compte nombre symbole a la ligne i 
    // compte nombre symbole a la colonne j 
    // compte nombre symbole a la diag de la case (i,j) vers (n, k)
    // Si vainqueur alors dire lequel 
    // Sinon donner le tour au prochain joueur 

// Faire la grille 

// Version 1 : 

// void afficher_grille_depart(int i){
//     printf("  1 2 3\n");
//     printf("1 . . .\n");
//     printf("2 . . .\n");
//     printf("3 . . .\n");
//     i = 0; 
// }

// // Fonction qui détermine si le joueur détient bien le tour 
// int est_tour(int joueur, int i){
    
// }


// Version 2 :


// Il faut conserver en mémoire les 9 cases de la grille 
// Pour cela : 
    // un char* qui va contenir les cases de la manière suivante : "123456789" sans oublier le 0 terminal 
    // Ainsi a chaque tour on aura plus qu'a faire :
        // grille[indice] = x ou o 
        // Afficher la grille avec une boucle sur l'indice dans la grille pour procéder à l'affichage 

// A propos du i donné dans la version 1 : 

// Il permettait de compter le nombre de tours déjà joué, cela me permettait de faire une sorte de mémorisation/vérification du tour du joueur
// Si je veux garder quelque chose comme cela il faudra que je fasse un int* i pour conserver le paramètre pour d'autres fonctions 
// Cet indice me permettait également en fonction de sa parité de savoir si je devais placer x ou o dans la grille

// Suppression de la fonction est_tour car inutile ici. 

// Il faudra faire : 
// Déterminer le joueur et demander sa case.
// Vérifier que la saisie correspond à une case valide et libre.
// Si le coup est valide, modifier la grille, compter ce coup et afficher la grille.
// Vérifier si ce coup produit une victoire ou si la grille est pleine.
// Si la partie continue, recommencer avec le joueur suivant.

// Création de la grille 

void initialiser_grille(char* grille){
    for(int i = 0; i<9; i+=1){
        grille[i] = '1' + i; 
    }
    grille[9] = 0;
}

// La création de la grille se fera dans le main avec char grille[10];

// Affichage de la grille 
void affichage_grille(const char* grille){
    int cpt_ligne = 1; 
    printf("  1 2 3\n");
    int i = 2; 
    while(i < 9){
        // Mon print de base en dessous affiche les chiffre mémoires de grille, ce n'est pas assez esthétique
        // printf("%d %c %c %c\n", cpt_ligne, grille[i-2], grille[i-1], grille[i]);
        // La ligne du printf ici permet d'avoir des points au début et les bonnes cases sinon 
        printf("%d %c %c %c\n",cpt_ligne, 
            (grille[i-2] == 'x' || grille[i-2] == 'o') ? grille[i-2] : '.',
            (grille[i-1] == 'x' || grille[i-1] == 'o') ? grille[i-1] : '.',
            (grille[i] == 'x' || grille[i] == 'o') ? grille[i] : '.');
        i+=3;
        cpt_ligne +=1;
    }
    printf("\n");
}

// Demander une case à un seul joueur 
// On utilise scanf avec %d 

int recup_case_joueur(){
    int a;
    int res = scanf("%d", &a);
    if(res==1){
        return a;
    }
    else{
        return -1; // echec en lecture 
    }
}

// Vérifier la saisie et la validité du coup 

// Pour la saisie : 
    // Vérifier qu'il n'y a pas eu une erreur de lecture 

// Pour vérifier que la case n'a pas déjà été jouée ; 
    // Utiliser le opérateurs avec les chaines de caractères pour vérifier que grille[indice] est bien compris entre 0 et 8

// Pour vérifier que le coup est légitime : 
    // On vérifie que la saisie ne dépasse pas les bords de la grille 

// On renvoit 1 si tout est bon (comme un true) et on renvoit 0 si il y a une erreur quelque part 
// La gestion en cas d'erreur sera faite dans les autres fonction je pense 
    // Par exemple ; si coup illégitime alors écrire l'erreur pour informer le joueur puis appeler a nouveau recup case joueur 

int verif_saisie_coup(int a,const char* grille){
    // Vérifier le numéro : 
    if(a <= 0 || a > 9){
        printf("Erreur dans le numéro de case donné précédemment\n");
        return 0; 
    }
    // calcul de l'indice correspondant au numéro 
    int calcul = a-1;

    if(calcul>8|| calcul <0){
        printf("Acces en dehors de la grille interdit.\n");
        return 0;
    }

    // Vérifier le contenu de la case
    if(grille[calcul] == 'x' || grille[calcul] == 'o'){
        printf("Cette case a déjà été jouée\n");
        return 0;
    }

    // Si tout est bon, accepter le coup
    return 1;
}

// Placer un coup accepté et afficher la grille 
// on met int* i ici pour avoir l'adresse de i qui est initialisé dans le main par int i = 1;
int placer_coup(int a, char* grille, int* i){
    int accept = verif_saisie_coup(a, grille); 

    if (accept == 1){
        int calcul = a-1;
        // Regarder la parité de i pour savoir quel joueur joue et donc si il faut mettre 'x' ou 'o' dans la grille
        if((*i)%2 != 0){
            // joueur 1 qui joue 
            grille[calcul] = 'x';
        }
        else{
            grille[calcul] = 'o';
        }
        (*i)+=1;
        affichage_grille(grille);
        return 1;
    }
    else{
        return 0;
    }
}

// Détecter une victoire 

// Pour les lignes : 
// Cette fonction vérifie les trois lignes pour déterminer si il y a un cas de victoire
// Si c'est le cas elle renvoie 1 
// Sinon elle renvoit 0
int victoire_ligne(const char* grille, int i) {
    char symbole;

    // i a déjà été incrémenté après le coup.
    if (i%2 == 0) {
        symbole = 'x';
    }
    else {
        symbole = 'o';
    }

    int idx_ligne = 0;

    while (idx_ligne < 9) {
        int cpt = 0;
        for (int k = idx_ligne; k < idx_ligne + 3; k++) {
            if (grille[k] == symbole) {
                cpt++;
            }
        }
        if (cpt == 3) {
            return 1;
        }
        idx_ligne += 3;
    }
    return 0;
}

// Pour les colonnes : 
int victoire_colonne(const char* grille, int i) {
    char symbole;

    // i a déjà été incrémenté après le coup.
    if (i % 2 == 0) {
        symbole = 'x';
    }
    else {
        symbole = 'o';
    }

    int idx_colonne = 0;

    while (idx_colonne < 3) {
        int cpt = 0;

        for (int k = idx_colonne; k < 9; k += 3) {
            if (grille[k] == symbole) {
                cpt++;
            }
        }

        if (cpt == 3) {
            return 1;
        }

        idx_colonne++;
    }

    return 0;
}

int victoire_diagonale(const char* grille, int i) {
    char symbole;

    // i a déjà été incrémenté après le coup.
    if (i % 2 == 0) {
        symbole = 'x';
    }
    else {
        symbole = 'o';
    }

    int cpt = 0;

    // Première diagonale : 0, 4, 8.
    for (int k = 0; k < 9; k += 4) {
        if (grille[k] == symbole) {
            cpt++;
        }
    }

    if (cpt == 3) {
        return 1;
    }

    cpt = 0;

    // Seconde diagonale : 2, 4, 6.
    for (int k = 2; k < 7; k += 2) {
        if (grille[k] == symbole) {
            cpt++;
        }
    }

    if (cpt == 3) {
        return 1;
    }

    return 0;
}

// Détecter un match nul 

// Si tous les cas de victoire sont nuls et que l'on est déjà à i = 10, alors on a déjà joué 9 tours donc les cases ont toutes été remplies 

int match_nul(const char* grille, int i){
    int val_diag = victoire_diagonale(grille, i);
    int val_ligne = victoire_ligne(grille, i);
    int val_col = victoire_colonne(grille,i);
    int sum = val_col + val_diag + val_ligne;

    if (sum == 0 && i == 10){
        return 1;
    }
    else{
        return 0;
    }
}

// Organiser la boucle complète de partie 
int main(int argc, char** argv){
    // Créer la grille : 
    char grille[10]; 
    initialiser_grille(grille);

    // Affichage du début : 
    affichage_grille(grille);

    // Initialisation du premier tour : 
    int i = 1;

    // Poursuite du jeu : 
    while(i<10 && victoire_colonne(grille, i) == 0 && victoire_ligne(grille, i) == 0 && victoire_diagonale(grille,i) == 0){
        // Les incrémentations de i sont déjà dans la fonction du coup placé, c'est pour cela qu'elles ne sont pas visible dans la boucle de ce main

        // Annonce du joueur 
        if (i%2 != 0){
            printf("C'est au joueur 1 de sélectionner une case :\n");
        }
        else{
            printf("C'est au joueur 2 de sélectionner une case :\n");
        }
        
        // Choix de la case : 
        int coup = recup_case_joueur(); 

        // Vérification du coup : 
        int v = verif_saisie_coup(coup, grille); 

        if (v == 0){
            printf("Vous devez sélectionner une case légitime :\n");
        }
        else{
            printf("Coup valide.\n");
            int x = placer_coup(coup, grille, &i);
            if(x==0){
                printf("Erreur dans le placement du coup\n"); 
            }
        }
    }
    // Cas ou la boucle se brise : 
        // Si i = 10 : match nul 
        // Sinon il y a une victoire à déterminer : 
            // Attention ici comme i a été incrémenté c'est le joueur du tour d'avant qui a gagné 

    if(victoire_ligne(grille,i)==1 || victoire_colonne(grille, i) == 1 || victoire_diagonale(grille, i) == 1){
        if(i%2 == 0){
            affichage_grille(grille);
            printf("Bravo joueur 1, tu as gagné !\n"); 
        }
        else{
            affichage_grille(grille); 
            printf("Bravo joueur 2, tu as gagné !\n");
        }
    }
    else{
        // Cas du match nul : 
        // On vérif au cas ou 
        if(match_nul(grille, i)==1){
            printf("C'est un match nul, dommage !\n");
        }
        else{
            printf("Erreur, ni match nul, ni gagnant\n");
        }
    }
    return EXIT_SUCCESS;
}