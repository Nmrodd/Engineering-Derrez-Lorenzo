#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

////// Exercice 8 : Bonus ///////


// Q1
void tri_bulle(int* tab, int n){
    int i = 0; 
    while(i<n){
        int j = i+1;
        while(j<n){
            if(tab[i]>tab[j]){
                int buff = tab[i]; 
                tab[i] = tab[j]; 
                tab[j] = buff; 
            } 
            j+=1; 
        }
        i+=1; 
    }
}

void affiche_tab(int* tab, int n){
    int i = 0; 
    while(i<n){
        printf("%d ", tab[i]);
        i+=1; 
    }
    printf("\n"); 
}

// Test Q1 

// int main(int argc, char* argv[]){
//     int n = 5; 
    
//     int tab[5] = {1, 4, 2, 3, 0}; 

//     tri_bulle(tab, n);
    
//     affiche_tab(tab, n); 

//     return 0;
// }

// Q2 
// In order to receive the number of comparison during the execution, we'll have to create a structure couple to get also the result of is_element and the nb_op
// struct cpl
// {
//     int res; 
//     int nb_op; 
// };
// typedef struct cpl cpl; 

// Conjecture : let's suppose we don't need the result anymore (0 or 1) but we only put our focus on nb_op
int is_elt(int* tab, int n, int x){
    int nb_op=0;

    int i = 0; 

    nb_op+=1; 

    while(i<n){
        if (x == tab[i]){
            return nb_op; 
        }
        i++; 
        nb_op+=4; 
    }
    return nb_op; 
}
// Same Conjecture here 
int is_elem_dich(int* tab, int n, int x){
    int nb_op = 0; 
    
    int debut = 0; 
    int fin = n-1; 

    nb_op+=2; 

    while(debut<fin){
        int mid = (debut+fin)/2; 
        if(tab[mid]==x){
            nb_op+=1;
            return nb_op;
        }
        if(x < tab[mid]){
            fin = mid-1; 
            nb_op+=2; 
        }
        else{
            debut = mid+1; 
            nb_op +=1; 
        }
        nb_op+=2; 
    }
    return nb_op; 
}

int main(int argc, char* argv[]){
    
    int n_min = 1000; 
    int n_max = 20000; 
    int pas   = 1000; 

    int n; 
    for(n = n_min; n <= n_max; n += pas){

        int* tab1 = malloc(n*sizeof(int)); 
        int indice1 = 0;
        while(indice1<n){
            tab1[indice1] = rand(); 
            indice1+=1; 
        }

        int x1 = rand();

        int nb_op_iter = is_elt(tab1, n, x1); 

        tri_bulle(tab1, n); 
        int nb_op_dich = is_elem_dich(tab1, n, x1);

        free(tab1); 

        printf("%d\t%d\t%d\n", n, nb_op_iter, nb_op_dich);
    }

    return 0;  
}