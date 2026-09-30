#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Exercice 1 : 

void swap(int* a, int* b){
    int buff = *a; 
    *a = *b; 
    *b = buff; 
}

// //Test Q1 : 
// int main(int argc, char** argv){
//     printf("Avant le swap : %d;%d\n", atoi(argv[1]), atoi(argv[2]));
//     int a = atoi(argv[1]);
//     int b = atoi(argv[2]);
//     swap(&a, &b);
//     printf("Après le swap : %d;%d\n", a, b);
//     return EXIT_SUCCESS;
// }

// Q2 : 

void order(int* a, int* b){
    if (*a > *b){
        swap(a, b);
    }
}

// Test Q2 
int main(int argc, char** argv){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]); 
    printf("Avant order : %d, %d\n",a,b);
    order(&a, &b);
    printf("Après order : %d, %d\n", a, b);
    return EXIT_SUCCESS;
}