#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//// Exercice 6 //// 
///
///



// Question 1 : 
//
//

int fibo_rec(int n){
	if(n<1){return 0;}
	if(n==1){return 1;}
	
	return fibo_rec(n-1)+fibo_rec(n-2); 
		
}



// Test Q1 //


int main(int argc, char** argv){
	int test1 = atoi(argv[1]);
	int test2 = atoi(argv[2]); 
	int test3 = atoi(argv[3]); 

	int r1 = fibo_rec(test1);
	int r2 = fibo_rec(test2); 
	int r3 = fibo_rec(test3); 

	printf("%d %d %d\n", r1, r2, r3);

	return EXIT_SUCCESS;	
}


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




