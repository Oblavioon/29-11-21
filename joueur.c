#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"

// Fonction pour malloc protégée
void* malloc_protege(size_t s){
    void * p;
    p=malloc(s);

    if(p) return p;
    else {perror("\nAllocation Impossible!\n");exit(EXIT_FAILURE);}
}


// Initialisation de la liste
void initListe(ListePlayer *pl){
    // On appelle malloc protégée
    pl = (ListePlayer *)malloc_protege(sizeof(ListePlayer));

    pl->tete = NULL;
}
// Initialisation du personnage
// Pointeur Joueur
void initPlayer(Player **ppj, ListePlayer **ppl){
    int temp;

    // pj->nom = nom
    printf("  \t\t*\n");
    printf("  \t\tEntrez le nom de votre personnage: ");
    fgets((*ppj)->nom, 20, stdin);

    // pj->sexe = sexe
    printf("  \t\t*-*\n");
    printf("  \t\tChoisissez votre sexe.\n");
    printf("  \t\t1:Homme | 2:Femme\n");
    printf("  \t\tChoisir : ");
    scanf("%d", &temp);
    (*ppj)->sexe = temp;

        // stats basiques
    (*ppj)->hp = 5;
    (*ppj)->dp = 2;
    (*ppj)->xp = 0;
    (*ppj)->lvl = 0;
    (*ppj)->po = 0;

        // stats avancées
    (*ppj)->zebapik = 0;
    (*ppj)->nitrile = 0;


    // Initialisation des positions
    (*ppj)->x=1;
    (*ppj)->y=1;

    // Init pointeur
        // Pointeur suivant
    (*ppj)->psuivant=NULL;
        // Pointeur liste
    (*ppl)->tete=*ppj;
}



// Initialisation de la caste que choisira le joueur
// Pointeur Joueur...
void initCaste(Player **ppj){
    int choix;

    printf("  \t\t*-*-*\n");
    printf("  \t\tQuelle caste/classe souhaitez avoir ?\n");
    printf("  \t\t1:Guerrier/Guerriere. | 2:Voleur/Voleuse.\n");
    printf("  \t\tChoisir :");
    scanf("%d", &choix);


    switch(choix){
        // Choix de la classe Guerrier/Guerrière
        case 1 :
            casteG(ppj);
            break;

        // Choix de la classe Voleur/Voleuse
        case 2 :
            casteV(ppj);
            break;
    }


}
// Classe Guerrier
void casteG(Player **ppj){

    // Ici on modifie le nom de la caste en fonctin du sexe..
    if((*ppj)->sexe == 1){
        strcpy((*ppj)->n_caste, "Guerrier");
    }else{
        strcpy((*ppj)->n_caste, "Guerriere");
    }

    // Init des stats de initiale du Guerrier
    // Parce que l'on pourra ajouter différente stats avec
    // des items etc...
    (*ppj)->hp += 10;
    (*ppj)->dp += 1;
    (*ppj)->xp += 2;
    (*ppj)->lvl += 0;
    (*ppj)->po += 0;

    // Initialisation des coordonnées
    (*ppj)->x=24;
    (*ppj)->y=17;

    // Initialisation du logo du joueur
    strcpy((*ppj)->logo_caste, "G");
}
// Classe Voleur
void casteV(Player **ppj){

    // Ici on modifie le nom de la caste en fonctin du sexe..
    if((*ppj)->sexe == 1){
        strcpy((*ppj)->n_caste, "Voleur");
    }else{
        strcpy((*ppj)->n_caste, "Voleuse");
    }

    // Init des stats de initiale du Voleur
    // Parce que l'on pourra ajouter différente stats avec
    // des items etc...
    (*ppj)->hp += 7;
    (*ppj)->dp += 3;
    (*ppj)->xp += 1;
    (*ppj)->lvl += 0;
    (*ppj)->po += 1;

    // Initialisation des coordonnées
    (*ppj)->x=23;
    (*ppj)->y=4;

    // Initialisation du logo du joueur
    strcpy((*ppj)->logo_caste, "V");
}

void depPerso(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
  char dep;
  printf("Deplacement : ");
  scanf("%c", &dep);

    if(dep!='z' || dep!='q' || dep!='s' || dep!='d' || dep!='Z' || dep!='Q' || dep!='S' || dep!='D'){

      // Ici on s'occupe de l'ordonnée
      if( dep == 'q' || dep == 'Q'){
        (*ppj)->x-=1;
      }
      if( dep == 'd' || dep == 'D' ){
        (*ppj)->x+=1;
      }
      //map[y][x]='H';
      // Ici on s'occupe de l'abscisse
      if( dep == 'z' || dep == 'Z' ){
        (*ppj)->y-=1;
      }
      if( dep == 's' || dep == 'S'){
        (*ppj)->y+=1;
      }
    }

    // menu pause
    if( dep == 'm' || dep == 'M'){
      menu_jeu(ppj, ppe, ppl, pple);
    }

    // Limite pour le plateau de jeu    
        // Pour x
    if((*ppj)->x==0) (*ppj)->x++;
    else if((*ppj)->x==29) (*ppj)->x--;
        // Pour y
    if((*ppj)->y==0) (*ppj)->y++;
    else if((*ppj)->y==24) (*ppj)->y--; 


    // EasterEgg
    if(dep == '~') easterEgg(ppj, ppe, ppl, pple);

}
