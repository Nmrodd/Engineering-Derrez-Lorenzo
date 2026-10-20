#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Question 1: 


void print_array(int* array, int n){
    for(int i = 0; i<n; i+=1){
        printf("%d ", array[i]);
    }
    printf("\n");
}


// Question 2 ; test de Q1 

// int main(int argc, char** argv){
    
//     int n = 4; 
//     int tab[4] = {1, 2, 3, 4};


//     print_array(tab, n);

//     return EXIT_SUCCESS;
// }


// Question 3; 

void nb_premiers_pairs(int n, int* res){
    int cpt = 0;
    int calc = 0;

    while(cpt<n){
        if(calc%2==0){
            res[cpt] = calc;
            cpt +=1;
        }
        calc +=1;
    }
}

// Question 4 ; 

// // Test rapide : 

// int main(int argc, char** argv){
//     int n = 3; 
//     int tab[3];

//     nb_premiers_pairs(n, tab);

//     print_array(tab,n);

//     return EXIT_SUCCESS;
// }