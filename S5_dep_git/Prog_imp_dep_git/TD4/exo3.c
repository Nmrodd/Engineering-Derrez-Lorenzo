#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//Exercice 3 

// Le but est d'écrire en n'utilisant que la notation pointeur : 

// Q1 : 

// stpcpy() en C copie la chaine source dans la destination.
char* stpcpy_pointeur(char* dst, const char* src){
    // Il faut écraser src dans dst 
    int i = 0; 
    while(src[i] != 0){
        dst[i] = src[i]; 
        i+=1;
    }
    dst[i+1] = 0;
    return dst; 
}

// Q2 : 
// size_t strlen(const char* s) retourne la taille de la chaine s 

size_t strlen_pointeur(const char* s){
    size_t taille; 
    int i = 0; 
    while(s[i] != 0){
        taille++;
    }
    return taille;
}

int main(int argc, char** argv){
    // Test stcpy : 

    // Test size_t : 
    for(int i = 1; i<argc; i+=1){
        
    }


    return EXIT_SUCCESS;
}