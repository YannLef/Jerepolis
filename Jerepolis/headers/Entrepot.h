/**
 * @brief Actualise la capacité maximale de stockage de l'entrepot
 * @param stockageEntrepot l'adresse du nombre max stocké
 * @param entrepot le batiment entrepot
 * */
void actualiseStockageEntrepot(int* stockageEntrepot, Batiment entrepot);

/**
 * @brief Affiche la popup du batiment
 * @param popups la popup courante
 * @param entrepot le batiment entrepot
 * */
void affichePopupEntrepot(Popups popups, Batiment entrepot, float bois, float pierre, float argent, int stockageEntrepot);

/**
 * @brief Gère un clic souris sur la popup du batiment
 * @param popups l'adresse de la popup courante
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du lic souris
 * */
void gereClicGauchePopupEntrepot(Popups* popups, int x, int y);
