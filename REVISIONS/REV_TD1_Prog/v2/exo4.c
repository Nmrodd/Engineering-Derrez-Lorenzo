#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Question 1 : 
//
//


int est_triee(int* tab, int n){
	int res = 1;
	for(int i = 1; i<n; i+=1){
		if (tab[i-1] > tab[i]) res = 0; 
	}

	return res; 
}


// Question 2 : 
//

int is_elt(int* tab, int n, int x){
	int res = 0; 
	for (int i = 0; i<n; i+=1){
		if (tab[i] == x){
			res = 1; 
		}	
	}
	return res; 
}


// Question 3 :  (Et Q4 car c'est déja la version récursive)


int rech_dich(int* tab, int n, int x, int debut, int fin){
	if (debut>fin){
		return 0;
	}
	int mid = (debut+fin)/2; 
	if ( x == tab[mid]) return 1; 
	if ( x < tab[mid]) return rech_dich(tab, n, x, debut, mid-1); 
	return rech_dich(tab, n, x, mid+1, fin); 
}


// test rapide : 
//
//
int main(int argc, char** argv){
	int n = 4; 

	int tab1[4] = {1, 2, 3, 4}; 

	int tab2[4] = {3, 2, 5, 6}; 

	int trie1 = est_triee(tab1, n); 
	printf("%d\n", trie1); 

	int trie2 = est_triee(tab2, n); 
	printf("%d\n", trie2); 

	int is1 = is_elt(tab1, n, 4); 
	printf("%d\n", is1); 

	int is2 = is_elt(tab2, n, 4); 
	printf("%d\n", is2); 

	int deb = 0; 
	int fin = n-1; 

	int dich1 = rech_dich(tab1, n, 4, deb, fin); 
       	printf("%d\n", dich1); 

	int dich2 = rech_dich(tab2, n, 4, 0, n-1); 
	printf("%d\n", dich2); 

	return EXIT_SUCCESS; 
}

