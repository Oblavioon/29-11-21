#ifndef __ENNEMIS_H__
#define __ENNEMIS_H__

// En vrai on peut donner de l'or aux ennemis
// ça nous permettrait de mettre un truc de loot en place
// Et ainsi faire des échanges directement une fois tuer avec des null ou autre
// En mode pj(pointeur joueur)->po += pe(pointeur ennemis)->po
// C'est vraiment interéssant dans ce contexte.
typedef struct Enemy{
    // Identité
    char n_caste[20];
    int id;

    // Stats Enemy
    int hp; // Pt de vie
    int dp; // Pt de dégât
    int xp; // Pt d'xp
    int lvl; // Niveau
    int po; // Point d'or

    // Ressources
    int zebapik;

    // Positions
    int x;
    int y;

    // Pointeur
    struct Enemy *esuivant;
}Enemy;

typedef struct ListeEnemy{
    Enemy *etete;
}ListeEnemy;



// Prototypes des fonctions dans le Ennemis.c
void initListeEnemy(ListeEnemy *pl);

void initEnemy(Enemy **ppe, ListeEnemy **ppl);

int foncSemiAl(unsigned int aleatoire);

void randEnemy(Enemy **ppe);

void casteGobelin(Enemy **ppe);

void casteOrc(Enemy **ppe);

void casteWorgen(Enemy **ppe);

void depEnemy(Enemy **ppe, int rpt);


#endif
