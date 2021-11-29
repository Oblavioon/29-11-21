#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"

void runGame(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple, int firstparty){
	int indice=0, i;
	// On déclare le tableau de fonction
	void (*plateau[3])(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple) = {pVerdoyante, salleBoss, estaminet};

	intro(6);

	if(firstparty==0){
		menuDemarrage(ppj, ppl);

		initEnemy(ppe, pple);

		if((*ppj)->nom[strlen((*ppj)->nom)-1]== '\n') (*ppj)->nom[strlen((*ppj)->nom)-1] = '\0';
		printf("Vous vous appelez %s, %s de Clergue.\n", (*ppj)->nom, (*ppj)->n_caste);

		firstparty++;
	}

	// Initialisation des coordonées de/des ennemis
  	depEnemy(ppe, 0);

	while(1){

		// Regarde la fonction en faisant ctrl + clic droit
		// j'espère que vous allez comprendre facilement je viens de finir
		// On a pas mal de warning avec le pointeur de tableau de fonction...
		interPO(ppj, 10, 10, &indice);
		plateau[indice]( ppj,  ppe,  ppl,  pple);

		// if((*ppj)->y!=10 && (*ppj)->x!=10){
			// pVerdoyante(ppj, ppe);
		// }else if((*ppj)->y==10 && (*ppj)->x==10){
        	// salleBoss(ppj, ppe);
        // }

      	interPE(ppj, ppe, ppl, pple);
      	depPerso(ppj, ppe, ppl, pple);


      	system("clear");
    }

}



void temps(){

}
