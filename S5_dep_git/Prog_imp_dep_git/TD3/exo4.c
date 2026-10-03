#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/// Exercice 4 /// 


/// Ecriture du type enum color /// 


enum color {
    NOIR, MARRON, ROUGE, ORANGE, JAUNE, VERT, BLEU, VIOLET, GRIS, BLANC, KIND_COUNT
};


/// Ecriture de la fonction times_pow10 /// 

// Il faut écrire : n * 10^p 

int times_pow10(int n, int p){
    int dix_puiss_p = 1;
    for(int cp = p; cp>0; cp-=1){
        dix_puiss_p = dix_puiss_p * 10;
    }
    return n*dix_puiss_p;
}

// Test times_pow10 

// int main(int argc, char** argv){
//     int i = 2; 
//     while(i<argc){
//         int n_i = atoi(argv[i-1]); 
//         int p_i = atoi(argv[i]);
//         int t_i = times_pow10(n_i, p_i); 
//         printf("Le résultat pour %d et %d est : %d\n", n_i, p_i, t_i);
//         i+=2;
//     }
//     return EXIT_SUCCESS;
// }

// Output pour ./exo4_exec 3 2 5 3 -> 300 et 5000 

// Ecriture de la fonction qui en fonction de 3 couleurs retourne la valeur de la résistance. 
// Quel type doit retourner cette fonction ? 

int valeur_resistance(enum color c1, enum color c2, enum color c3){
    int res = 0; 
    res = c1 * 10; 
    res = c2 + res; 
    res = times_pow10(res, c3);
    return res;
}

// Test pas ouf car hard-codé :
// int main(int argc, char** argv){
//     enum color c1 = NOIR; 
//     enum color c2 = BLANC; 
//     enum color c3 = MARRON;

//     int test_1_HC = valeur_resistance(c1, c2, c3);
//     printf("%d\n", test_1_HC);
//     return EXIT_SUCCESS;
// }
// Output : 90;

// Test classique avec argc et argv pour Q3

// int main(int argc, char** argv){
//     int i = 3; 
//     while(i<argc){
//         enum color c_i3 = (enum color) (atoi(argv[i]));
//         enum color c_i2 = (enum color) (atoi(argv[i-1]));
//         enum color c_i1 = (enum color) (atoi(argv[i-2]));
//         int t_i = valeur_resistance(c_i1, c_i2, c_i3);
//         printf("%d\n", t_i);
//         i+=3;
//     }
//     return EXIT_SUCCESS;
// }


// Ecriture de la fonction index_of 
// Retourne l'indice d'une chaine de caractère dans un tableau de chaine 

int index_of(char** tab_chaines, int nb_chaines,char* elt){

    for(int i = 0; i<nb_chaines; i+=1){
        if(strcmp(tab_chaines[i], elt) == 0){
            return i; 
        }
    }
    return -1; // On pourrait retourner nb_chaines également car on est sur que nb_chaines est un indice impossible pour un tableau de taille nb_chaines 
}

// Test index_of 

// int main(int argc, char** argv){
    
//     int ind_alea = rand()%argc;

//     int t_i = index_of(argv, argc, argv[ind_alea]);
//     printf("Pour la chaine %s dans le tableau de chaines, on obtient l'indice %d\n",argv[ind_alea], t_i);

//     return EXIT_SUCCESS;
// }


// Ecriture un programme qui en fonction de trois couleurs données soit textuellement, affiche la valeur de la résistance 

int main(int argc, char **argv)
{
    // On est obligé d'utiliser un tableau de char couleurs ici pour récupérer avec index_of pour ensuite récupérer le bon type enum colo
    char *couleurs[KIND_COUNT] = {
        "NOIR",
        "MARRON",
        "ROUGE",
        "ORANGE",
        "JAUNE",
        "VERT",
        "BLEU",
        "VIOLET",
        "GRIS",
        "BLANC"
    };
    int i = 3;
    while (i < argc) {
        int ind1 = index_of(couleurs, KIND_COUNT, argv[i - 2]);
        int ind2 = index_of(couleurs, KIND_COUNT, argv[i - 1]);
        int ind3 = index_of(couleurs, KIND_COUNT, argv[i]);

        enum color c_i1 = (enum color) ind1;
        enum color c_i2 = (enum color) ind2;
        enum color c_i3 = (enum color) ind3;

        int t_i = valeur_resistance(c_i1, c_i2, c_i3);
        printf("%d\n", t_i);
        i += 3;
    }
    return EXIT_SUCCESS;
}