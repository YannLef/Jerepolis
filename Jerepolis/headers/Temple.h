/**
 * @brief Affiche la popup du temple
 * @param popups la popus courante
 * @param temple le batiment temple
 * */
void affichePopupTemple(Popups popups, Batiment temple);

/**
 * @brief Gère un clic gauche de souris sur la popup du temple
 * @param popups l'adresse de la popup courante
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * @param temple l'adresse du batiment temple
 * @param faveur l'adresse du nombre de faveurs
 * @param divinite l'adresse de la divinité de la ville
 * */
void gereClicGauchePopupTemple(Popups* popups, int x, int y, Batiment* temple, float* faveur, Divinite* divinite);

/**
 * @brief Génère les faveurs en fonction de la population du temple
 * @param temple le batiment temple
 * @param divinité la divinité de la ville
 * @param faveurs l'adresse du nombre de faveurs
 * */
void genereFaveurs(Batiment temple, Divinite divinite, float* faveur);
