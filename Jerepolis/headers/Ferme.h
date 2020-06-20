/**
 * @brief Actualise la capactié de population pouvant encore être nourrie en fonction de la ferme et de la population actuelle
 * @param capacitePopulationRestante l'adresse du nombre de population libre restante
 * @param ferme le batiment ferme
 * @param senat le batiment senat
 * @param entrepot le batiment entrepot
 * @param scierie le batiment scierie
 * @param temple le batiment temple
 * @param carriere le batiment carrière
 * @param caserne le batiment caserne
 * @param mine le batiment mine
 * @param nbEpee le nombre d'épee
 * @param nbFrondeur le nombre de frondeur
 * @param nbArcher le nombre d'archers
 * @param nbHoplite le nombre d'hoplites
 * @param nbCavalier le nombre de cavaliers
 * @param nbChar le nombre de chars
 * @param nbCatapulte le nombre de catapultes
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l"unité charr
 * @param catapulte l'unité catapulte
 * */
void actualiseCapacitePopulationRestante(int* capacitePopulationRestante, Batiment ferme, Batiment senat, Batiment entrepot, Batiment scierie, Batiment temple, Batiment carriere, Batiment caserne,
Batiment mine, int nbEpee, int nbFrondeur, int nbArcher, int nbHoplite, int nbCavalier, int nbChar, int nbCatapulte, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier,
Unite charr, Unite catapulte);

/**
 * @brief Affiche la popuup de la ferme
 * @param popups la popups courante
 * @param ferme le batiment ferme
 * */
void affichePopupFerme(Popups popups, Batiment ferme);

/**
 * @brief Gère le clic gauche de la souris sur la popup de la ferme
 * @param popups l'adresse de la popup courante
 * @param x l'abscsisse du clic souris
 * @param y l'ordonnée du clic souris
 * */
void gereClicGauchePopupFerme(Popups* popups, int x, int y);

/**
 * @param Calcule la population d'une unité en fonction du nombre de cette unité
 * @param u l'unité
 * @param le nombre de cette unité
 * @return la population totale occupée par ce type d'unité
 * */
int calculePopulationUnite(Unite u, int nbUnite);
