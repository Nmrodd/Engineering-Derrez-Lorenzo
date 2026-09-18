#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//// Exercice 1 //////

// Q1 
int main(int argc, char* argv[]){
    int i = 1; 
    while(i<argc){ 
        printf("%s \n", argv[i]);
        i+=1;
    }
    return EXIT_SUCCESS;
}

// Q2

int calc_taille1(int argc, char* argv[]){
    if(argc>1){
        int taille = 0;
        int i = 0; 
        while(argv[1][i] != 0){
            taille +=1;
            i +=1; 
        }
        return taille;
    }
    else{
        return 0;
    }
}


int calc_taille2(int argc, char* argv[]){
    if(argc>1){
        return strlen(argv[1]);
    }
    else{
        return 0;
    }
}

// Q3
int lengthcompare(int argc, char* argv[]){
    if(argc>2){
        int taille1 = strlen(argv[1]);
        int taille2 = strlen(argv[2]);

        if(taille1>taille2){return taille1;}
        else{return taille2;}
    }
    else{
        if(argc==2){
            return strlen(argv[1]);
        }
        else{return 0;}
    }
}

//Q4
int est_voyelle(char caractere){
    if (caractere == 'a' || caractere == 'e' ||
        caractere == 'i' || caractere == 'o' ||
        caractere == 'u' || caractere == 'y' ||
        caractere == 'A' || caractere == 'E' ||
        caractere == 'I' || caractere == 'O' ||
        caractere == 'U' || caractere == 'Y')
    {
        return 1;
    }
    return 0;
}

int nb_voy(char *chaine){
    int n = strlen(chaine);
    int nb = 0;
    int i = 0;

    while (i < n)
    {
        if (est_voyelle(chaine[i]) == 1)
        {
            nb++;
        }
        i++;
    }
    return nb;
}


// int main(int argc, char* argv[]){
//     int test1 = calc_taille2(argc, argv);
//     printf("%d\n", test1);
//     return 0;
// }

// Test Q3 : 
int main(int argc, char* argv[]){
    int i = 1; 
    while(i<argc){
        int test = nb_voy(argv[i]);
        printf("%d\n", test);
        i+=1; 
    }
    return EXIT_SUCCESS;
}

