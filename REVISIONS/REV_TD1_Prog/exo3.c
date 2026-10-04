#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


/// Exercice 3 : Manipulation de tableaux d'entiers /// 


// Q1 : 

int somme_elt_tab(int* tab, int n){
    int sum = 0; 
    for (int i =0; i<n; i+=1){
        sum += tab[i];
    }

    return sum; 
}

// Q2 : 

// Pour calculer le produit scalaire de deux tableaux d'entiers il faut implémenter une fonction racine carrée : 

int racine_c(int n){
    int i = 1; 
    while(i*i<n){
        i+=1;
    }
    return i-1;
}


//// ERRATUM : IL N'Y A PAS BESOIN DE SQRT //// (je le laisse ici vu que je l'ai implémenté)


// Poursuite de la fonction initiale : 
// PREDICAT : n est la taille des deux tableaux

int ps_tab(int* tab1, int* tab2, int n){
    int res = 0; 

    for(int i = 0; i<n; i+=1){
        res += tab1[i]*tab2[i];
    }

    return res;
}

// Q3 : 

int sum_membre_a_membre_tab(int* tab1, int* tab2, int n){
    int sum = 0;    

    for(int i = 0; i<n; i+=1){
        sum += tab1[i]+tab2[i];
    }

    return sum; 
}



// Test de Q1, Q2 et Q3 : 
int main(int argc, char** argv){
    int n = 4; 
    int tab[4] = {1, 2, 3, 4}; 

    // Test Q1 : 
    int t1 = somme_elt_tab(tab, n); 
    printf("Le test de Q1 donne : %d\n", t1);

    // test rapide pour la fonction racine carrée ; 
    int a = 5;  
    int t_racine = racine_c(a); 
    printf("%d\n", t_racine); 

    // Test Q2 
    int taille = 3; 
    int tab1[3] = {1, 2, 3}; 
    int tab2[3] = {4, 5, 6}; 
    int t2 = ps_tab(tab1, tab2, taille); 
    printf("Le P.S est : %d\n", t2); 


    // test Q3 : 
    int t3 = sum_membre_a_membre_tab(tab1, tab2, taille); 
    printf("La somme des tableaux membres à membres est : %d\n", t3);

    return EXIT_SUCCESS;
}