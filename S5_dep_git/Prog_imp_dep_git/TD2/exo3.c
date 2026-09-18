#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//Q1 :

void chaine_miroir(char* chaine){
    int n = strlen(chaine); 
    int i = 0; 
    while(i<n){
        printf("%c", chaine[n-1-i]);
        i+=1;         
    }
    printf("\n");
}

// Autre méthode Q1 : 
char* chaine_miroir_update(char* chaine){
    int n = strlen(chaine); 
    int i = 0; 
    char* tab = malloc((n+1)*sizeof(char));
    tab[n] = 0;
    while(i<n){
        printf("%c", chaine[n-1-i]);
        tab[i] = chaine[n-1-i];
        i+=1;         
    }
    printf("\n");
    return tab;
}


int main(int argc, char** argv){
    int i = 1; 
    while(i<argc){
        chaine_miroir(argv[i]); 
        i+=1; 
    }
    return EXIT_SUCCESS;
}

// Q2 : 
// Etant donne que ma fonction de Q1 ne modifie jamais le tableau, je me suis contente de mettre const char* en modification

void chaine_miroir_2(const char* chaine){
    int n = strlen(chaine); 
    int i = 0; 
    while(i<n){
        printf("%c", chaine[n-1-i]);
        i+=1;         
    }
    printf("\n");
}

int main(int argc, char** argv){
    int i = 1; 
    while(i<argc){
        chaine_miroir(argv[i]); 
        i+=1; 
    }
    return EXIT_SUCCESS;
}
//Avec l'autre méthode : 

// Autre méthode Q1 : 
char* chaine_miroir_2_update(const char* chaine){
    int n = strlen(chaine); 
    int i = 0; 
    char* tab = malloc((n+1)*sizeof(char));
    tab[n] = 0;
    while(i<n){
        printf("%c", chaine[n-1-i]);
        tab[i] = chaine[n-1-i];
        i+=1;         
    }
    printf("\n");
    return tab;
}
