#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Q1 : 


// int main(int argc, char** argv){
//     for(int i = 0; i<argc; i+=1){
//         printf("%s ", argv[i]);
//     }
//     printf("\n");
// }


// Q2 : 


int calc_length(char chaine[]){
    int i = 0;
    int cpt=0;
    while(chaine[i]!=0){
        cpt ++;
        i++;
    }
    return cpt;
}

// int main(int argc, char** argv){
//     int taille = atoi(argv[1]);
//     int test_taille = calc_length(argv[2]);

//     printf("%d et %d\n", taille, test_taille);

//     return EXIT_SUCCESS;
// }


// Q3 : 

int comp(char chaine1[], char chaine2[]){
    int taille1 = calc_length(chaine1);
    int taille2 = calc_length(chaine2);

    if(taille1==taille2) return 0;
    if(taille1<taille2)return 1;
    return -1;
}

// Q4 :


int nb_voy(char* chaine, int n){
    
    int cpt =0;

    for(int i = 0; i<n; i+=1){
        switch (chaine[i])
        {
            case 'a': case 'A': case 'e': case'E': case'i': case'I':case'o':case'O':case'u':case'U':
                cpt +=1;
                break;
            default:
                break;
        }
    }
    return cpt;
}

