#ifndef H_MENU_H
#define H_MENU_H



//FILE* fopen(const char* nomDuFichier, const char* modeOuverture);
//int fclose(FILE* pointeurSurFichier);
void purgeSTDIN();

void intro(unsigned int choix);

void confChoix();

void menuDemarrage(Player **ppj, ListePlayer **ppl);

void menu_jeu(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

void menuAttack(Player **ppj, Enemy **ppe);

void menuCombat(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

/*
void menuCombatOrc(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

void menuCombatGobelin(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

void menuCombatWorgen(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);
*/

/*
int menuCreationPerso();
int menuNom(Player *pp);
int menuSexe(Player *pp);
int menuCasteMale(Player *pp);
int menuCasteFemelle();
*/

#endif
