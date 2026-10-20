#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Q1 : 
//


//int main(int argc, char** argv){
//	for (int i = 0; i<argc; i+=1){
//		printf("%s ", argv[i]); 
//	}
//	printf("\n");
//
//	return EXIT_SUCCESS;
//}

// Q2 
//
//


int give_length(char* chaine){
	int i = 0; 
	while(chaine[i] != 0){
		i++;
	}
	return i;
}


//int main(int argc, char** argv){
//	for(int i = 1; i<argc; i+=1){
//		int t_i = give_length(argv[i]); 
//		printf("La taille de %s est : %d\n", argv[i], t_i);
//	}int length_comp(char* chaine1, char* chaine2){
//         int t_1 = give_length(chaine1);
//         int t_2 = give_length(chaine2);
//         if(t_1 == t_2) return 0;
//         if (t_1 < t_2) return 1;
//         return -1;
// }

//}

// Q3 
//

int length_comp(char* chaine1, char* chaine2){
	int t_1 = give_length(chaine1);
	int t_2 = give_length(chaine2); 
	if(t_1 == t_2) return 0; 
	if (t_1 < t_2) return 1; 
	return -1; 
}


// Q4 :
//

int nb_vy(char* chaine){
	int taille = give_length(chaine);

	int cpt = 0;


	for(int i = 0; i<taille; i+=1){
		switch (chaine[i]){
			case 'a':
			case 'A':
				cpt +=1;
				break;
			case 'e':
			case 'E':
				cpt +=1;
				break;
			case 'i':
			case 'I':
				cpt +=1;
				break;
			case 'o':
			case 'O':
				cpt +=1;
				break;
			case 'u':
			case 'U':
				cpt +=1;
				break;
			default:
				break;
		}
	}
	return cpt;
}


int main(int argc, char** argv){
	for(int i = 1; i<argc;i+=1){
		int t_i = nb_vy(argv[i]); 
		printf("Le nombre de voyelles dans %s est : %d\n", argv[i], t_i);
	}
	return EXIT_SUCCESS;
}




