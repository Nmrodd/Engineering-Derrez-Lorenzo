#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Ecriture de la fonction PGCD // 

// Question 1 : de manière récursive 


int pgcd_rec(int a, int b){
    if (b==0){
        return a;
    }
    else{
        return pgcd_rec(b, a%b);
    }
}


// Q2 : 
// Test rapide pour Q1 :

// int main(int argc, char** argv){
//     int i = 2; 
//     while(i<argc){
//         int a_i = atoi(argv[i-1]);
//         int a_i2 = atoi(argv[i]);
//         int t_i = pgcd_rec(a_i, a_i2);
//         printf("Le pgcd des entiers %d et %d est : %d\n", a_i, a_i2, t_i); 
//         i+=2;
//     }
//     return EXIT_SUCCESS; 
// }


// Q3 : 

// Pour procéder à l'implémentation de la fonction pgcd de manière itérative, il suffit de faire une boucle while avec une gestion des condition b > 0 

int pgcd_iter(int a, int b){

    while(b!=0){
        int r = a%b;
        a = b; 
        b = r;
    }
    return a; 
}


// Q4 : 
// Test Q3 : 

// Test rapide pour Q3:

int main(int argc, char** argv){
    int i = 2; 
    while(i<argc){
        int a_i = atoi(argv[i-1]);
        int a_i2 = atoi(argv[i]);
        int t_i = pgcd_iter(a_i, a_i2);
        printf("Le pgcd des entiers %d et %d est : %d\n", a_i, a_i2, t_i); 
        i+=2;
    }
    return EXIT_SUCCESS; 
}
