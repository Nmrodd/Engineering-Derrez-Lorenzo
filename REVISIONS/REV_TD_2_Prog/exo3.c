#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>



// Q1 : 

void chaine_miroir(int taille, char* chaine){
    for(int i = 0; i<taille/2; i+=1){
        char buff = chaine[i]; 
        chaine[i] = chaine[taille-i-1]; 
        chaine[taille-i-1] = buff;
    }
}

int main(void) {
    char mots[][20] = {"abcd", "abcde", "A", ""};
    char attendus[][20] = {"dcba", "edcba", "A", ""};

    for (int i = 0; i < 4; i++) {
        printf("\"%s\" -> ", mots[i]);

        chaine_miroir((int)strlen(mots[i]), mots[i]);

        printf("\"%s\" | attendu : \"%s\" | %s\n",
               mots[i],
               attendus[i],
               strcmp(mots[i], attendus[i]) == 0 ? "OK" : "ECHEC");
    }

    return 0;
}