#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Exo 1 : Calendrier 

// Q1 : 

int est_bissextile(int annee) {
    return (annee % 400 == 0) ||
           (annee % 4 == 0 && annee % 100 != 0);
}

// int main(int argc, char** argv){
//     for(int i = 1; i<argc; i+=1){
//         int test_i =  est_bissextile(atoi(argv[i]));
//         if(test_i){printf("L'année %s est bissextile.\n", argv[i]);}
//         else{printf("L'année %s n'est pas bissextile.\n", argv[i]);}
//     }

//     return EXIT_SUCCESS;
// }


// Q2 :

void print_nb_restants(int mois, int annee){
    if (mois==2){
        if(est_bissextile(annee)){
            printf("Le mois de février comporte 29 jours.\n");
        }
        else{
            printf("Le mois de février de cette année comporte 28 jours.\n");
        }
    }
    else{
        switch (mois){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                printf("Ce mois comporte 31 jours.\n");
                break;
            default:
                printf("Ce mois comporte 30 jours.\n");
        }
    }
}

// int main(int argc, char** argv){
//     int mois1 = 2; 
//     int annee1 = 2000; 
//     print_nb_restants(mois1,annee1);

//     int annee2 = 2010; 
//     print_nb_restants(mois1, annee2);

//     int mois3 = 7; 
//     print_nb_restants(mois3, annee2);

//     return EXIT_SUCCESS;
// }

// Q3 : 


