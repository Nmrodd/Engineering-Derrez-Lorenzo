#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Q1 : 

//Implémentation du tri par sélection 

void selection_sort(int* tab, int n){
    int i = 0;

    int indx_ppvl = i;
    int buff_ppl = tab[0];

    while(i<n){
        int j = i+1; 
        indx_ppvl = i;
        buff_ppl = tab[i];
        while(j<n){
            if(tab[j] < buff_ppl){
                buff_ppl = tab[j];
                indx_ppvl = j;
            }
            j+=1; 
        }
        int buff = tab[i]; 
        tab[i] = buff_ppl; 
        tab[indx_ppvl] = buff;
        i+=1;
        
    }
}

// Test Q1 : 

void affiche_tab(int* tab, int n){
    int i = 0; 
    while(i<n){
        printf("%d ", tab[i]);
        i+=1;
    }
    printf("\n");
}

int main(int argc, char** argv){
    int i = 1; 
    int* tab = malloc((argc-1)*sizeof(int));
    while(i<argc){
        int x = atoi(argv[i]);
        tab[i-1] = x; 
        i+=1;
    }
    affiche_tab(tab, argc-1);
    selection_sort(tab, argc-1);
    affiche_tab(tab, argc-1);
    free(tab);
}   

// Q2 : 

void lexico_sort(char** tab, int n){
    int i = 0; 

    int indx_ppl = 0; 
    char* buff_ppl = tab[0];

    while(i<n){
        int j = i+1; 
        indx_ppl = i; 
        buff_ppl = tab[i];
        while(j<n){
            if(strcmp(buff_ppl, tab[j]) > 0){
                buff_ppl = tab[j]; 
                indx_ppl = j; 
            }
            j+=1;
        }
        char* buff = tab[i]; 
        tab[i] = buff_ppl; 
        tab[indx_ppl] = buff; 
        i+=1;
    }
}

void affiche_tab_char(char* chaine){
    int n = strlen(chaine); 
    int i = 0; 
    while(i<n){
        printf("%c",chaine[i]);
        i+=1;
    }
    printf("\n");
}

int main(int argc, char** argv){
    lexico_sort((argv+1), argc-1); // Ici il faut décaler le pointeur pour éviter de prendre en compte ./exo6_exec dans le tri. Il faut alors diminuer la taille de argc. 
    int i = 1; 
    while(i<argc){
        affiche_tab_char(argv[i]); 
        i+=1;
    }
    return EXIT_SUCCESS;
}
