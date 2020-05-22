void chargeImages(DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades,
DonneesImageRGB** ameliorer, DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler,
DonneesImageRGB** attaquer, DonneesImageRGB** attaqueSortante, DonneesImageRGB** retourTroupe);
void initPopups(Popups* popups);
void afficheBackground(Divinite divinite, DonneesImageRGB* background, DonneesImageRGB* backgroundZeus, DonneesImageRGB* backgroundPoseidon, DonneesImageRGB* backgroundHades);
void gereClicVitesse(int x, int y);
void gereClicQuitter(int x, int y, Pages* p);
void afficheArmee(int nbEpee, int nbFrondeur, int nbArcher, int nbHoplite, int nbCavalier, int nbChar, int nbCatapulte);
void afficheRessources(float faveur, float bois, float pierre, float argent, int capacitePopulationRestante);
