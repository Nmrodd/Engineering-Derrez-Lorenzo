#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Exercice 5 : 


// Question 1 : 

void pascal_ligne(int n, int valeurs[]){
	
	for(int i = n-1;  i>0; i-=1){
		valeurs[i] = valeurs[i] + valeurs[i-1]; 
	}
}

void print_pascal(int n, int valeurs[]){
	for(int i = 0; i<n; i+=1){
		printf("%d ", valeurs[i]); 
	}
	printf("\n"); 
}

// Question 2: 


void affiche_pascal(int n, int valeurs[]){	
	for(int i = 1; i<=n; i+=1){ 
		pascal_ligne(i, valeurs);
	       	print_pascal(i, valeurs); 	
	}	
}


// Test rapide : 
//


int main(int argc, char** argv){

	 
	int tab[12]; 
	tab[0] = 1; 
	tab[1] = 2; 
	tab[2] = 1;	
	tab[3] = 0;
	int n = 4; 

	pascal_ligne(n, tab); 
	print_pascal(n, tab); 

	int tab2[12]; 
	tab2[0] = 1;
	affiche_pascal(n, tab2); 
	 

	return EXIT_SUCCESS; 
}
