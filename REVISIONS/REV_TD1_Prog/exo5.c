#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>



// Ceci est l'exo 5 : Triangle de Pascal Révision TD 1 // 


// Question 1 : 


void pascal_ligne(int n, int valeurs[])
{
	// Pour pouvoir faire avec uniquement le tableau valeurs, il faut supposer qu'il contienne deja une taille adaptée
	
	for(int i = n; i >=1; i-=1){
		int buff = valeurs[i]; 
		valeurs[i] = valeurs[i-1] + buff; 
	}

}



// Test Q1 : 

void afficher_ligne(int n, int valeurs[]){
	for(int i = 0; i < n; i+=1)
	{
		printf("%d ", valeurs[i]); 
	}
	printf("\n");
}

//int main(int argc, char** argv)
//{
//
//	int valeurs[12];
//	valeurs[0] = 1; 
//	pascal_ligne(2, valeurs);
//
//	// Affichage du tableau : 
//	afficher_ligne(2, valeurs); 
//
//	return EXIT_SUCCESS;
//		
//}


// Question 2 : 
//

void affiche_pascal(int n, int valeurs[]){
	for(int i = 0; i<n; i+=1){
		pascal_ligne(i, valeurs);
		afficher_ligne(i+1, valeurs);
	}
}


// Test Q2 : 

#define MAX_CONST 100


int main(int argc, char** argv){
	int n = 5; 	
	int valeurs[12] = {1};

	affiche_pascal(n, valeurs);

	return EXIT_SUCCESS; 

}



