#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/// Exercice 4 : /// 



// Q1 ;

int est_triee(int* tab, int n){
    int i = 1; 

    while(i<n){
        if(tab[i-1]>tab[i]){
            return 0;
        }
        i+=1;
    }
    return 1;
}

// Q2 : 

int is_elt(int* tab, int n, int elt){
    int i = 0; 
    while(i<n){
        if(tab[i] == elt){
            return 1; 
        }
        i+=1;
    }
    return 0;
}

// Q3 : (Q4 car j'ai déjà fais la récursion)
// On suppose que le tableau est déjà trié 
// Recherche dichotomique 

int rech_dich(int* tab, int n, int elt, int debut, int fin){
    if(debut>fin){
        return 0;
    }

    int m = (debut+fin)/2;

    if (tab[m] == elt){
        return 1;
    }
    if(tab[m] < elt){
        return rech_dich(tab, n, elt, m+1, fin);
    }
    return rech_dich(tab, n, elt, debut, m-1);
}

// Test pour les différentes questions : 

int main(int argc, char** argv){

    // Test Q1 
    int n = 3; 
    int tab[3] = {1, 2, 3}; 
    int test1 = est_triee(tab, n);  
    printf("%d\n", test1);

    // Test Q2 : 
    int t2 = is_elt(tab, n, 2); 
    int t3 = is_elt(tab, n, 4);
    printf("%d\n", t2); 
    printf("%d\n", t3);

    // Test Q3/Q4 (j'ai directement fais une version récursive)
    int debut = 0; 
    int taille = 5; 
    int fin = taille-1;
    int tab2[5] = {1, 4, 8, 10, 12};
    int elt1 = 3;
    int elt2 = 4;
    int t_dic1 = rech_dich(tab2, taille, elt1, debut, fin);
    printf("%d\n", t_dic1);
    int t_dic2 = rech_dich(tab2, taille, elt2, debut, fin);
    printf("%d\n", t_dic2);

    return EXIT_SUCCESS;
}