#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>



// Q1 :
enum color {NOIR, MARRON, ROUGE, ORANGE, JAUNE, VERT, BLEU, VIOLET, GRIS, BLANC, KIND_COUNT};


// Ajout d'une fonction pour afficher le texte 

const static char* txt[KIND_COUNT] = {"NOIR", "MARRON", "ROUGE", "ORANGE", "JAUNE", "VERT", "BLEU", "VIOLET", "GRIS", "BLANC"};

const char* renvoit_txt(enum color k){
    if (k>=0 && k < KIND_COUNT){
        return txt[k];
    }
    else{
        printf("index out of bounds\n");
        return NULL;
    }
}


// Q2 :

int times_pow10(int n, int p){
    int calc = 1;
    for(int i = 0; i<p; i+=1){
        calc = calc*10;
    }
    return n*calc;
}


// Q3 :
// en fonction de 3 couleurs doit renvoyer la valeur de la résistance 

int valeur_resistance(enum color k1, enum color k2, enum color k3){
    return times_pow10(k1*10+k2, k3);
}


// Q4 :
int index_of(char** chaines, int nb_chaines, char* elt){
    for(int i = 0; i<nb_chaines; i+=1){
        if(strcmp(elt, chaines[i])==0){
            return i;
        }
    }
    return -1;
}

// Q5 :

void print_value_res(enum color k1, enum color k2, enum color k3){
    int res = valeur_resistance(k1, k2, k3);
    printf("La vlaeur de la résistance, pour les couleurs %s %s et %s est : %d\n",renvoit_txt(k1), renvoit_txt(k2), renvoit_txt(k3), res);
}