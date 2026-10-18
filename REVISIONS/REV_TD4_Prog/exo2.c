#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


// On veut une fonction qui soit capable de retourner le min et le max d'un tableau en meme temps

struct couple {
    int min;
    int max;
};

void return_min_max(int* array, int n, struct couple* cpl_resultats){
    int current_min = array[0];
    int current_max = array[0];

    for(int i = 0; i<n; i+=1){
        if(array[i]<current_min){
            current_min = array[i];
        }
        if(array[i]>current_max){
            current_max = array[i];
        }
    }

    cpl_resultats->max = current_max; 
    cpl_resultats->min = current_min;
}


// Test rapide :

int main(int argc, char** argv){
    int n = 3; 
    int array[3];

    for(int i = 0; i<n; i+=1){
        array[i] = atoi(argv[i+1]);
    }

    struct couple cpl;

    return_min_max(array,n,&cpl);
    
    printf("%d\n", cpl.min);
    printf("%d\n", cpl.max);

    return EXIT_SUCCESS;
}
