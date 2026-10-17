#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


int give_length(char* chaine){
	int i = 0; 
	while(chaine[i] != 0){
		i++;
	}
	return i;
}




//Q1:
//


int test_palindrome(char* chaine1, int taille){
	int mid = taille/2; 

	int cpt = 0; 


	for(int i = 0; i<mid; i+=1){
		if (chaine1[i] == chaine1[taille-i-1]) cpt +=1;
	}
	if(cpt == mid){
		return 1;
	}
	return 0;
}

// int main(int argc, char** argv){

// 	for(int i = 0; i<argc; i+=1){
// 		int taille_i = give_length(argv[i]);
// 		int t_i = test_palindrome(argv[i], taille_i);
// 		if (t_i){
// 			printf("Le mot %s est un palindrome.\n", argv[i]);
// 		}
// 		else{
// 			printf("Le mot %s n'est pas un palindrome.\n", argv[i]);
// 		}
// 	}

// 	return EXIT_SUCCESS;
// }


// Q2 : 

int test_isalpha(char car){
	if((car >=  'A' && car <= 'Z') || (car >= 'a' && car <= 'z')) return 1;
	return 0;
}

// Q3 : 

char to_low(char car) {
    if (car >= 'A' && car <= 'Z') {
        return car - 'A' + 'a';
    }
    return car;
}

// Q4 : 

// Il suffit de faire un pointeur a gauche et un a droite puis d'incrémenter les compteurs tant que l'on a pas une lettre de l'alphabet et dans ce cas appliquer tolowerpour effectuer la comparaison et incrémenter le compteur 

