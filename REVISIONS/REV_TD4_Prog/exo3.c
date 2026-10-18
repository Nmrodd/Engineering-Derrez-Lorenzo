#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Q1 : variante de strcpy

char* stpcopy(const char* src, char* dst){
    int i = 0; 
    while(src[i] != 0){
        dst[i] = src[i]; 
        i+=1;
    }
    dst[i] = 0;
    return dst;
}


void print_chaine(const char* chaine){
    int i = 0;
    while(chaine[i] != 0){
        printf("%c", chaine[i]);
        i+=1;
    }
    printf("\n");
}

// // test : 

// int main(int argc, char** argv){
//     const char* src = "aba";
//     char dst[4];

//     stpcopy(src, dst);
//     print_chaine(dst);

//     return EXIT_SUCCESS;
// }

// Q2 : 

