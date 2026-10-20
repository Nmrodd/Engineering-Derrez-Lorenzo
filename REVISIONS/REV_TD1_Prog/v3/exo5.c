#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


// Ajout : 

void print_array(int* array, int n){
    for(int i = 0; i<n; i+=1){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Q1 : 

// Il faut parcourir de droite à gauche ici 


void pascal_ligne(int n, int valeurs[]){
    for(int i = n-1; i>0; i-=1){
        valeurs[i] = valeurs[i-1] + valeurs[i];
    }
}

// Test: 

// int main(int argc, char** argv){
//     int n = 4; 
//     int res[n]; 
//     res[0] = 1; 
//     pascal_ligne(2, res);
//     print_array(res,2);

//     return EXIT_SUCCESS;
// }

// Q2 : 

void ecrire_pascal(int n, int* valeurs){
    for(int i = 1; i<=n; i+=1){
        pascal_ligne(i, valeurs);
        print_array(valeurs,i);
    }
}

// // test : 
// int main(int argc, char** argv){
//     int n = 4;
//     int res[n];
//     res[0] = 1;

//     ecrire_pascal(n,res);

//     return EXIT_SUCCESS;
// }

