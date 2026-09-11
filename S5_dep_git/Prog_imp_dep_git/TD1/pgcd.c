
//// Exercice 1 //// 

// Q1 : 
int pgcd_rec(int a, int b){
    if (b == 0){
        return a; 
    }
    else{
        int r = a%b; 
        return pgcd_rec(b, r); 
    }
     
}

//Q3 :
int pgcd_iter(int a, int b){
    ///
}

// Test : 
int main(int argc, char* argv[]){
    int x1 = 15; 
    int x2 = 3; 
    int t1 = pgcd_rec(x1, x2); 
    printf("Test 1 result : %d\n", t1); 
    
    int y1 = 4; 
    int y2 = 8; 
    int t2 = pgcd_rec(y1, y2); 
    printf("Test 2 result : %d\n", t2);

    int z1 = 10; 
    int z2 = 0; 
    int t3 = pgcd_rec(z1, z2); 
    printf("Test 3 result : %d\n", t3); 
    return 0; 
}

