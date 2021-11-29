#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include "ennemis.h"

// Structure Player
// Propre à chacun des joueurs...
// À voir ce qui peut être attribué en fonction de chaque classe...
typedef struct Player Player;
struct Player{
    // Identité
    char nom[20];
    int sexe; // 1=G & 2=F
    char n_caste[20];
    char logo_caste[10];

    // Stats joueurs
    int hp; // Pt de vie
    int dp; // Pt de dégât
    int xp; // Pt d'xp
    int lvl; // Niveau
    int po; // Point d'or

    // Ressources
    int zebapik; // Comme les joker etc.. à voir utilité
    int nitrile; // Minerai

    // Coordonnées
    int x; // Elles seront importantes pour la sauvegarde
    int y; // nous permettra à la fois déplacement du joueur et sa savuegarde sur la map
    char n_map[50]; // utile pour la sauvegarde, savoir sur quel plateau s'est arrêté le joueur
                    // avec une comparaison des chaines de caractère (une fonction bien à elle)...

    // Pointeur pour liste
    Player *psuivant;
};



// Structure Liste
// Pourra nous servir pour les sauvgarde etc...
typedef struct ListePlayer{
    Player *tete;
}ListePlayer;




// Prototypes
void* malloc_protege(size_t s);

void initListe(ListePlayer *pl);

void initPlayer(Player **ppj, ListePlayer **ppl);

void initCaste(Player **ppj);

void casteG(Player **ppj);

void casteV(Player **ppj);

void depPerso(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

#endif
