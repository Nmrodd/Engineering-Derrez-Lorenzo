#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


// Question 1 : 


int pgcd_rec(int a, int b){
    if(b==0)return a;
    return pgcd_rec(b, a%b);
}


// Question 2 :
// // Test : 
// int main(int argc, char** argv){
//     int a = atoi(argv[1]);
//     int b = atoi(argv[2]);
//     int t_i = pgcd_rec(a,b);
//     printf("%d\n", t_i);
//     return EXIT_SUCCESS;
// }

// Question 3 : 

int pgcd_iter(int a, int b){
    while(b>0){
        int r  = a%b;
        a = b; 
        b = r;
    }
    return a;
}

// // Test ; 
 
// int main(int argc, char** argv){
//     int a = atoi(argv[1]);
//     int b = atoi(argv[2]);
//     int t_i = pgcd_iter(a,b);
//     printf("%d\n", t_i);
//     return EXIT_SUCCESS;
// }