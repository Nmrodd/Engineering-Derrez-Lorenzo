#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//// Exercice 2 ////

// Q1 : 

void affiche_tab(int* tab, int n){
    int i = 0; 
    while(i<n){
        printf("%d ", tab[i]); 
        i++; 
    }
    printf("\n");
}

/// Test 

int main(int argc, char* argv[]){
    int n = 5; 
    int* tab1 = malloc(n*sizeof(int)); 

    int i = 0; 
    while(i<n){
        tab1[i] = i; 
        i++; 
    }

    affiche_tab(tab1, n); 
    return 0; 
}

// Q3 :

int* n_premier_pairs(int n){ 
    int* tab = malloc(n*sizeof(int)); 
    int cpt = 0;

    int nbr = 0; 

    while(cpt!=n){
        if(nbr%2==0){
            tab[cpt] = nbr; 
            nbr++; 
            cpt++; 
        }
        else{
            nbr++; 
        }
    }
    return tab; 
}

// Modification of the main function 

int main(int argc, char* argv[]){
    int n = 5; 
    int* tab1 = n_premier_pairs(n); 
    
    affiche_tab(tab1,n); 

    return 0; 
}