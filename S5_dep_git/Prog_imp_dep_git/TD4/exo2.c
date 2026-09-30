#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Exercice 1 

// Q1 

void min_max(int l, int* t, int* min, int* max){
    for(int i = 0; i<l; i+=1){
        if (t[i] < *min){*min = t[i];}
        if (t[i] > *max){*max = t[i];}
    }
}


// // Test Q1 : 
// int main(int argc, char** argv){
//     //Construction du tableau 
//     int t[argc-1]; 
//     for(int i = 1; i<argc; i+=1){
//         int elt = atoi(argv[i]); 
//         t[i-1] = elt;
//     }   

//     int min = t[0];
//     int max = t[0];

//     min_max(argc-1, t, &min, &max); 

//     printf("Le min et le max sont respectivement : %d, %d\n", min, max);
//     return EXIT_SUCCESS;
// }

// Q2 : 

void min_max_update(int l, int t[], int *min, int *max){
    // On initialise avec le premier élément (si demandé)
    if (min != NULL) { *min = t[0]; }
    if (max != NULL) { *max = t[0]; }

    for (int i = 1; i < l; i += 1) {
        if (min != NULL && t[i] < *min) { *min = t[i]; }
        if (max != NULL && t[i] > *max) { *max = t[i]; }
    }
}

// Test Q2 : 
int main(int argc, char** argv){
    int t[argc-1];
    for(int i = 1; i < argc; i += 1){
        t[i-1] = atoi(argv[i]);
    }

    int min, max;

    min_max_update(argc-1, t, &min, &max);
    printf("Les deux : min = %d, max = %d\n", min, max);

    min_max_update(argc-1, t, &min, NULL);
    printf("Min seul : min = %d\n", min);

    min_max_update(argc-1, t, NULL, &max);
    printf("Max seul : max = %d\n", max);

    return EXIT_SUCCESS;
}