void gereClicAttaquerMain(int x, int y, Popups* p);
void affichePopupAttaque(Popups p, DonneesImageRGB* attaquer, int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Ennemi e);
void initAttTroupes(int* nbAttEpee, int* nbAttFrondeur, int* nbAttArcher, int* nbAttHoplite, int* nbAttCavalier, int* nbAttChar, int* nbAttCatapulte);
void clicPopupAttaque(int x, int y, Popups* p, int* nbAttEpee, int* nbAttFrondeur, int* nbAttArcher, int* nbAttHoplite, int* nbAttCavalier, int* nbAttChar, int* nbAttCatapulte, int* nbEpee,
int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe, Ennemi* ennemi, Unite epee, Unite frondeur, Unite archer,
Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);
int calculeVitesseArmee(int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Unite epee, Unite frondeur, Unite archer, Unite hoplite,
Unite cavalier, Unite charr, Unite catapulte);
int calculeTempsDeTrajet(int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Unite epee, Unite frondeur, Unite archer, Unite hoplite,
Unite cavalier, Unite charr, Unite catapulte, Ennemi ennemi);
