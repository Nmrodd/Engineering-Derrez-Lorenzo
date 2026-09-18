#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int* atoi_tab(char* chaine, int *taille){
    int n = strlen(chaine); 
    int i = 0; 

    int cpt = 0;
    int* tab = malloc(n*sizeof(int));
    while(i<n){
        if(chaine[i] != ' '){
            int j = i+1; 
            while(j<n && chaine[j] != ' '){
                j+=1; 
            }
            char chaine_i[j-i+1];
            int l = 0; 
            int temp = i;
            chaine_i[j-i] = 0; 
            while(l<(j-i)){
                chaine_i[l] = chaine[temp];
                l+=1; 
                temp+=1;
            }
            tab[cpt] = atoi(chaine_i);
            cpt++; 
            i = j;
        }
        else{
            i+=1;
        }
    }
    *taille=cpt;
    return tab;
}

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
    int taille; 
    while (i<argc){
        int* tab = atoi_tab(argv[i], &taille);
        affiche_tab(tab, taille);
        free(tab);
        i+=1; 
    }
}

// Q2 : 
#include <ctype.h>


int* atoi_tab2(char* chaine, int *taille){
    int n = strlen(chaine); 
    int i = 0; 

    int cpt = 0;
    int* tab = malloc(n*sizeof(int));
    while(i<n){
        if(isdigit(chaine[i])!=0){
            int j = i+1; 
            while(j<n && (isdigit(chaine[j])!=0)){
                j+=1; 
            }
            char chaine_i[j-i+1];
            int l = 0; 
            int temp = i;
            chaine_i[j-i] = 0; 
            while(l<(j-i)){
                chaine_i[l] = chaine[temp];
                l+=1; 
                temp+=1;
            }
            tab[cpt] = atoi(chaine_i);
            cpt++; 
            i = j;
        }
        else{
            i+=1;
        }
    }
    *taille=cpt;
    return tab;
}

int main(int argc, char** argv){
    int i = 1; 
    int taille; 
    while (i<argc){
        int* tab = atoi_tab2(argv[i], &taille);
        affiche_tab(tab, taille);
        free(tab);
        i+=1; 
    }
}