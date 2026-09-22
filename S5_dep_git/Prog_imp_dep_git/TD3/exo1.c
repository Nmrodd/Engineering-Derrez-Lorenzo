#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/// Exerice 1 /// 


// Q1 : 

int est_bissextile(int annee){
    if((annee%4==0 && annee%100!=0) || annee%400==0){
        return 1;
    }
    else{
        return 0; 
    }
}


// int main(int argc, char** argv){
//     int i = 1; 
//     while(i<argc){
//         int t1 = est_bissextile(atoi(argv[i]));
//         if (t1 == 1){
//             printf("L'année %d est bissextile.\n", atoi(argv[i]));
//         }
//         else{
//             printf("L'année %d n'est pas bissextile.\n", atoi(argv[i]));
//         }
//         i+=1;
//     }
//     return EXIT_SUCCESS;
// }

// Q2 : 

// Pour faire ceci, il faudra regarder si l'année est bissextile, et regarder la parité du mois pour savoir si il faut dire 30 jours,ou 31.

void nb_jours(int annee, int mois){
    if (mois == 2){
        if (est_bissextile(annee)){
            printf("Le mois de février a 29 jours en année bissextile.\n");
        } else {
            printf("Le mois de février comptient 28 jours en année non bissextile.\n");
        }
    }
    else if (mois==1 || mois==3 || mois==5 || mois==7 ||
             mois==8 || mois==10 || mois==12){
        printf("Ce mois comptient 31 jours.\n");
    }
    else {
        printf("Ce mois contient 30 jours.\n");
    }
}

// int main(int argc, char** argv){
//     int i = 2;
//     while(i < argc){
//         nb_jours(atoi(argv[i-1]), atoi(argv[i])); 
//         i+=2;
//     }
//     return EXIT_SUCCESS;
// }

// Q3 : 

void affiche_jour(int y, int m, int d, char** jours){
    if(m>=3){
        int z = y;
        int D = (23*m)/9 + d + 4 + y + z/4 - z/100 + z/400 - 2;
        int idx = (D+6)%7;
        printf("Le jour de la semaine correspondant au %d/%d/%d est : %s.\n", d, m, y, jours[idx]);
    }
    else{
        int z = y-1;
        int D = (23*m)/9 + d + 4 + y + z/4 - z/100 + z/400;
        int idx = (D+6)%7;
        printf("Le jour de la semaine correspondant au %d/%d/%d est : %s.\n", d, m, y, jours[idx]);
    }
}

int main(int argc, char** argv){
    int i = 3; 
    char* jours[7] = {"Lundi", "Mardi", "Mercredi", "Jeudi","Vendredi", "Samedi", "Dimanche"};
    while(i<argc){
        affiche_jour(atoi(argv[i-2]), atoi(argv[i-1]), atoi(argv[i]), jours);
        i+=3;
    }
    return EXIT_SUCCESS;
}

// Q4 BONUS : 
