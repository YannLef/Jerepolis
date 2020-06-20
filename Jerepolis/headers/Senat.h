/**
 * @brief Affiche la popup du batiment
 * @param popups la popup courante
 * @param maximum l'image du bouton maximum
 * @param impossible l'image du bouton impossible
 * @param ameliorer l'image du bouton améliorer
 * @param construire l'image du bouton construire
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * @param fileDeConstruction la tête de liste de la file de construction
 * @param senat le batiment senat
 * @param scierie le batiment scierie
 * @param ferme le batiment ferme
 * @param entrepot le batiment entrepot
 * @param mine le batiment mine
 * @param carriere le batiment carrière
 * @param temple le batiment temple
 * @param caserne le batiment caserne
 * */
void affichePopupSenat(Popups popups, DonneesImageRGB *maximum, DonneesImageRGB *impossible, DonneesImageRGB *ameliorer, DonneesImageRGB *construire, float* bois, float* pierre, float* argent,
ameliorationBatiment* fileDeConstructions, Batiment senat, Batiment scierie, Batiment ferme, Batiment entrepot, Batiment mine, Batiment carriere, Batiment temple, Batiment caserne);

/**
 * @brief Détermine l'abscisse de fin d'un bouton à partir de l'abscisse de début
 * @param xDebut l'abscisse de début du bouton
 * @return l'abscisse de fin du bouton
 * */
int calculeXFinBouton(int xDebut);

/**
 * @brief Détermine l'ordonnée de fin d'un bouton à partir de l'ordonnée de début
 * @param yDebut l'ordonnée de début du bouton
 * @return l'ordonnée de fin du bouton
 * */
int calculeYFinBouton(int yDebut);

/**
 * @brief Gère un clic souris sur la popup du batiment
 * @param popups l'adresse de la popup courante
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du lic souris
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * @param fileDeConstruction l'adresse de la tête de liste de la file de construction
 * @param senat l'adresse du batiment senat
 * @param scierie l'adresse du batiment scierie
 * @param ferme l'adresse du batiment ferme
 * @param carriere l'adresse du batiment carriere
 * @param entrepot l'adresse du batiment entrepot
 * @param mine l'adresse du batiment mine
 * @param caserne l'adresse du batiment caserne
 * @param temple l'adresse du batient temple
 * */
void gereClicGauchePopupSenat(Popups* popups, int x, int y, float* bois, float* pierre, float* argent, ameliorationBatiment** fileDeConstructions, Batiment* senat, Batiment* scierie,
Batiment* ferme, Batiment* carriere, Batiment* entrepot, Batiment* mine, Batiment* caserne, Batiment* temple);

/**
 * @brief Actualise la popup du sénat
 * @param popups l'adresse de  la popup courante
 * */
void actualisePopup(Popups* popups);
