void affichePopupSenat(Popups popups, DonneesImageRGB *maximum, DonneesImageRGB *impossible, DonneesImageRGB *ameliorer, DonneesImageRGB *construire, float* bois, float* pierre, float* argent, ameliorationBatiment* fileDeConstructions,
Batiment senat, Batiment scierie, Batiment ferme, Batiment entrepot, Batiment mine, Batiment carriere, Batiment temple, Batiment caserne);

int calculeXFinBouton(int xDebut);

int calculeYFinBouton(int yDebut);

void gereClicGauchePopupSenat(Popups* popups, int x, int y, float* bois, float* pierre, float* argent, ameliorationBatiment** fileDeConstructions, Batiment* senat, Batiment* scierie,
Batiment* ferme, Batiment* carriere, Batiment* entrepot, Batiment* mine, Batiment* caserne, Batiment* temple);
void actualisePopup(Popups* popups);
