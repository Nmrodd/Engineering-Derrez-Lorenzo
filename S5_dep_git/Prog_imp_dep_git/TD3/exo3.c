#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/// Exercice 3 /// 

// Q1 : 

// Méthode 1 : 
int nb_bits_m1(int n){ 
    int i = 0; 

    size_t taille_octets = sizeof(n);
    int taille = taille_octets*8;

    int masque = 1;
    int cpt = 0;

    while(i<taille){
        int dec = n & masque; 
        if (dec != 0){
            cpt +=1;
        }
        masque = masque << 1;
        i+=1;
    }
    return cpt;
}

// Méthode 2 : 
int nb_bits_m2(int n){
    int cpt = 0;
    int masque = n;
    while(masque!= 0)
    {
        int dec = masque & 1;
        if(dec == 1){cpt++;};
        masque = masque >> 1;
    }
    return cpt;
}

// // Test Q1: 
// int main(int argc, char** argv){
//     int i = 1; 
//     while(i<argc)
//     {
//         int test_i = nb_bits_m1(atoi(argv[i]));
//         printf("%d ", test_i);
//         i+=1;
//     }
//     printf("\n");

//     int j = 1; 
//     while(j<argc){
//         int test_j = nb_bits_m2(atoi(argv[j]));
//         printf("%d ", test_j);
//         j+=1;
//     }
//     printf("\n");

//     return EXIT_SUCCESS;
// }


// Q2 : 

// On souhaite utiliser l'algorithme de Hacker's Delight

int hackers_delight(int n){
    int masque = n & 1;

    int cpt = 0;

    while(masque != 0)
    {
        // Récupération du complément à deux : 

        // Retirer le bit à 1 avec OU EXCLUSIF :

    }
}
