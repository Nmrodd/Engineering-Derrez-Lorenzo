#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Question 1 ; 


int is_sorted(int* array, int n){
    int i = 1;
    while(i<n && array[i-1]<=array[i]){
        i+=1;
    }
    return n==i;
}

// test Q1 : 

// int main(int argc, char** argv){
//     int n = 3; 
//     int tab[3] = {1, 2, 3};

//     int n2 = 4; 
//     int tab2[4] = {2, 1, 3, 4};

//     int t_1 = is_sorted(tab, n);
//     printf("%d\n", t_1);

//     int t_2 = is_sorted(tab2, n2); 
//     printf("%d\n", t_2);

//     return EXIT_SUCCESS;
// }

// Q2 : 

int is_element(int* array, int n, int elt){
    int res = 0;
    
    for(int i = 0; i<n; i+=1){
        if(array[i]==elt){
            res = 1;
        }
    } 
    return res;
}


// // Test Q2 : 

// int main(int argc, char** argv){
//     int n = 4; 
//     int tab[4] = {1, 2, 2, 4};

//     int t_1 = is_element(tab, n, 4);
//     printf("%d\n", t_1);

//     int t_2 = is_element(tab, n, 3);
//     printf("%d\n", t_2);

//     return EXIT_SUCCESS;
// }


// Q3 :

int rech_dic_rec(int* array, int n, int start, int end, int elt){
    if(start>end)return 0;
    
    int mid = (start+end)/2;
    if(array[mid]==elt)return 1;
    
    if(array[mid]>elt){
        return rech_dic_rec(array, n, start, end-1, elt);
    }
    return rech_dic_rec(array, n, start+1, end, elt);
}

// // Test Rapide : Q3 et Q4 car j'ai déjà fais la version récursive 
// int main(int argc, char** argv){
//     int n = 4; 
//     int tab[4] = {1, 2, 2, 4};

//     int start=0;
//     int end=n-1;

//     int t_1 = rech_dic_rec(tab, n,start,end, 4);
//     printf("%d\n", t_1);

//     int t_2 = rech_dic_rec(tab, n,start,end, 3);
//     printf("%d\n", t_2);

//     return EXIT_SUCCESS;
// }