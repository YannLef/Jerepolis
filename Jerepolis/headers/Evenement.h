void initEvenementTroupe(EvenementTroupe** e, int timer, TypeEvenement type, Ennemi* ennemi, int nbEpee, int nbFrondeur, int nbArcher, int nbHoplite, int nbCavalier, int nbChar, int nbCatapulte);
void insertEvenementTroupe(EvenementTroupe* e, EvenementTroupe** listeEvenementTroupe);
void printEvenementTroupe(EvenementTroupe* e);
void printListeEvenementTroupe(EvenementTroupe* e);
void gereListeEvenementTroupe(EvenementTroupe** listeEvenementTroupe, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte);
void finEvenementTroupe(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte, EvenementTroupe** listeEvenementTroupe,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte);
int combat(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);
void calculeUnitesRestantes(int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, int resultat, int attaque);
void afficheEvenement(EvenementTroupe* e, int numero, DonneesImageRGB* attaqueSortante, DonneesImageRGB* retourTroupe);
void afficheListeEvenementTroupe(EvenementTroupe* e, DonneesImageRGB* attaqueSortante, DonneesImageRGB* retourTroupe);
