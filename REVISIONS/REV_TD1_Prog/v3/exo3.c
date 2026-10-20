#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Question 1 ;


int sum_elements(int* array, int n){
    int sum = 0; 

    for (int i = 0; i<n; i+=1){
        sum += array[i];
    }
    return sum; 
}


// Question 2 : 

int p_scalar(int* array1, int n, int* array2){
    int res = 0;

    for(int i = 0; i<n; i+=1){
        res += array1[i]*array2[i];
    }

    return res;
}


// Question 3 : 
int sum_2_arrays(int* array1, int n, int* array2){
    int sum = 0; 

    for (int i = 0; i<n; i+=1){
        sum += array1[i] + array2[i];
    }
    return sum;
}


// Test de toutes les fonctions : 

int main(int argc, char** argv){
    
    // Test Q1 :

    int n1 = 4; 
    int tab1[4] = {1, 2, 3, 4};

    int t_1 = sum_elements(tab1,n1);
    printf("La somme est : %d\n", t_1);

    // Test Q2 :

    int tab2[4] = {4, 3, 2, 1};

    int t_2 = p_scalar(tab1, n1, tab2);
    printf("Le produit scalaire des deux tab est : %d\n", t_2);


    // Test Q3 : 

    int t_3 = sum_2_arrays(tab1, n1, tab2);
    printf("La somme des deux tab membres a membres est: %d\n", t_3);


    return EXIT_SUCCESS;
}