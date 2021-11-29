#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"

// On utilise cette fonction pour purge le STDIN(...)
void purgeSTDIN(){
  char ch;

  while((ch=getchar())!= '\n' && ch!=EOF);
}

void intro(unsigned int choix){
  system("clear");

  if(choix==0){
    printf(" ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄   ▄▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄\n");
    printf("█       █   █   █       █   ▄  █ █       █      █       █       █   ▄  █ \n");
    printf("█   ▄▄▄▄█   █   █    ▄▄▄█  █ █ █ █   ▄▄▄▄█  ▄   █▄     ▄█   ▄   █  █ █ █ \n");
    printf("█  █  ▄▄█   █   █   █▄▄▄█   █▄▄█▄█  █  ▄▄█ █▄█  █ █   █ █  █ █  █   █▄▄█▄ \n");
    printf("█  █ █  █   █▄▄▄█    ▄▄▄█    ▄▄  █  █ █  █      █ █   █ █  █▄█  █    ▄▄  █\n");
    printf("█  █▄▄█ █       █   █▄▄▄█   █  █ █  █▄▄█ █  ▄   █ █   █ █       █   █  █ █\n");
    printf("█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█  █▄█▄▄▄▄▄▄▄█▄█ █▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄▄▄█  █▄█\n");
  }

  if(choix==3){
    printf("      ▄▄█▀▀▀▄█          ▀██              ▀██   ██     \n");
    printf("     ▄█▀     ▀    ▄▄▄    ██ ▄▄▄    ▄▄▄▄   ██  ▄▄▄  ▄▄ ▄▄▄   \n");
    printf("     ██    ▄▄▄▄ ▄█  ▀█▄  ██▀  ██ ▄█▄▄▄██  ██   ██   ██  ██ \n");
    printf("     ▀█▄    ██  ██   ██  ██    █ ██       ██   ██   ██  ██  \n");
    printf("      ▀▀█▄▄▄▀█   ▀█▄▄█▀  ▀█▄▄▄▀   ▀█▄▄▄▀ ▄██▄ ▄██▄ ▄██▄ ██▄ \n");
  }

  if(choix==4){
    printf("\t\t   ▄▄█▀▀██                 \n");
    printf("\t\t ▄█▀      ██  ▄▄▄ ▄▄    ▄▄▄▄    \n");
    printf("\t\t ██        ██  ██▀ ▀▀ ▄█   ▀▀  \n");
    printf("\t\t ▀█▄      ██   ██     ██       \n");
    printf("\t\t   ▀▀█▄▄▄█▀   ▄██▄     ▀█▄▄▄▀ ");
  }

  if(choix==5){
    printf("    ▀██ ▀██▀  ▀█▀\n");
    printf("     ▀█▄ ▀█▄  ▄▀    ▄▄▄   ▄▄▄ ▄▄    ▄▄▄ ▄   ▄▄▄▄  ▄▄ ▄▄▄\n");
    printf("      ██  ██  █   ▄█  ▀█▄  ██▀ ▀▀  ██ ██  ▄█▄▄▄██  ██  ██\n");
    printf("       ███ ███    ██   ██  ██       █▀▀   ██       ██  ██\n");
    printf("        █   █      ▀█▄▄█▀ ▄██▄     ▀████▄  ▀█▄▄▄▀ ▄██▄ ██▄\n");
    printf("                                   ▄█▄▄▄▄▀");
  }

  if(choix==6){
    printf("▀██▀▀█▄                  ▀██                █         ▀██                              ▄                            \n");
    printf(" ██   ██   ▄▄▄▄    ▄▄▄▄   ██ ▄▄            ███      ▄▄ ██  ▄▄▄▄ ▄▄▄   ▄▄▄▄  ▄▄ ▄▄▄   ▄██▄  ▄▄▄ ▄▄▄  ▄▄▄ ▄▄    ▄▄▄▄  \n");
    printf(" ██▀▀▀█▄  ▀▀ ▄██  ██▄ ▀   ██▀ ██          █  ██   ▄▀  ▀██   ▀█▄  █  ▄█▄▄▄██  ██  ██   ██    ██  ██   ██▀ ▀▀ ▄█▄▄▄██ \n");
    printf(" ██    ██ ▄█▀ ██  ▄ ▀█▄▄  ██  ██   ████  ▄▀▀▀▀█▄  █▄   ██    ▀█▄█   ██       ██  ██   ██    ██  ██   ██     ██      \n");
    printf("▄██▄▄▄█▀  ▀█▄▄▀█▀ █▀▄▄█▀ ▄██▄ ██▄       ▄█▄  ▄██▄ ▀█▄▄▀██▄    ▀█     ▀█▄▄▄▀ ▄██▄ ██▄  ▀█▄▀  ▀█▄▄▀█▄ ▄██▄     ▀█▄▄▄▀ \n");
    printf(" \n");
    printf("\t\t\t  ▄▄█▀▀▀▄█       ▀██▀  ▀█▀  ██                          \n");
    printf("\t\t\t▄█▀     ▀         ▀█▄  ▄▀  ▄▄▄  ▄▄▄ ▄▄  ▄▄▄ ▄▄▄   ▄▄▄▄  \n");
    printf("\t\t\t██                 ██  █    ██   ██▀ ▀▀  ██  ██  ██▄ ▀  \n");
    printf("\t\t\t▀█▄      ▄  ████    ███     ██   ██      ██  ██  ▄ ▀█▄▄ \n");
    printf("\t\t\t ▀▀█▄▄▄▄▀            █     ▄██▄ ▄██▄     ▀█▄▄▀█▄ █▀▄▄█▀ \n");

    sleep(5);
  }

  if(choix==7){
    printf(" ▀██▀▀▀▀█                   ▄                   ▀██▀▀▀▀█               \n");
    printf("  ██  ▄     ▄▄▄▄    ▄▄▄▄  ▄██▄    ▄▄▄▄  ▄▄▄ ▄▄   ██  ▄      ▄▄▄ ▄   ▄▄▄ ▄  \n");
    printf("  ██▀▀█    ▀▀ ▄██  ██▄ ▀   ██   ▄█▄▄▄██  ██▀ ▀▀  ██▀▀█     ██ ██   ██ ██  \n");
    printf("  ██       ▄█▀ ██  ▄ ▀█▄▄  ██   ██       ██      ██         █▀▀     █▀▀   \n");
    printf(" ▄██▄▄▄▄▄█ ▀█▄▄▀█▀ █▀▄▄█▀  ▀█▄▀  ▀█▄▄▄▀ ▄██▄    ▄██▄▄▄▄▄█  ▀████▄  ▀████▄ \n");
    printf("                                                           ▄█▄▄▄▄▀ ▄█▄▄▄▄▀  \n");
  }
}

void confChoix(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
  int i;

  // Nous permet de valider réellement l'attaque du joueur
  // (évite certains bug)... et rajoute une sécurité
  // alternative au compteur....
  printf("\n\tValidez votre choix (1) sinon (0) : ");
  scanf("%d", &i);
  while(i!=1 /*|| i!=0*/){
    printf("\n\tValidez votre choix (1) : ");
    scanf("%d", &i);
  }

  //if(i==0){
  //  menuCombat(ppj, ppe, ppl, pple);
  //}
}



// Fonction pour le menu Démarrage
void menuDemarrage(Player **ppj, ListePlayer **ppl){

  int choix;
  // system("clear");
  //do{
  //le tableau affiché dans le terminal
  intro(0);
  printf("\n  \t\t*************************************************");
  printf("\n  \t\t|\t\tMenu de démarrage :\t\t|");
  printf("\n  \t\t*************************************************");
  printf("\n  \t\t|\t\t\t\t\t\t|" );
  printf("\n  \t\t|\t1.Nouvelle partie \t\t\t|");
  printf("\n  \t\t|\t\t\t\t\t\t|" );
  printf("\n  \t\t|\t2.Charger partie enregistrée  \t\t|");
  printf("\n  \t\t|\t\t\t\t\t\t|" );
  printf("\n  \t\t|\t3.Supprimer une partie enregistrée  \t|");
  printf("\n  \t\t|\t\t\t\t\t\t|" );
  printf("\n  \t\t|\t4.Quitter \t\t\t\t|");
  printf("\n  \t\t|\t\t\t\t\t\t|" );
  printf("\n  \t\t|\t\t\t\t\t\t|" );
  printf("\n  \t\t*************************************************" );
  printf("\n  \t\tEntrez votre choix : ");
  scanf("%d", &choix);
    switch (choix) // appel des différentes fonctions/procédures
    {              // en fonction du choix fait par l'utilisateur
      case 1:
        purgeSTDIN();
        initPlayer(ppj, ppl);
        initCaste(ppj);

        break;

      case 2:
        //chargerSauvegarde()
        //printf("Reprendre partie");
        break;
      case 3:
        printf("Reprendre supp");
        break;
      case 4:
        printf(" \n");
        exit(0); // Sortie du programme choisie par l'utilisateur
        break;
      default:
        printf("Entrée incorrecte.\n");
        printf("S'il vous plait entrez une valeur correcte.\n");
    //}
  }
  system("clear");
}




// Fonction concernant le menu du jeu
// lorsqu'en pleine partie l'on appuie sur "m"
// l'on déclenche ce menu...
void menu_jeu(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
  // ListePlayer *pl = NULL;
  //pl = pl->prem_el;
  int choix;
  system("clear");
  do{
    //le tableau affiché dans le terminal
    printf("\n\t*************************************************\n");
    printf("\t|\t\tMenu du jeu :\t\t\t|\n");
    printf("\t*************************************************\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t1.Sauvegarder la partie \t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t2.Reprendre partie \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t3.Quitter le jeu  \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t*************************************************\n" );
    printf("\tEntrez votre choix : ");
    scanf("%d", &choix);
    switch (choix) // appel des différentes fonctions/procédures
    {              // en fonction du choix fait par l'utilisateur
      case 1:
        ecrireSauvegarde(ppl);

        break;

      case 2:
        runGame(ppj, ppe, ppl, pple, 1);
        break;
      case 3:
        exit(0);
        break;
      case 4:
        printf(" \n");
        exit(0); // Sortie du programme choisie par l'utilisateur
        break;
      default:
        printf("Entrée incorrecte.\n");
        printf("S'il vous plait entrez une valeur correcte.\n");
    }
    system("clear");
  }
  while(1);
}



// Le menu des attaques du personnage ce déclenche
// automatiquement lorsque le joueur intéragit avec 1 ennemi.
void menuAttack(Player **ppj, Enemy **ppe){

  int choix; // On utilise choix pour définir les attaques qui vont suivre.

  printf("\t1. Guillotine Slash,\n\t 2. Brise mur,\n\t 3. Demembrement,\n");
  printf("Choisissez votre option : ");
  scanf("%d", &choix);

  while(choix<1 || choix>3){
    printf("Choisissez votre option : ");
    scanf("%d", &choix);
    printf("\n");
  }
  switch(choix){
    // Partie pour le joueur
    case 1 :
      headShot(ppj, ppe, choix);
      break;

    case 2 :
      chestShot(ppj, ppe, choix);
      break;

    case 3 :
      limbShot(ppj, ppe, choix);
      break;

    // Partie pour les mobs
      // On utilisera certianement un srand
      // avec son rand que l'on importera via une commande certainement
      // par adresse en utilisant un pointeur.. Faut voir :)
    case 4 :
      headShot(ppj, ppe, choix);
      break;

    case 5 :
      chestShot(ppj, ppe, choix);
      break;

    case 6 :
      limbShot(ppj, ppe, choix);
      break;
  }
}
void menuCombat(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
    int choix, i;
    system("clear");
    do{
    //le tableau affiché dans le terminal

      if((*ppe)->id==1){
        intro(3); // Pour les gobelins.
      }else if((*ppe)->id==2){ 
        intro(4); // Pour les orcs.
      }else if((*ppe)->id==3){
        intro(5); // Pour les worgens.
      }

      printf("\n\t*************************************************\n");
      printf("\t|\t\tMenu de combat  :\t\t|\n");
      printf("\t*************************************************\n\t|");
      printf("\t\t\t\t\t\t" );
      printf("|\n\t|\t\tQue faire ? \t\t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t1.Guillotine Slash \t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t2.Brise mur  \t\t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t3.Demembrement \t\t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t4.Fuir lamentablement ...\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t*************************************************\n" );
      affStatsComb(ppj, ppe);

      printf("\tEntrez votre choix : ");
      scanf("%d", &choix);
      switch (choix) // appel des différentes fonctions/procédures
      {              // en fonction du choix fait par l'utilisateur
        case 1:
          headShot(ppj, ppe, 3);
          
          confChoix(ppj, ppe, ppl, pple);

          deroulementCombat(ppj, ppe, ppl, pple);
          break;

        case 2:
          chestShot(ppj, ppe, 2);

          confChoix(ppj, ppe, ppl, pple);

          deroulementCombat(ppj, ppe, ppl, pple);
          break;

        case 3:
          limbShot(ppj, ppe, 1);

          confChoix(ppj, ppe, ppl, pple);

          deroulementCombat(ppj, ppe, ppl, pple);
          break;
          
        case 4:
          ((*ppj)->x += 1);
          ((*ppj)->y +=1);
          runGame(ppj, ppe, ppl, pple, 1);

          break;

        default:
          printf("\tEntrée incorrecte.\n");
          printf("\tS'il vous plait entrez une valeur correcte.\n");
          menuCombat(ppj, ppe, ppl, pple);

        system("clear");
      }
    }while(1);
}

void deroulementCombat(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
  if((*ppe)->hp<=0){
    // Si le joueur tue la monstre il recup ces ressources
    (*ppj)->po+=(*ppe)->po;
    (*ppj)->xp+=(*ppe)->xp;
    (*ppj)->zebapik+=(*ppe)->zebapik;

    // On déplace la joueur à +1 de ces coordonnées initiale
    (*ppj)->y+=1;
    (*ppj)->x+=1;

    // On initialise à nouveau le monstre
    initEnemy(ppe, pple);
    randEnemy(ppe);

    // On relance la partie
    runGame(ppj, ppe, ppl, pple, 1);
  }

  if((*ppj)->hp<=0){
    // Si le joueur tue la monstre il recup ces ressources
    (*ppj)->y=15;
    (*ppj)->x=23;

    // On relance la partie
    runGame(ppj, ppe, ppl, pple, 1);
  }

}


void easterEgg(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
    int choix;
    system("clear");

    intro(7);

    do{
    //le tableau affiché dans le terminal
    printf("\t*************************************************\n");
    printf("\t|Pour préparer la potion anti C-virus ,\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|l’alchimiste du royaume utilise exclusivement  |\n\t|");
    printf("des produits disponibles dans\t\t\t|\n" );
    printf("\t|les contrées alentours.\t\t\t" );
    printf("|\n\t|Notamment de l’huile de roche des falaises,\t|\n");
    printf("\t|de l’extrait de trèfle, de la betterave rouge  |\n" );
    printf("\t|ainsi qu’un bouillon marin à base\t\t|\n" );
    printf("\t|de crustacés et de crevettes grises.\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|Pour parfumer le tout,\t\t\t\t|\n");
    printf("\t|il précise qu’il ajoute un léger spray \t|\n" );
    printf("\t|de parfum de la forêt, \t\t\t|\n" );
    printf("\t|sans oublier l’ingrédient principal,\t\t|\n");
    printf("\t|de la zebapik en grande quantité.\t\t|\n");
    printf("\t|Côté préparation, comptez 5 à 6 heures\t\t|\n" );
    printf("\t|de cuisson pour cette précieuse potion.\t|\n");
    printf("\t|\t\t1 pour quitter\t\t\t|\n" );
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t*************************************************\n" );
    printf("\t");
    scanf("%d", &choix);
      switch (choix) // appel des différentes fonctions/procédures
      {              // en fonction du choix fait par l'utilisateur
        case 1:
          runGame(ppj, ppe, ppl, pple, 1);
          break;
        default:
          printf("Entrée incorrecte.\n");
          printf("S'il vous plait entrez une valeur correcte.\n");
      }
      system("clear");
    }
    while(1);
}




/*

J'ai mis en commentaire étant donné que finalement ça ne nous fait que des lignes en plus...
on a pu utiliser correctement les "id" xD

void menuCombatGobelin(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){

      int choix, i;
      system("clear");
      do{
      //le tableau affiché dans le terminal
      printf("      ▄▄█▀▀▀▄█          ▀██              ▀██   ██     \n");
      printf("     ▄█▀     ▀    ▄▄▄    ██ ▄▄▄    ▄▄▄▄   ██  ▄▄▄  ▄▄ ▄▄▄   \n");
      printf("     ██    ▄▄▄▄ ▄█  ▀█▄  ██▀  ██ ▄█▄▄▄██  ██   ██   ██  ██ \n");
      printf("     ▀█▄    ██  ██   ██  ██    █ ██       ██   ██   ██  ██  \n");
      printf("      ▀▀█▄▄▄▀█   ▀█▄▄█▀  ▀█▄▄▄▀   ▀█▄▄▄▀ ▄██▄ ▄██▄ ▄██▄ ██▄ \n");
      printf("\n\t*************************************************\n");
      printf("\t|\t\tMenu de combat  :\t\t|\n");
      printf("\t*************************************************\n\t|");
      printf("\t\t\t\t\t\t" );
      printf("|\n\t|\t\tQue faire ? \t\t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t1.HeadShot  \t\t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t2.ChestShot  \t\t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t3.LimbShot \t\t\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t4.Fuir lamentablement ...\t|\n");
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t|\t\t\t\t\t\t|\n" );
      printf("\t*************************************************\n" );
      printf("\tEntrez votre choix : ");
      scanf("%d", &choix);
        switch (choix) // appel des différentes fonctions/procédures
        {              // en fonction du choix fait par l'utilisateur
          case 1:
            headShot(ppj, ppe, 3);
          
            for(i=0; i<40; i++);

            if((*ppe)->hp<=0){
              runGame(ppj, ppe, ppl, pple, 1);
            }
            break;
          case 2:
            chestShot(&ppj, &ppe, 2);

            for(i=0; i<40; i++);

            if((*ppe)->hp<=0){
              runGame(ppj, ppe, ppl, pple, 1);
            }

            break;
          case 3:
            limbShot(&ppj, &ppe, 1);

            for(i=0; i<40; i++);

            if((*ppe)->hp<=0){
              runGame(ppj, ppe, ppl, pple, 1);
            }

            break;
          case 4:
            (*ppj->x += 1)
            (*ppj->y +=1)
            runGame(ppj, ppe, ppl, pple, 1);
            break;
          default:
            printf("Entrée incorrecte.\n");
            printf("S'il vous plait entrez une valeur correcte.\n");
            menuCombatGobelin()
        }
        system("clear");
      }
      while(1);
}

void menuCombatWorgen(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){

    int choix;
    system("clear");
    do{
    //le tableau affiché dans le terminal
    printf("    ▀██ ▀██▀  ▀█▀\n");
    printf("     ▀█▄ ▀█▄  ▄▀    ▄▄▄   ▄▄▄ ▄▄    ▄▄▄ ▄   ▄▄▄▄  ▄▄ ▄▄▄\n");
    printf("      ██  ██  █   ▄█  ▀█▄  ██▀ ▀▀  ██ ██  ▄█▄▄▄██  ██  ██\n");
    printf("       ███ ███    ██   ██  ██       █▀▀   ██       ██  ██\n");
    printf("        █   █      ▀█▄▄█▀ ▄██▄     ▀████▄  ▀█▄▄▄▀ ▄██▄ ██▄\n");
    printf("                                   ▄█▄▄▄▄▀");
    printf("\n\t*************************************************\n");
    printf("\t|\t\tMenu de combat  :\t\t|\n");
    printf("\t*************************************************\n\t|");
    printf("\t\t\t\t\t\t" );
    printf("|\n\t|\t\tQue faire ? \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t1.HeadShot  \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t2.ChestShot  \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t3.LimbShot \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t4.Fuir lamentablement ...\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t*************************************************\n" );
     printf("\tEntrez votre choix : ");
    scanf("%d", &choix);
      switch (choix) // appel des différentes fonctions/procédures
      {              // en fonction du choix fait par l'utilisateur
        case 1:
          //headShot(&ppj, &ppe, 3);
          break;
        case 2:
          //chestShot(&ppj, &ppe, 2);
          break;
        case 3:
          //limbShot(&ppj, &ppe, 1);
          break;
        case 4:
          //(*ppj->x += 1)
          //(*ppj->y +=1)
          //runGame(ppj, ppe, ppl, pple, 1);
          break;
        default:
          printf("Entrée incorrecte.\n");
          printf("S'il vous plait entrez une valeur correcte.\n");
      }
      system("clear");
    }

    while(1);


}
*/