void initRecrutementUnite(RecrutementUnite** recrutement, int nbUnite, Unite* u);
void ajouteRecrutementUnite(RecrutementUnite** fileDeRecrutement, RecrutementUnite* recrutement);
void afficheFileDeRecrutement(RecrutementUnite* fileDeRecrutement, DonneesImageRGB* annuler, Popups popups);
int getTailleFileDeRecrutement(RecrutementUnite* fileDeRecrutement);
void printRecrutementUnite(RecrutementUnite recrutement);
void gereClicFileDeRecrutement(int x, int y, RecrutementUnite** fileDeRecrutement, Popups popups, float* bois, float* pierre, float* argent, float* faveur);
void annulerRecrutement(int numero, RecrutementUnite** fileDeRecrutement, float* bois, float* pierre, float* argent, float* faveur);
void gereFileDeRecrutement(RecrutementUnite** fileDeRecrutement, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte);
void resetFileDeRecrutement(RecrutementUnite** fileDeRecrutement);
