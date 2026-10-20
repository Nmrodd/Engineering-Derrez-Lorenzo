#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


/// Question 1 ///

//////// IMPLEMENTATION DE LA STRUCTURE //////////


// Convention pour le status : 
enum status {EQUIPE1, EQUIPE2, NUL, PASJOUEE, KIND_COUNT};

static const char* txt[KIND_COUNT] = {"EQUIPE1", "EQUIPE2", "NUL", "PAJOUEE"};

const char* renvoit_status(enum status k){
    if(k>=0 && k<KIND_COUNT){
        return txt[k];
    }
    else{
        return NULL;
    }
}

struct game{
    char* teams[2];
    int scores[2]; // score equipe1 =  scores[0]; score equipe2 = scores[1]
    enum status state;
};


////////// IMPLEMENT METHODS ////////// 

/// Question 2 ///

struct game make_game(char* t1, char* t2){
    struct game match_nonDisputee; 

    match_nonDisputee.teams[0] = t1;
    match_nonDisputee.teams[1] = t2;
    match_nonDisputee.state = 3;

    // (void)match_nonDisputee.scores;
    match_nonDisputee.scores[0] = 0;
    match_nonDisputee.scores[1] = 0;

    return match_nonDisputee;
}

/// Question 3 ///

char* winner(struct game match){
    if ((match.state == 2) || (match.state == 3)){
        return NULL;
    }
    else{
        if(match.state==0){
            return match.teams[0];
        }
        else{
            return match.teams[1];
        }
    }
}


/// Question 4 ///

void print_game(struct game match){
    printf("%s\t-\t%s\t", match.teams[0], match.teams[1]);
}


void print_results(struct game match){
    if(match.state != 3){

        char* win = winner(match);

        if (win == NULL) {
            printf("%d\t-\t%d\n", match.scores[0], match.scores[1]);
        }
        else if (strcmp(match.teams[0], win) == 0) {
            printf("%d*\t-\t%d\n", match.scores[0], match.scores[1]);
        }   
        else {
            printf("%d\t-\t%d*\n", match.scores[0], match.scores[1]);
        }
    }
    else{
        printf("Match pas encore jouée entre les deux équipes %s et %s.\n", match.teams[0], match.teams[1]);
    }
}

/// Question 5 ///

void print_games(struct game tableaux_de_match[], int nb_matchs){
    for(int i = 0; i<nb_matchs; i+=1){
        print_game(tableaux_de_match[i]);
    }
}

/// Question 6 /// 

// H1 : players%2==0;
// H2 : teams is sorted -> order by Desc
// H3 : length(games) >= players/2

int make_tournament(int players, char* teams[], struct game games[]){
    int mid = players/2;
    for(int i = 0; i<mid; i+=1){
        games[i] = make_game(teams[i], teams[players-i-1]);
    }
    
    return mid;
}

/// Question 7 /// 

// Pour qu'un tournoi soit complet, il faut : 
    // n soit une puissance de 2 (pour la découpe)
    // Sinon il faut trouver la puissance de 2 la plus proche de n (arrondi inférieur)
//

int nb_tournoi_condition(int n){
    int res = 1; 
    while(res<=n){
        res *=2;
    }
    return res/2; // pour l'arrondie inférieur
}

/// Question 8 /// 

int make_pool(int players, char* teams[], struct game games[]){
    int nb_matchs = 0;

    for(int i = 0; i<players; i+=1){
        for(int j = 0; j<players; j+=1){
            if (i!=j){
                games[nb_matchs] = make_game(teams[i], teams[j]);
                nb_matchs+=1;
            }
        }
    }
    return nb_matchs;
}

/// Question 9 /// 




////// MAIN ////// 

int main(int argc, char** argv){

    //// For the first methods: ////

    char* t1 = (argc>1) ? argv[1] : "PSG";
    char* t2 = (argc>2) ? argv[2] : "BARCA";

    struct game match_foot1 = make_game(t1,t2);
    print_game(match_foot1);

    printf("\n");

    match_foot1.state = 0;
    match_foot1.scores[0] = 1;

    print_results(match_foot1);

    printf("\n");

    //// Test : Array of games ////

    char* t3 = (argc>3) ? argv[3] : "ASVEL";
    char* t4 = (argc>4) ? argv[4] : "PARIS-BASKETBALL";

    struct game match_basket1 = make_game(t3,t4);
    print_game(match_basket1);

    printf("\n");

    struct game tab_matchs_test1[2]; 
    tab_matchs_test1[0] = match_foot1;
    tab_matchs_test1[1] = match_basket1;

    print_games(tab_matchs_test1, 2);
    
    printf("\n");


    //// Test : Tournament Implementation //// 

    int players = 4; // players = nb_teams
    struct game tab_match2[players];
    char* teams[players];
    teams[0] = t1;
    teams[1] = t2;
    teams[2] = t3;
    teams[3] = t4;

    int nb_equipes = make_tournament(players, teams, tab_match2);
    printf("Le nombre de matchs crées : %d\n", nb_equipes);

    print_games(tab_match2, nb_equipes);
    printf("\n");

    //// Test : Make Pool //// 

    struct game matchs_pool[20]; 
    int nb_matchs_pools = make_pool(players, teams, matchs_pool);
    printf("Le nombre de maths de pool crées : %d\n", nb_matchs_pools);

    print_games(matchs_pool, nb_matchs_pools);
    printf("\n");


    return EXIT_SUCCESS;
}