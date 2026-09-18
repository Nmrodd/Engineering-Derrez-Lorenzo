#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Exercice 2 : 

// Q1 : 

int est_palindrome(char* chaine){
    int n = strlen(chaine); 
    int i = 0; 
    int parcours = n/2; 

    int cpt = 0; 

    while(i<parcours && (chaine[i] == chaine[n-1-i])){
        i+=1; 
        cpt+=1; 
    }
    
    if(cpt == parcours){
        return 1; 
    }
    return 0; 
}

// Test Q1 

// int main(int argc, char** argv){
//     int i = 1; 
//     while(i < argc){
//         int test_i = est_palindrome(argv[i]);
//         if (test_i == 1){
//             printf("%s est un palindrome.\n", argv[i]);
//         }        
//         else{
//             printf("%s n'est pas un palindrome. \n", argv[i]);
//         }
//         i+=1; 
//     }
//     return EXIT_SUCCESS;
// }

// Q2 : 
// #include <ctype.h>

// int is_in_alph(char caractere)
// {
//     return isalpha(caractere);
// }

int is_in_alph(char caractere)
{
    if ((caractere >= 'a' && caractere <= 'z') ||
        (caractere >= 'A' && caractere <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Test Q2 : 
int main(int argc, char** argv){
    int i = 0; 
    while(i<argc){
        int n_i = strlen(argv[i]); 
        int j = 0; 
        while(j<n_i){
            int test_i = is_in_alph(argv[i][j]); 
            if(test_i){
                printf("%c est dans l'alphabet. \n", argv[i][j]);
            }
            else{
                printf("%c n'est pas dans l'alphabet. \n", argv[i][j]);
            }
            j+=1;
        }
        i+=1;
    }
    return EXIT_SUCCESS;
}

// Q3 : 
char maj_to_min(char car)
{
    if (car >= 'A' && car <= 'Z')
    {
        return car + ('a' - 'A');
    }
    else
    {
        return car;
    }
}

int main(int argc, char **argv)
{
    int i = 1;

    while (i < argc)
    {
        int n_i = strlen(argv[i]);
        int j = 0;

        while (j < n_i)
        {
            char test_j = maj_to_min(argv[i][j]);

            printf("%c", test_j);

            j += 1;
        }

        printf("\n");
        i += 1;
    }

    return 0;
}

// Q4 : 

// Amélioration de la fonction palindrome : 

int est_palindrome_update(char* chaine){
    int n = strlen(chaine); 
    int g = 0;
    int d = n-1;

    while(g<d){
        while(is_in_alph(chaine[g]) == 0 && g<d){
            g+=1;
        }
        while(is_in_alph(chaine[d]) == 0 && g<d){
            d-=1;
        }
        if(g>d){
            break;
        }
        if(maj_to_min(chaine[g]) == maj_to_min(chaine[d])){
            d-=1;
            g+=1;
        }
        else{
            return 0;
        }
    }
    return 1;
}
