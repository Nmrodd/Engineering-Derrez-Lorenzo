#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// question 1; 

int fibo_rec(int n){
    if(n<1){return 0;}
	if(n==1){return 1;}
	
	return fibo_rec(n-1)+fibo_rec(n-2); 
}

// Question 2:

// int main(int argc, char** argv){
//     if (argc>1){
//         for(int i = 1; i<argc; i+=1){
//             int n_i = atoi(argv[i]);
//             int t_i = fibo_rec(n_i);
//             printf("Le calcul fibo_rec pour %d est : %d\n", n_i, t_i);
//         }

//         return EXIT_SUCCESS;
//     }
//     else{
//         return EXIT_FAILURE;
//     }
// }

//Question 3:
int fibo_iter(int n){
	if (n == 0) return 0; 
	if (n ==1) return 1; 
	
	int memo[n+1];
	memo[0] = 0; 
	memo[1] = 1; 
	for(int i =2 ; i<=n; i+=1){
		memo[i] = memo[i-1] + memo[i-2];
	} 
	return memo[n]; 
}


// Test rapidité entre les deux : 

#include <time.h>

int main(int argc, char** argv){
    int n = 50; 

    // Pour le premier test récursif : 
    clock_t start = clock();
    int t_rec = fibo_rec(n);
    clock_t end = clock();

    double temps_rec = (double)(end-start)/CLOCKS_PER_SEC;

    printf("res rec: %d\n", t_rec);
    printf("temps rec : %f\n", temps_rec);

    // Pour le test itératif : 
    clock_t start_iter = clock();
    int t_iter = fibo_iter(n);
    clock_t end_iter = clock();

    double temps_iter = (double)(end_iter-start_iter)/CLOCKS_PER_SEC;


    printf("res iter: %d\n", t_iter);
    printf("temps iter : %f\n", temps_iter);


    return EXIT_SUCCESS;

}