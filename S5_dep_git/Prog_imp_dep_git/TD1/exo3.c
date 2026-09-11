#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//// Exercice 3 ////

// Q1 : 

int sum_elts_array(int* tab, int n){
    int s = 0; 
    int i = 0; 
    while(i<n){
        s += tab[i]; 
        i++; 
    }
    return s; 
}

// Q2 

int sqr(int x){
    int i = 0; 
    while(i*i<x){
        i++; 
    }
    return i; 
}

int produit_scalaire(int* tab1, int* tab2, int n){
    int i = 0; 
    int res = 0; 

    while (i<n){
        res += tab1[i]*tab2[i]; 
        i++; 
    }
    return sqr(res); 
}

// Q3 : 

int somme_memb_memb_arr(int n, int* tab1, int* tab2){
    int i = 0; 
    int res = 0; 
    while(i<n){
        res += tab1[i]+tab2[i]; 
        i++; 
    }
    return res; 
}

// Test 

int main(int argc, char* argv[]){
    int n = 5; 

    int tab1[5] = {0, 1, 2, 3, 4};
    int tab2[5] = {5, 4, 3, 2, 1};

    int t1 = sum_elts_array(tab1, n); 
    printf("Test first function for tab1 : %d\n", t1); 

    int t2 = produit_scalaire(tab1, tab2, n); 
    printf("Test second function : %d\n", t2); 

    int t3 = somme_memb_memb_arr(n, tab1, tab2); 
    printf("Test third function : %d\n", t3);

    return 0; 
}
