#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Question 1 : 

int sum_elements(int* tab, int n){
	int sum = 0; 
	for (int i = 0; i<n; i+=1){
		sum = sum + tab[i]; 
	}
	return sum; 

}

// Question 2 : 
//


int scalar_product(int* tab1, int n, int* tab2){
	int ps = 0; 

	for(int i = 0; i<n; i+=1){
		ps += tab1[i]*tab2[i]; 	
	}
	return ps; 
}



// Question 3 :
//


int sum_elt_to_elt(int* tab1, int n, int* tab2){
	int sum = 0; 
	for(int i =0; i<n; i+=1){
		sum += tab1[i]+tab2[i]; 
	}
	return sum; 
}



// Test : 

void print_array(int* tab, int n){
	for(int i = 0; i<n; i+=1){
		printf("%d ", tab[i]); 
	}
	printf("\n");

}


int main(int argc, char** argv){
	
	int n = atoi(argv[1]); 

	int tab[n]; 

	for (int i = 0; i<n; i+=1){
		tab[i] = atoi(argv[2+i]); 
	}

	int t1 = sum_elements(tab, n); 
	printf("%d \n", t1);
	
	int tab2[n]; 

	for (int j = 0; j<n; j+=1){
		tab2[j] = atoi(argv[n+1-j]); 
	}

	int ps1 = scalar_product(tab, n, tab2);
	printf("%d\n", ps1);

	int s1 = sum_elt_to_elt(tab, n, tab2);
       	printf("%d\n", s1); 	


	return EXIT_SUCCESS; 

}





