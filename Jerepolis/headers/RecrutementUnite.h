void initRecrutementUnite(RecrutementUnite** recrutement, int nbUnite, Unite* u);
void ajouteRecrutementUnite(RecrutementUnite** fileDeRecrutement, RecrutementUnite* recrutement);
void afficheFileDeRecrutement(RecrutementUnite* fileDeRecrutement, DonneesImageRGB* annuler);
int getTailleFileDeRecrutement(RecrutementUnite* fileDeRecrutement);
void printRecrutementUnite(RecrutementUnite recrutement);
void gereClicFileDeRecrutement(int x, int y, RecrutementUnite** fileDeRecrutement, Popups popups, float* bois, float* pierre, float* argent, float* faveur);
void annulerRecrutement(int numero, RecrutementUnite** fileDeRecrutement, float* bois, float* pierre, float* argent, float* faveur);
