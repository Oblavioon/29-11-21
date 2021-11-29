#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "save.h"
#include "run.h"


void chargerSauvegarde(ListePlayer *pl,FILE *sauvegarde){
  char buffer[256];
  char *s;

  while(fgets(buffer,256,sauvegarde)){
    if(buffer[strlen(buffer)-1]== '\n') buffer[strlen(buffer)-1] = '\0';

    s = buffer;
    while(*s!=';') s++;
    *s = '\0';
    s++;
  }
  //morceau d'un cours de M2
  /*
  t_elem* load_liste()
  {
  FILE*f;
  t_elem*prem=NULL,*p,e;
    //Tout d'abord, ouvrir le fichier dans lequel il y a la liste sauvegardée,
    if((f=fopen("save liste.bin","rb"))!=NULL){
      //allouer la mémoire pour le premier maillon prem.
      prem=malloc(sizeof(t_elem));
      //copier le premier maillon sauvé dans le fichier dans le premier maillon recréé
      //prem avec la fonction fread()
      fread(prem,sizeof(t_elem),1,f);

      p=prem;
      while(fread(&e,sizeof(t_elem),1,f)){ //oui oui fread contenue dans stdio.h
        p->suiv=malloc(sizeof(t_elem));
        p=p->suiv;
        *p=e;
        p->suiv=NULL;
      }
      fclose(f);
  }
  else
    printf("erreur ou fichier inexistant");
  return prem;
*/
}

/*

pl->tete = pj; 

*/


void ecrireSauvegarde(ListePlayer **ppl){
  Player *courant;

  FILE* fichier = NULL;
  fichier = fopen("sauvegarde.txt", "r+");

  if (fichier != NULL)
  {
      printf("\nOn peut lire et écrire dans la sauvegarde\n\n");
  }
  else
  {
      // On affiche un message d'erreur si on veut
      printf("Impossible d'ouvrir le fichier repertoire.txt\n");
      exit(1);
  }
  courant = (*ppl)->tete ;
  while(courant != NULL)
  {
    fprintf(fichier, "%s;%d;%s;%d;%d;%d;%d;%d;%d;%d;%d;%d;\n", courant->nom, courant->sexe, courant->n_caste, courant->hp, courant->dp, courant->xp, courant->lvl, courant->po, courant->zebapik, courant->nitrile, courant->x, courant->y);
    courant = courant->psuivant;
  }
  fclose(fichier);
}

/*
gcc -c ennemis.c -o ennemis.o -g -Wall
gcc -c fight.c -o fight.o -g -Wall
gcc -c joueur.c -o joueur.o -g -Wall
gcc -c menu.c -o menu.o -g -Wall
gcc -c map.c -o map.o -g -Wall
gcc -c run.c -o run.o -g -Wall
gcc -c save.c -o save.o -g -Wall
gcc -c main.c -o main.o -g -Wall
gcc ennemis.o fight.o joueur.o menu.o map.o main.o -oprogram -lm -g -Wall
valgrind --leak-check=yes -s ./program
*/


/*
  Liste *pliste,*pl2;
  FILE * f1,*f2;

  f1 = fopen("rep.txt","w");
  f2 = fopen("rep.txt","r");
*/
