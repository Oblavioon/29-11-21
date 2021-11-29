#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"

int foncSemiAl(unsigned int aleatoire){

    srand((unsigned) time(NULL));

    aleatoire = rand()%aleatoire;

    return aleatoire;
}



// Initialisation de la liste
void initListeEnemy(ListeEnemy *ple){
    // On appelle malloc protégée
    ple = (ListeEnemy *)malloc_protege(sizeof(ListeEnemy));

    ple->etete = NULL;
}

void initEnemy(Enemy **ppe, ListeEnemy **pple){
    int caste;

    // Initialisation des stats basique
    (*ppe)->hp = 0;
    (*ppe)->dp = 0;
    (*ppe)->xp = 0;
    (*ppe)->lvl = 0;
    (*ppe)->po = 0;
        // Stats
    (*ppe)->x = 1;
    (*ppe)->y = 1;

    // Initialisation pointeurs
        // pointeur Esuivant
    (*ppe)->esuivant=NULL;
        // pointeur de liste
    (*pple)->etete=*ppe;
}


void randEnemy(Enemy **ppe){
    int choix=0;

    choix = foncSemiAl(3+1);
    while(choix<=0 || choix>3){
        choix = foncSemiAl(3+1);
    }

    // Choix des castes de chacun des monstres
    // De façon semi-aléatoire (srand - rand)...
    if(choix==1){
        casteGobelin(ppe);
    }else if(choix==2){
        casteOrc(ppe);
    }else if(choix==3){
        casteWorgen(ppe);
    }
}


// À savoir que les Gobelins seront la caste la plus lvl chez les ennemis, représentés par un - ou + ou ♠︎
void casteGobelin(Enemy **ppe){

    // Nom de la classe/du mob/ID
    strcpy((*ppe)->n_caste, "Gobelin");
    (*ppe)->id=1;

    // Rajout de données pour les statistiques
    (*ppe)->hp += 2;
    (*ppe)->dp += 1;
    (*ppe)->xp += 5;
    (*ppe)->po += 2;
    //position
    (*ppe)->x = 1;
    (*ppe)->y = 1;
        // Fixe le niveau du mob
    (*ppe)->lvl = 1;

    // Rajout du valeur Zebapik (pt bonus)
    (*ppe)->zebapik = 1;
}
//  À savoir que les Orcs sont la middle class des mob jute avant les Orgen et juste après les Gobelins, représentés par un + ou * ou ♣︎
void casteOrc(Enemy **ppe){

    // Nom de la  classe/du mob/ID
    strcpy((*ppe)->n_caste, "Orc");
    (*ppe)->id=2;

    // Rajout de données pour les stats
    (*ppe)->hp += 4;
    (*ppe)->dp += 3;
    (*ppe)->xp += 10;
    (*ppe)->po += 4;
    //position
    (*ppe)->x = 1;
    (*ppe)->y = 1;
        // Fixe le niveau du mob
    (*ppe)->lvl = 1;

    // Rajout du valeur Zebapik (pt bonus)
    (*ppe)->zebapik = 1;
}
// À savoir que les Orgens sont la caste la plus haute parmis les mob "normaux"... représentés par un ^ ou $ ou ♥
void casteWorgen(Enemy **ppe){

    // Nom de la classe/du mob/ID
    strcpy((*ppe)->n_caste, "Worgen");
    (*ppe)->id=3;

    // Rajout de données pour les stats
    (*ppe)->hp += 9;
    (*ppe)->dp += 6;
    (*ppe)->xp += 10;
    (*ppe)->po += 6;
    //position
    (*ppe)->x = 1;
    (*ppe)->y = 1;
        // Fixe le niveau du mob
    (*ppe)->lvl = 1;

    // Rajout du valeur Zebapik (pt bonus)
    (*ppe)->zebapik = 2;
}


// Déplacement des personnages...
void depEnemy(Enemy **ppe, int rpt){
    if(rpt==0){
        (*ppe)->x = foncSemiAl(16+1);
        while((*ppe)->x==0 || (*ppe)->x>=16){
            (*ppe)->x = foncSemiAl(16+1);
        }
        (*ppe)->y = foncSemiAl(23+1);
        while((*ppe)->y==0 || (*ppe)->y>=24){
            (*ppe)->y = foncSemiAl(23+1);
        }
    }
    // Si l'on veut que les ennemis se déplace aussi -automatiquement-
    // if(rpt!=0){
        // (*ppe)->x++;
        // (*ppe)->y+=foncSemiAl(1+1);
    // }
}
