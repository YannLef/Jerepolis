void chargeImages(DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades, DonneesImageRGB** ameliorer,
DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler);
void initPopups(Popups* popups);
void initBatiments(ModeleBatiment** modeleSenat, Batiment* senat, ModeleBatiment** modeleFerme, Batiment* ferme, ModeleBatiment** modeleCarriere, Batiment* carriere, ModeleBatiment** modeleScierie,
Batiment* scierie, ModeleBatiment** modeleMine, Batiment* mine, ModeleBatiment** modeleEntrepot, Batiment* entrepot, ModeleBatiment** modeleTemple, Batiment* temple, ModeleBatiment** modeleCaserne,
Batiment* caserne);
void afficheBatiments(Batiment senat, Batiment ferme, Batiment carriere, Batiment scierie, Batiment mine, Batiment entrepot, Batiment temple, Batiment caserne);
void afficheBackground(Divinite divinite, DonneesImageRGB* background, DonneesImageRGB* backgroundZeus, DonneesImageRGB* backgroundPoseidon, DonneesImageRGB* backgroundHades);
void gereClicVitesse(int x, int y);
