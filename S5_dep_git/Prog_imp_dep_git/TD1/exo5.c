#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//// Exercice 5 ////


// Q1 

void pascal_ligne(int n, int* valeurs){
    int k = 1; 
    
    printf("%d ", 1); 
    
    while (k<n-1){
        int elt = valeurs[k-1] + valeurs[k]; 
        printf( "%d ", elt);  
        k++; 
    }
    printf("1 \n");
}


// Q2 

void affiche_pascal(int n, int* valeurs,int i){ 
    if(i<n){
        int ligne_i[i+1]; 
        int k = 1; 
        ligne_i[0] = 1; 
        ligne_i[i] = 1;
        printf("1 ");
        while(k<i){
            int elt = valeurs[k-1]+valeurs[k]; 
            ligne_i[k] = elt; 
            printf("%d ", ligne_i[k]); 
            k++;
        }
        printf("1 \n"); 
        i+=1;
        affiche_pascal(n, ligne_i, i); 
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    //Q3 
    int n;

    printf("Combien de lignes voulez-vous ? ");
    scanf("%d", &n);

    int valeurs[2] = {1,1}; 
    pascal_ligne(n, valeurs); 

    int i = 1;
    int val1[1] = {1};
    printf("1 \n");
    affiche_pascal(n,val1, i); 

    return 0; 
}