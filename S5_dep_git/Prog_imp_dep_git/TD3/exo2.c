#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/// Exercice 2 ///

// Q1 :

void affiche_table_ASCII65to90_Q1(){
    int i = 65; 
    printf(" Car.    dec.    hexa     octal\n");
    while(i<=90){
        printf("    %c      %d    0x%x     0%o\n", i, i, i, i);
        i+=1;
    }
}


//Q2 
const char* noms_controle[] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS",  "TAB", "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM",  "SUB", "ESC", "FS",  "GS",  "RS",  "US",
    "SP"   // 32 : l'espace, techniquement imprimable mais invisible
};

void affiche0_to_32(){
    printf(" Car.    dec.    hexa     octal\n");
    int i = 0; 
    while(i<=32){
        printf("    %-4s   %d    0x%x     0%o\n", noms_controle[i], i, i, i);
        i+=1;
    }
}

void affiche33_to127(){
    int i = 33; 
    while(i<=127){
        printf("    %c      %d    0x%x     0%o\n", i, i, i, i);
        i+=1;
    }
}

void affiche0_to_127_Q2(){
    affiche0_to_32();
    affiche33_to127();
}


// Q3 
void affiche128_to255(){
    // Il faut encoder soit meme les caractères en UTF 8 car sinon ce n'est pas gérer automatiquement et cela renvoit le caractère mojibake
}

void affiche0_to255(){
    affiche0_to_127_Q2();
    affiche128_to255();
}


int main(int argc, char** argv){
    // Q1 : 
    // affiche_table_ASCII65to90_Q1();

    // Q2 : 
    // affiche0_to_127_Q2();

    // Q3 : 
    

    return EXIT_SUCCESS;
}
