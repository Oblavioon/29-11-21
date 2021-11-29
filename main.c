#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"




int main(){

    // Joueur
    Player *pj;
    pj = (Player *)malloc_protege(sizeof(Player));
    ListePlayer *pl;
    pl = (ListePlayer *)malloc_protege(sizeof(ListePlayer));

    // Ennemie
    Enemy *pe;
    pe = (Enemy *)malloc_protege(sizeof(Enemy));
    ListeEnemy *ple;
    ple = (ListeEnemy *)malloc_protege(sizeof(ListeEnemy));


    runGame(&pj, &pe, &pl, &ple, 0);

    /*
    while(1){

      pVerdoyante(&pj);
      interactionPerso(&pj, &pl);

      system("clear");
    }
  */


    free(pj);
    free(pl);
    free(pe);
    free(ple);

    return 0;
}



/*

gcc *.c -ojeu -lm -g -Wall
valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./jeu

gcc -c ennemis.c -o ennemis.o -g -Wall
gcc -c fight.c -o fight.o -g -Wall
gcc -c joueur.c -o joueur.o -g -Wall
gcc -c menu.c -o menu.o -g -Wall
gcc -c map.c -o map.o -g -Wall
gcc -c run.c -o run.o -g -Wall
gcc -c save.c -o save.o -g -Wall
gcc -c main.c -o main.o -g -Wall
gcc ennemis.o fight.o joueur.o menu.o map.o run.o save.o main.o -oprogram -lm -g -Wall

valgrind --leak-check=yes -s ./program
*/
