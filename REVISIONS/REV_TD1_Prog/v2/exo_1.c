#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


// Question 1 :
//

int pgcd_rec(int a, int b){
	if (b==0) return a;
	return pgcd_rec(b, a%b);	
}

// Question 2 : c'était des tests 
//
// Question 3 : 

int pgcd_iter(int a, int b){
	while(b>0){
		a = b; 
		b = a%b; 
	}
	return a; 

}



// Test : 
//

int main(int argc, char** argv)
{
	if (argc < 3){
		printf("Erreur dans les arguments"); 
		return EXIT_FAILURE;
	}
	else{
		int a = atoi(argv[1]); 
		int b = atoi(argv[2]); 
		int t1 = pgcd_iter(a,b);
		printf("Le pgcd rec de %d et %d est : %d\n", a, b, t1);
		
		
		
		return EXIT_SUCCESS; 
	}
}
