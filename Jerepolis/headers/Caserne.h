void initUnite(Unite* u, int prixBois, int prixPierre, int prixArgent, int prixFaveur, int population, int temps, int attaque, int vitesse, int capacite);
void initUnites(Unite* epee, Unite* frondeur, Unite* archer, Unite* hoplite, Unite* cavalier, Unite* charr, Unite* catapulte);
void chargeAffichageUnite(char prixBois[100], char prixPierre[100], char prixArgent[100], char prixFaveur[100], char population[100], char temps[100], char attaque[100], char vitesse[100],
char capacite[100], Unite u, int nb_troupe);
void affichePopupCaserne(Popups popups, Batiment caserne, Troupe troupe, int nb_troupe, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);
void gereClicGauchePopupCaserne(Popups* popups, int x, int y, Batiment* caserne, float* bois, float* pierre, float* argent, float* faveur, Troupe* troupe, int* nb_troupe, Unite epee, 
Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);
