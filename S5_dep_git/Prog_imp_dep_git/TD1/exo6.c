#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Q1 
int fibo_rec(int x){
    if(x<1)return 0;
    if(x==1)return 1;
    if(x>1){
        return fibo_rec(x-1)+fibo_rec(x-2); 
    }
    // Return -1 pour respecter la signature de la fonction fibo_rec 
    return -1;
}

// Q2 Main after Q3

// Q3 

int fibo_iter(int x, int* memo){
    memo[0] = 0;
    memo[1] = 1; 
    
    int i = 2; 
    while(i<=x){
        memo[i] = memo[i-1]+memo[i-2]; 
        i+=1; 
    }
    return memo[x]; 
}

// Q4 
// We have to add date_time to determinate during the execution thanks to main function which method is the fastest
#include <time.h>

int main(int argc, char* argv[]){

    int x;
    int resultat_rec;
    int resultat_iter;

    clock_t debut;
    clock_t fin;

    double temps_rec;
    double temps_iter;

    int memo[46];


    // Test avec x = 10
    x = 10;

    debut = clock();
    resultat_rec = fibo_rec(x);
    fin = clock();

    temps_rec = (double)(fin - debut) / CLOCKS_PER_SEC;

    debut = clock();
    resultat_iter = fibo_iter(x, memo);
    fin = clock();

    temps_iter = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("x = %d\n", x);
    printf("fibo_rec  : %d\n", resultat_rec);
    printf("temps     : %f secondes\n", temps_rec);
    printf("fibo_iter : %d\n", resultat_iter);
    printf("temps     : %f secondes\n\n", temps_iter);


    // Test avec x = 20
    x = 20;

    debut = clock();
    resultat_rec = fibo_rec(x);
    fin = clock();

    temps_rec = (double)(fin - debut) / CLOCKS_PER_SEC;

    debut = clock();
    resultat_iter = fibo_iter(x, memo);
    fin = clock();

    temps_iter = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("x = %d\n", x);
    printf("fibo_rec  : %d\n", resultat_rec);
    printf("temps     : %f secondes\n", temps_rec);
    printf("fibo_iter : %d\n", resultat_iter);
    printf("temps     : %f secondes\n\n", temps_iter);


    // Test avec x = 30
    x = 30;

    debut = clock();
    resultat_rec = fibo_rec(x);
    fin = clock();

    temps_rec = (double)(fin - debut) / CLOCKS_PER_SEC;

    debut = clock();
    resultat_iter = fibo_iter(x, memo);
    fin = clock();

    temps_iter = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("x = %d\n", x);
    printf("fibo_rec  : %d\n", resultat_rec);
    printf("temps     : %f secondes\n", temps_rec);
    printf("fibo_iter : %d\n", resultat_iter);
    printf("temps     : %f secondes\n\n", temps_iter);


    // Test avec x = 40
    x = 40;

    debut = clock();
    resultat_rec = fibo_rec(x);
    fin = clock();

    temps_rec = (double)(fin - debut) / CLOCKS_PER_SEC;

    debut = clock();
    resultat_iter = fibo_iter(x, memo);
    fin = clock();

    temps_iter = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("x = %d\n", x);
    printf("fibo_rec  : %d\n", resultat_rec);
    printf("temps     : %f secondes\n", temps_rec);
    printf("fibo_iter : %d\n", resultat_iter);
    printf("temps     : %f secondes\n\n", temps_iter);


    return 0;
}

//x = 10
//fibo_rec  : 55
// temps     : 0.000002 secondes
// fibo_iter : 55
// temps     : 0.000001 secondes

// x = 20
// fibo_rec  : 6765
// temps     : 0.000061 secondes
// fibo_iter : 6765
// temps     : 0.000001 secondes

// x = 30
// fibo_rec  : 832040
// temps     : 0.008850 secondes
// fibo_iter : 832040
// temps     : 0.000001 secondes

// x = 40
// fibo_rec  : 102334155
// temps     : 1.051600 secondes
//fibo_iter : 102334155
//temps     : 0.000001 secondes