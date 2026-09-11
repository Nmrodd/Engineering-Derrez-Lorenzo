#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//// Exercice 7 : Bonus //// 

// Q1 : sieve of Eratosthenes

// Conjecture : tabool has a length of n+1. With that information, the value is the index

int sqr(int x){
    int i = 0; 
    while(i*i<x){
        i++; 
    }
    return i; 
}

void eratosthene(int* tabool, int n){
    int pp_entier = 2; 
    int pg_entier = sqr(n); 
    
    while(pp_entier <= pg_entier){
        int cpt = pp_entier+1;
        while(cpt<=n){
            if(cpt%pp_entier == 0){
                tabool[cpt] = 0;
            }
            cpt +=1; 
        }
        pp_entier+=1;
    }
}

// Test Q1 

// Aux. function 
void affiche_datab(int* tab, int n){
    int indice=0; 
    while(indice<=n){
        printf("%d ", tab[indice]);
        indice +=1; 
    }
    printf("\n"); 
}


// int main(int argc, char* argv[]){
//     int n = 30; 
    
//     int* tabool = malloc((n+1)*sizeof(int));
//     tabool[0] = 0; 
//     tabool[1] = 0; 
//     int i = 2; 
//     while(i<=n){
//         tabool[i] = 1; 
//         i+=1; 
//     } 

//     eratosthene(tabool, n); 
//     affiche_datab(tabool, n); 

//     return 0; 
// }

// Q2 

int eratosthene_2_sans_comp(int* tabool, int n){
    int pp_entier = 2; 
    int pg_entier = sqr(n); 
    
    // Q2 
    int nb_acc = 0; 

    while(pp_entier <= pg_entier){
        int cpt = pp_entier+1;
        while(cpt<=n){
            if(cpt%pp_entier == 0 ){
                tabool[cpt] = 0;
                nb_acc+=1; 
            }
            
            cpt +=1; 
        }
        pp_entier+=1;
    }

    return nb_acc; 
}

int eratosthene_2_avec_comp(int* tabool, int n){
    int pp_entier = 2; 
    int pg_entier = sqr(n); 
    
    // Q2 
    int nb_acc = 0; 

    while(pp_entier <= pg_entier){
        int cpt = pp_entier+1;
        while(cpt<=n){
            if(tabool[cpt]==1 && cpt%pp_entier == 0 ){
                tabool[cpt] = 0;
                nb_acc+=1; 
            }
            nb_acc+=1; 
            cpt +=1; 
        }
        pp_entier+=1;
    }

    return nb_acc; 
}

// Test Q2

#include <time.h>

// int main(int argc, char* argv[]){
//     int n = 30000; 
    
//     int* tabool = malloc((n+1)*sizeof(int));
//     tabool[0] = 0; 
//     tabool[1] = 0; 
//     int i = 2; 
//     while(i<=n){
//         tabool[i] = 1; 
//         i+=1; 
//     } 

//     clock_t debut; 
//     clock_t fin; 

//     double temps_wit_comp;
//     double temps_avec_comp;

//     debut = clock(); 
//     int t1 = eratosthene_2_sans_comp(tabool, n); 
//     fin = clock(); 

//     temps_wit_comp = (double)(fin - debut) / CLOCKS_PER_SEC;

//     debut = clock(); 
//     int t2 = eratosthene_2_avec_comp(tabool, n); 
//     fin = clock(); 

//     temps_avec_comp = (double)(fin-debut)/CLOCKS_PER_SEC;

//     printf("Nombre d'accès sans comparaisons : %d \n",t1); 
//     printf("Nombre d'accès avec comparaisons : %d \n", t2);
    
//     printf("Temps sans comparaisons : %f \n", temps_wit_comp); 
//     printf("Temps avec comparaisons : %f \n", temps_avec_comp); 


//     return 0; 
// }

// Q3 
int eratosthene_3_sans_comp(int* tabool, int n){
    int nb_op = 0;

    int pp_entier = 2; 
    int pg_entier = sqr(n); 
     
    nb_op +=2; 

    while(pp_entier <= pg_entier){
        int cpt = pp_entier+1;
        while(cpt<=n){
            if(cpt%pp_entier == 0 ){
                tabool[cpt] = 0;
                nb_op+=1; 
            }
            cpt +=1; 
            nb_op+=4; 
        }
        pp_entier+=1;
        nb_op+=3; 
    }

    return nb_op; 
}

int eratosthene_3_avec_comp(int* tabool, int n){
    int nb_op = 0; 

    int pp_entier = 2; 
    int pg_entier = sqr(n); 

    nb_op +=2; 

    while(pp_entier <= pg_entier){
        int cpt = pp_entier+1;
        while(cpt<=n){
            if(tabool[cpt]==1 && cpt%pp_entier == 0 ){
                tabool[cpt] = 0;
                nb_op+=1; 
            }
            cpt +=1;
            nb_op+=5; 
        }
        pp_entier+=1;
        nb_op +=3; 
    }

    return nb_op; 
}

// Test Q3

// int main(int argc, char* argv[]){
//     int n = 30000; 
    
//     int* tabool = malloc((n+1)*sizeof(int));
//     tabool[0] = 0; 
//     tabool[1] = 0; 
//     int i = 2; 
//     while(i<=n){
//         tabool[i] = 1; 
//         i+=1; 
//     } 

//     clock_t debut; 
//     clock_t fin; 

//     double temps_wit_comp;
//     double temps_avec_comp;

//     debut = clock(); 
//     int t1 = eratosthene_3_sans_comp(tabool, n); 
//     fin = clock(); 

//     temps_wit_comp = (double)(fin - debut) / CLOCKS_PER_SEC;

//     debut = clock(); 
//     int t2 = eratosthene_3_avec_comp(tabool, n); 
//     fin = clock(); 

//     temps_avec_comp = (double)(fin-debut)/CLOCKS_PER_SEC;

//     printf("Nombre d'opérations sans comparaisons : %d \n",t1); 
//     printf("Nombre d'opérations avec comparaisons : %d \n", t2);
    
//     printf("Temps sans comparaisons : %f \n", temps_wit_comp); 
//     printf("Temps avec comparaisons : %f \n", temps_avec_comp); 


//     return 0; 
// }


//Q3 : With GNUPLOT 

int* init_tabool(int n){
    int* tabool = malloc((n+1)*sizeof(int));
    tabool[0] = 0; 
    tabool[1] = 0; 
    int i = 2; 
    while(i<=n){
        tabool[i] = 1; 
        i+=1; 
    } 
    return tabool; 
}

int main(int argc, char* argv[]){
    int n_min = 10000; 
    int n_max = 100000; 
    int pas   = 10000; 

    int n; 
    for(n = n_min; n <= n_max; n += pas){
        int* tabool_sans = init_tabool(n); 
        int nb_op_sans = eratosthene_3_sans_comp(tabool_sans, n); 
        free(tabool_sans); 

        int* tabool_avec = init_tabool(n); 
        int nb_op_avec = eratosthene_3_avec_comp(tabool_avec, n); 
        free(tabool_avec); 

        printf("%d\t%d\t%d\n", n, nb_op_sans, nb_op_avec); 
    }

    return 0; 
}