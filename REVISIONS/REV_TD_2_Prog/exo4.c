#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Q1 : 


void int_to_a(int a, char* resu){

    int buff = a;

    int odg = 1; 
    while(buff/10 > 0){
        odg+=1;
        buff /= 10;
    }

    resu[odg] = 0;

    for (int i = odg-1; i>=0; i-=1){
        resu[i] = '0' + (a%10);
        a/=10;
    }
}