#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


/// Exercice 2 TD1 : permet de manipuler des tableaux d'entiers ///

// Q1 : 


void affiche_tab(int* tab, int taille){
    for(int i = 0; i<taille; i+=1){
        int val_i = tab[i]; 
        printf("%d ", val_i); 
    }
    printf("\n"); 
}

// Q2 : 

// Test de Q1 avec un main() qui écrit le tableau dans le dur 

// int main(int argc, char** argv){
//     int taille = 4; 
//     int tab[4] = {1, 4, 2, 5}; 

//     affiche_tab(tab, taille); 

//     return EXIT_SUCCESS;

// }

// Q3 : 
void remplir_tab_n_premiers_pairs(int* tab, int n){
    int indice_ajout_tab = 0;

    int cpt_n_pairs = 0;
    int calc = 0;
    while(cpt_n_pairs != n){
        if (calc%2 == 0){
            cpt_n_pairs+=1;
            // Ajout dans le tab : 
            tab[indice_ajout_tab] = calc;
            indice_ajout_tab+=1;
        }
        calc+=1;
    } 
}


// Q4 : 

int main(int argc, char** argv){
    int n = 4; 
    int tab[4]; 
    remplir_tab_n_premiers_pairs(tab, n); 
    affiche_tab(tab, n);
    return EXIT_SUCCESS;
}