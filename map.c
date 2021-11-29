#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"


#define BLACK    "\033[1;30m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define PURPLE   "\033[1;35m"
#define CYAN     "\033[1;36m"
#define GREY     "\033[1;37m"

#define DEFAULT_COLOR "\033[0;m"


void pVerdoyante(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
//char map[y] [x];
  char map[25][50]; //, c[10]
  int  k=0;
  int i, j, x=(*ppj)->x, y=(*ppj)->y;


  system("clear");
  printf("\n");
  // (*ppj)->n_map[50]="Prairie Verdoyante";
  strcpy((*ppj)->n_map, "Prairie Verdoyante");
  printf("\033[1;35m%s\n", (*ppj)->n_map);

  // initialisation du tableau
  for(i=0; i<25; i++){
    for(j=0; j<30; j++){

      if( i == 0 || i == 24 ){
        map[i][j]='=';
      }
      else if( j == 0 || j == 29 ){
        map[i][j]='|';
      }
      else{
        map[i][j]=' ';
      }



        //Joeur
        //map[(*ppj)->y][(*ppj)->x]='H';
        //Héro
        // map[5][9]='H';
        //Herbes
        map[1][1]='*';
        map[1][2]='*';
        map[1][3]='*';
        map[2][1]='*';
        map[3][1]='*';
        map[2][2]='*';
        //Champs
        map[1][28]='*';
        map[1][27]='*';
        map[1][26]='*';
        map[1][25]='*';
        map[1][24]='*';
        map[1][23]='*';
        map[1][22]='*';
        map[1][21]='*';
        map[1][20]='*';
        map[1][19]='*';
        map[1][18]='*';
        map[1][17]='*';

        map[3][28]='*';
        map[3][27]='*';
        map[3][26]='*';
        map[3][25]='*';
        map[3][24]='*';
        map[3][23]='*';
        map[3][22]='*';
        map[3][21]='*';
        map[3][20]='*';
        map[3][19]='*';
        map[3][18]='*';
        map[3][17]='*';

        map[5][28]='*';
        map[5][27]='*';
        map[5][26]='*';
        map[5][25]='*';
        map[5][24]='*';
        map[5][23]='*';
        map[5][22]='*';
        map[5][21]='*';
        map[5][20]='*';
        map[5][19]='*';
        map[5][18]='*';
        map[5][17]='*';

        map[7][28]='*';
        map[7][27]='*';
        map[7][26]='*';
        map[7][25]='*';
        map[7][24]='*';
        map[7][23]='*';
        map[7][22]='*';
        map[7][21]='*';
        map[7][20]='*';
        map[7][19]='*';
        map[7][18]='*';
        map[7][17]='*';

        //Minerais
        map[23][1]='#';
        map[22][1]='#';
        map[21][1]='#';
        map[23][2]='#';
        map[22][2]='#';
        map[23][3]='#';

        //un truc qu'on sait pas trop mais bleu(certainement de l'eau)
        map[13][12]='~';
        map[12][12]='~';
        map[11][12]='~';
        map[10][12]='~';
        map[9][12]='~';
        map[12][11]='~';
        map[11][11]='~';
        map[10][11]='~';
        map[12][13]='~';
        map[11][13]='~';
        map[10][13]='~';
        map[11][14]='~';
        map[11][10]='~';
        map[12][10]='~';
        map[13][10]='~';
        map[13][11]='~';

        map[23][18]='~';
        map[22][18]='~';
        map[21][18]='~';
        map[20][18]='~';
        map[19][18]='~';
        map[18][18]='~';
        map[18][18]='~';
        map[17][18]='~';
        map[16][18]='~';
        map[15][18]='~';
        map[15][19]='~';
        map[15][20]='~';
        map[15][21]='~';
        map[15][22]='~';

        //map[15][25]='~';
        map[15][26]='~';
        map[15][27]='~';
        map[15][28]='~';

        //Péon
        map[2][26]='P';
        map[4][19]='P';
        map[6][24]='P';

        //Villageois
        map[23][25]='V';
        map[21][28]='V';
        map[21][23]='V';

        //Méchant niveau max
        map[20][3]='M';

        //méchant niveau min
        //(*ppe)->x = 22;
        //(*ppe)->y = 10;
        //map[(*ppe)->y][(*ppe)->x]='m';
        //(*ppe)->x = 13;
        //(*ppe)->y = 9;
        //map[(*ppe)->y][(*ppe)->x]='m';
        // (*ppe)->x = 3;
        // (*ppe)->y = 15;
        (*ppe) = (Enemy *)malloc_protege(sizeof(Enemy));
        map[(*ppe)->y][(*ppe)->x]='m';

        //Mur d'enceinte
        map[23][19]='O';
        map[22][19]='O';
        map[21][19]='O';
        map[20][19]='O';
        map[19][19]='O';
        map[18][19]='O';
        map[17][19]='O';
        map[16][19]='O';
        map[16][20]='O';
        map[16][21]='O';
        map[16][22]='O';

        //map[16][25]='O';
        map[16][26]='O';
        map[16][27]='O';
        map[16][28]='O';

        //pont Lewis
        map[15][23]=']';
        map[15][25]='[';
        map[16][23]=']';
        map[16][25]='[';

        //cimetière
        map[23][16]='+';
        map[22][16]='+';
        map[21][16]='+';
        map[20][16]='+';
        //map[19][16]='+';
        map[23][14]='+';
        map[22][14]='+';
        map[21][14]='+';
        map[20][14]='+';
        //map[19][14]='+';
        map[23][12]='+';
        map[22][12]='+';
        map[21][12]='+';
        map[20][12]='+';

        // Téléporteur
        map[10][10] = '@';


      }
    }

    // Affichage du tableau
    for(i=0; i<25; i++){
      for(j=0; j<30; j++){
        //Affichage Bords droite/gauche
        if(map[i][j]=='|'){
          printf("\033[1;35m%2c",map[i][j]);
        }
        //Affichage Bords haut/bas
        if(map[i][j]=='='){
          printf("\033[1;35m%2c",map[i][j]);
        }

        //Affichage Herbes
        if(map[i][j]=='*'){
          printf("\033[1;32m%2c",map[i][j]);
        }
        //Affichage Minerais
        if(map[i][j]=='#'){
          printf("\033[1;37m%2c",map[i][j]);
        }
        //Affichage Héro
        map[y][x]='H';
        if(map[i][j]=='H'){
          printf("\033[1;36m%2c",map[i][j]);
        }
        //Péon
        if(map[i][j]=='P'){
          printf("\033[0;m%2c",map[i][j]);
        }
        //Villageois
        if(map[i][j]=='V'){
          printf("\033[0;m%2c",map[i][j]);
        }


        //Affichage Méchant niveau max
        if(map[i][j]=='M'){
          printf("\033[1;31m%2c",map[i][j]);
        }
        //Affichage méchant niveau min
        if(map[i][j]=='m'){
          printf("\033[1;33m%2c",map[i][j]);
        }
        //Affichage d'un truc qu'on sait pas mais bleu
        if(map[i][j]=='~'){
          printf("\033[1;34m%2c",map[i][j]);
        }
        //Affichage d'espace
        if(map[i][j]==' '){
          printf("\033[1;33m%2c",map[i][j]);
        }
        //Affichage mur d'enceinte
        if(map[i][j]=='O'){
          printf("\033[1;37m%2c",map[i][j]);
        }
        //Affichage pont Lewis
        if(map[i][j]=='[' || map[i][j]==']'){
          printf("\033[1;37m%2c",map[i][j]);
        }
        //cimetière
        if(map[i][j]=='+'){
          printf("\033[1;37m%2c",map[i][j]);
        }
        // Téléporteur
        if(map[i][j]=='@'){
          printf("\033[1;37m%2c",map[i][j]);
        }


        k++;
      if(k%30 == 0){
        printf("\n");
      }
    }
  }

  affStats(ppj);

  //deplacement(ppj);

  printf("\n");
}


void salleBoss(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){

  char map[25][40];
  int r = 12;
  int i, j, k = 0, x = 20, y = 12;

  for(i=0;i<25;i++){
    for(j=0;j<40;j++){

      if(sqrt((y-i)*(y-i) + (x-j)*(x-j)) <= r-1){
        map[i][j] = ' ';
      }
      else if(sqrt((y-i)*(y-i) + (x-j)*(x-j)) <= r+1){
        map[i][j] = '#';
      }
      else{
        map[i][j] = ' ';
      }
      //Boss
      map[12][20] = 'B';
      //Méchant
      map[10][18] = 'M';
      map[14][18] = 'M';
      map[10][22] = 'M';
      map[14][22] = 'M';

      //Téléporteur
      map[23][20] = '@';
    }
  }
  for(i=0;i<25;i++){
    for(j=0;j<40;j++){

      //if(map[i][j]=='#'){
      printf("\033[1;31m%2c", map[i][j] );
      //}
      k++;

      if(k%40 == 0){
      printf("\n\033[0;m");
      }
    }
  }
}


void estaminet(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){

char map[25][64];
int  k;
int i, j;
k=0;


printf("\033[1;34m▀██▀▀▀▀█           ▄                       ██                     ▄\n");
printf(" ██  ▄     ▄▄▄▄  ▄██▄   ▄▄▄▄   ▄▄ ▄▄ ▄▄   ▄▄▄  ▄▄ ▄▄▄     ▄▄▄▄  ▄██▄\n");
printf(" ██▀▀█    ██▄ ▀   ██   ▀▀ ▄██   ██ ██ ██   ██   ██  ██  ▄█▄▄▄██  ██\n");
printf(" ██       ▄ ▀█▄▄  ██   ▄█▀ ██   ██ ██ ██   ██   ██  ██  ██       ██\n");
printf("▄██▄▄▄▄▄█ █▀▄▄█▀  ▀█▄▀ ▀█▄▄▀█▀ ▄██ ██ ██▄ ▄██▄ ▄██▄ ██▄  ▀█▄▄▄▀  ▀█▄▀\033[0;m\n");



//printf("\tEstaminet...\n");
// initialisation du tableau
//printf("\033[1;33m");
for(i=0; i<15; i++){
  for(j=0; j<30; j++){

    if( i == 0 || i == 14 ){
      //printf("\033[1;35m");
      map[i][j]='=';
    }
    else if( j == 0 || j == 29 ){
      map[i][j]='|';
    }

    else{
      //printf("\033[1;34m");
      map[i][j]=' ';

    }
    //Fioles sur étagères
    if(i == 1 && (j == 1 ))
      map[i][j]='&';
    if(i == 1 && (j == 3 ))
      map[i][j]='&';
    if(i == 1 && (j == 5 ))
      map[i][j]='&';
    if(i == 1 && (j == 7 ))
      map[i][j]='&';
    if(i == 1 && (j == 9 ))
      map[i][j]='&';
    if(i == 1 && (j == 11 ))
      map[i][j]='&';
    if(i == 1 && (j == 13 ))
      map[i][j]='&';
    if(i == 1 && (j == 15 ))
      map[i][j]='&';
    if(i == 1 && (j == 17 ))
      map[i][j]='&';
    if(i == 1 && (j == 19 ))
      map[i][j]='&';
    if(i == 1 && (j == 21 ))
      map[i][j]='&';
    if(i == 1 && (j == 23 ))
      map[i][j]='&';
    if(i == 1 && (j == 25 ))
      map[i][j]='&';
    if(i == 1 && (j == 27 ))
      map[i][j]='&';

    //Etagères
    if(i == 2 && (j > 0 && j < 29))
      map[i][j]='-';

    //Camelot
    if(i == 3 && j == 5)
      map[i][j]='C';

    //Barman
    if(i == 3 && j == 25)
      map[i][j]='B';

    //Alchimiste
    //Barman
    if(i == 3 && j == 15)
      map[i][j]='A';

    //Comptoir
    if(i == 4 && (j > 0 && j < 29))
      map[i][j]='_';

    //Héro
    if(i == 6 && j == 15)
      map[i][j]='H';

    //Téléporteur
    if(i == 13 && j == 15)
      map[i][j]='@';

  }
}

  // Affichage du tableau
  for(i=0; i<15; i++){
    for(j=0; j<30; j++){

    //if(map[i][j]=='='){
      //printf("%2c", map[i][j]);
    //}

      printf("%2c",map[i][j]);

      k++;
      if(k%30 == 0){
        printf("\n");
      }
    }
  }

printf("\n");
}

/*
gcc -o main main.c -lm -g -Wall
valgrind --leak-check=yes -s ./main
*/

int interPM(){
  int indice;

  printf("Quelle map souhaitez-vous rejoindre ?\n");
  printf("1.Prairie Verdoyante | 2.Salle du BOSS | 3.Shop/Autre\n");
  printf("Choisir : ");
  scanf("%d", &indice);

  while(indice<1 || indice>3){
    printf("Quelle map souhaitez-vous rejoindre ?\n");
    printf("1.Prairie Verdoyante | 2.Salle du BOSS | 3.Shop/Autre\n");
    printf("Choisir : ");
    scanf("%d", &indice);
  }

  if(indice==1){
    return 0;
  }else if(indice==2){
    return 1;
  }else if(indice==3){
    return 2;
  }
  return 0;
}

// Fonction dédiée à l'interaction objet
// on reprend le principe de celle interPE (interaction Perso Enemy).
void interPO(Player **ppj, int x, int y, int *indice){
  int temp=0;

	temp = ((*ppj)->x + (*ppj)->y) - (x + y);

  if(temp==0){
    printf("OKtp\n");
    *indice = interPM();
  }
}



// Fonction qui permettra l'affichage du perso et des options (déplacement, stats, etc...)
void affStats(Player **ppj){

  purgeSTDIN();

  if((*ppj)->nom[strlen((*ppj)->nom)-1]== '\n') (*ppj)->nom[strlen((*ppj)->nom)-1] = '\0';

  printf("\033[1;33m %s ~ %s [%d, %d]\n", (*ppj)->n_caste, (*ppj)->nom, (*ppj)->x, (*ppj)->y); // Perso
  printf("\033[1;33m  HP : %d;", (*ppj)->hp); // Perso

  printf("\033[1;37m\t\t[↑]:z"); // Déplacement

  printf("\t\t \033[1;33m Zebapik : %d\n", (*ppj)->zebapik); // Perso

  printf("\033[1;33m  DP : %d;", (*ppj)->dp); // Perso

  printf("\033[1;37m  \t [←]:q\t[↓]:s\t[→]:d"); // Déplacement

  printf("\t \033[1;33m Nitrile : %d\n", (*ppj)->nitrile); // Perso

  printf("\033[1;33m  PO : %d;", (*ppj)->po); // Perso

  printf("\t\t\t\t \033[1;33m Niveau : %d (%d)\n", (*ppj)->lvl, (*ppj)->xp); // Perso

  printf("\n");
}

/*
void map1(Player *pj)
{
  char map[25][64], n_map[70]="Prairie verdoyante...";
  char c[20]="bonjour";
  int hp=20, dp=30, po=40;
  int lvl=50;
  int  k;
  int i, j;
  k=0;

  printf("\n");
  printf("\033[1;35m%s\n", n_map);
  // initialisation du tableau
  for(i=0; i<25; i++){
    for(j=0; j<64; j++){

      if( i == 0 || i == 24 ){
        map[i][j]='=';
      }
      else if( j == 0 || j == 63 ){
        map[i][j]='|';
      }
      else{
        map[i][j]='*';
      }

      map[5][9]='H';

    }
  }

  // Affichage du tableau
  for(i=0; i<25; i++){
    for(j=0; j<64; j++){

      if(map[i][j]=='=' || map[i][j]=='|'){
        printf("\033[1;35m%c",map[i][j]);
      }

      if(map[i][j]=='*'){
        printf("\033[0;32m%c",map[i][j]);
      }

      if(map[i][j]=='H'){
        printf("\033[1;33m%c",map[i][j]);
      }

      k++;
      if(k%64 == 0){
        printf("\n");
      }
    }
  }

  printf("\033[1;33mNom : %s;\n HP : %d; \033[1;37m\t\t[↑]:z\n \033[1;33mDP : %d; \033[1;37m\t[←]:q\t[↓]:s\t[→]:d  \n \033[1;33mPO : %d;\n", c, hp, dp, po);

  printf("\n");
}*/
