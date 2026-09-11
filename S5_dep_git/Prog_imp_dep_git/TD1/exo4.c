#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//// Exercice 4 //// 

// Q1 : 

int est_trie(int* tab, int n){ 
    int i = 1; 
    int anc_val = tab[0];

    while(i<n && anc_val<tab[i]){
        anc_val = tab[i]; 
        i++; 
    }
    if (n == i){
        return 1; 
    }
    else{
        return 0;
    }
}


// Q2 : 

int is_elt(int* tab, int n, int x){
    int i = 0; 
    while(i<n){
        if (x == tab[i]){
            return 1; 
        }
        i++; 
    }
    return 0; 
}

// Q3

int is_elem_dich(int* tab, int n, int x){
    int debut = 0; 
    int fin = n-1; 

    while(debut<fin){
        int mid = (debut+fin)/2; 
        if(tab[mid]==x)return 1; 
        if(x < tab[mid]){
            fin = mid-1; 
        }
        else{
            debut = mid+1; 
        }
    }
    return 0; 
}

// Q4 : 
int rech_dich_rec(int* tab, int n, int deb, int fin, int x){
    
    if (deb >= fin)return 0; 

    int mid  = (deb+fin)/2; 
    if(tab[mid]==x){return 1;}
    if(tab[mid]>x){
        fin = mid-1; 
        return rech_dich_rec(tab, n, deb, fin, x); 
    }
    else{
        deb = mid+1; 
        return rech_dich_rec(tab, n, deb, fin, x); 
    }
}

//Test 

int main(int argc, char* argv[]){
    
    int n = 5;
    int tab1[5] = {0, 1, 2, 3, 4}; 
    int t1 = est_trie(tab1, n); 
    printf("Test Q1 : %d\n", t1); 

    int x1 = 3; 
    int t2 = is_elt(tab1, n, x1); 
    printf("Test Q2 : %d\n", t2); 

    int x2 = 8; 
    int t3 = is_elem_dich(tab1, n, x2); 
    printf("Test Q3 : %d\n", t3); 
    
    int x3 = 7; 
    int t4 = rech_dich_rec(tab1, n, 0, 4, x3); 
    printf("Test Q4 : %d\n", t4); 
}