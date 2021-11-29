#ifndef H_MAP_H
#define H_MAP_H

// Prototypes
//void deplacement(Player **ppj);

void pVerdoyante(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

void salleBoss(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

void estaminet(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

int interPM();

void interPO(Player **ppj, int x, int y, int *indice);

void affStats(Player **ppj);

#endif
