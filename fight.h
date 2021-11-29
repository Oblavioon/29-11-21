#ifndef __FIGHT_H__
#define __FIGHT_H__

#include "ennemis.h"

// Prototypes
void affStatsComb(Player **ppj, Enemy **ppe);

void interPE(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

void headShot(Player **ppj, Enemy **ppe, int choix);

void chestShot(Player **ppj, Enemy **ppe, int choix);

void limbShot(Player **ppj, Enemy **ppe, int choix);



#endif
