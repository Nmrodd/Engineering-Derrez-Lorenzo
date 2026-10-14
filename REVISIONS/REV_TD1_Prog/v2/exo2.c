#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Question 1 : 
//


void print_array(int* tab, int n){
	for(int i = 0; i<n; i+=1){
		printf("%d ", tab[i]); 
	}
	printf("\n"); 
}



// Question 2 : 
//

// Question 3 : 
//

void nb_premiers_pairs(int* tab, int n){
	int compteur = 0; 
	int i = 0; 
	while(compteur < n){
		if (i%2 == 0){
			tab[compteur] = i; 
			compteur +=1; 
		}
		i+=1; 
	}
}



// Test : 
//
//

int main(int argc, char** argv){
	int n = 4; 
	int tab[4] = {1, 2, 3, 4}; 

	print_array(tab, n); 


	int tab2[4]; 
	nb_premiers_pairs(tab2, n); 

	print_array(tab2, n); 


	return EXIT_SUCCESS; 
}
