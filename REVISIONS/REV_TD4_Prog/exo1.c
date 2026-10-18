#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Q1 : 

void swap(int* p, int* x){
    int buff = *p; 
    *p = *x; 
    *x = buff; 
}

// Q2 : 

void order(int *p, int* x){
    if (*p > *x){
        swap(p,x);
    }
}