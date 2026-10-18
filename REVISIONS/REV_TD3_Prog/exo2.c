#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Q1 : 

void print_65to90(){
    // printf("Car. dec. hexa octal\n");
    for(int i = 65; i<91; i+=1){
        printf("%c %d 0x%x 0%o\n", i,i,i,i); 
    }
}

// int main(int argc, char** argv){
//     print_65to90();

//     return EXIT_SUCCESS;
// }

// Q2 :

void print_91to127(){
    for(int i = 91; i<128; i+=1){
        printf("%c %d 0x%x 0%o\n", i,i,i,i); 
    }
}

void print_32to64(){
    for(int i = 32; i<65; i+=1){
        printf("%c %d 0x%x 0%o\n", i,i,i,i); 
    }
}

const char* zero_a_tdeux[32] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS",  "HT",  "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM",  "SUB", "ESC", "FS",  "GS",  "RS",  "US"
};


void print_0to31(){
    for(int i = 0; i<32; i+=1){
        printf("%s %d 0x%x 0%o\n", zero_a_tdeux[i], i, i, i);
    }
}

int main(int agrc, char** argv){
    printf("Car. dec. hexa octal\n");

    print_0to31(); 
    print_32to64(); 
    print_65to90();
    print_91to127();

    return EXIT_SUCCESS;
}