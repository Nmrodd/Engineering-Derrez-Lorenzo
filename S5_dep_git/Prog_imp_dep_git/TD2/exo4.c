#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Exercice 4 

// Q1 : 

void int_to_a(int code){
    int taille = 1; 
    int odg = 1;
    
    while(code>=odg*10){
        odg = odg*10;
        taille+=1;
    }

    char chaine[taille+1]; 
    chaine[taille] = 0;
    taille--; 
    
    int i = 0; 

    while(odg>0){
        char val = '0' + (code/odg);
        chaine[i] = val;
        code = code%odg;
        odg=odg/10;
        printf("%c", val);
        i+=1;
    }
    printf("\n");
}


// Q2 : 

// Extension avec les entiers signés : 
void int_to_a_signed(int code){
    if(code >= 0){
        int_to_a(code);
    }
    else{
        // Il faudrait seulement gérer le cas INT_MIN autrement car cette méthodde ne fonctionne pas pour lui
        printf("-");
        int_to_a(code-2*code);
    }
}
// Q3 : 
// Test des fonctions : 

// Test Q1 
int main(int argc, char** argv){
    int i = 1; 
    while(i<argc){
        int t_i = atoi(argv[i]);
        int_to_a(t_i);
        i+=1;
    }   
    return EXIT_SUCCESS;
}

// Test Q2 : 
