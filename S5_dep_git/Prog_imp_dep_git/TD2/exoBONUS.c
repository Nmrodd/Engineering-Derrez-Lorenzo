#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


// Faire atoi qui étant donné une chaine de caract. renvoie l'entier qui est dedans 

// Gestion des cas pathologiques : 
    // 0 
    // Distinguer les négatifs et positifs 
int puiss_10(int n) {
    int i = 0;
    int res = 1;

    while (i < n) {
        res = res * 10;
        i++;
    }

    return res;
}

int atoi_bonus(char* chaine){
    int taille = strlen(chaine);

    if(chaine[0] == '0' && taille==1){
        return 0;
    }
    if(chaine[0] == '-'){
        
        int i = 1; 

        int ent = 0; 

        while(i<taille && chaine[i] != 0){
            ent += (chaine[i] - '0') * puiss_10(taille-i-1);
            i+=1;
        }
        return -ent;
    }
    else{
        int i = 0;
        int ent = 0;

        while(i<taille && (chaine[i] - '0') != 0){
            ent += (chaine[i] - '0') * puiss_10(taille-i-1);
            i+=1;
        }
        return ent;
    }
}

// "-342" -> - 3 * 100 + 4 * 10 + 2 * 1
// "342"  -> 3 * 100 + 4 * 10 + 2 * 1 


int main(int argc, char** argv){
    int i = 1; 
    
    while(i<argc){
        int test_i = atoi_bonus(argv[i]);
        printf("%d\n", test_i);
        i+=1;
    }

    return EXIT_SUCCESS;
}


// correction itoa pour marcher avec une conversion binaire sans écrire une deuxieme fonction 