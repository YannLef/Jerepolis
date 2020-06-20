/**
 * @brief Donne la version textuelle du type de batiment (énumération)
 * @return le type en version textuelle
 * @param type le type en version énuméré
 * */
char* getBatimentTypeName(typeBatiment type);

/**
 * @brief Affiche dans la console le descriptif d'un batiment
 * @param batiment le batiment à afficher
 * */
void printBatiment(Batiment batiment);

/**
 * @brief Initialise un batiment au niveau 1 à partir du modèle associé
 * @param b le batiment à initialiser
 * @param m le modèle du batiment
 * */
void initBatiment(Batiment* b, ModeleBatiment* m, int x, int y, int xDebutHitBox, int xFinHitBox, int yDebutHitBox, int yFinHitBox, Popup popup);

/**
 * @brief Défini l'icon d'un batiment
 * @param b l'adresse du batiment dont on veut modifier l'icon
 * @param iconImageName le nom de l'icon
 * */
void setIconImage(Batiment* b, char* iconImageName);

/**
 * @brief Défini l'image de popup d'un batient
 * @param b l'adresse du batiment dont on veut modifier la popup
 * @param popupImageName le nom de l'image 
 * */
void setPopupImage(Batiment* b, char* popupImageName);

/**
 * @brief Ameliore un batiment sous certaines conditions :
 * - la file de constructions ne doit pas être pleine
 * - le batiment ne doit pas déjà être au niveau maximum ou en amélioration pour le niveau maximum
 * - le joueur doit posséder suffisement de bois, pierre, argent
 * @param batiment le batiment à améliorer
 * @param bois le stock de bois
 * @param pierre le stock de pierre
 * @param argent le stock d'argent
 * @param fileDeConstructions la file de constructions
 * */
void amelioreBatiment(Batiment* batiment, float* bois, float* pierre, float* argent, ameliorationBatiment** fileDeConstructions);

/**
 * @brief Affiche un batiment graphiquement
 * @param b le batiment à afficher
 * */
void afficheBatiment(Batiment b);

/**
 * @brief Gere les clics : détermine s'il est surla hitbox du batiment et agit en fonction
 * @param b le pointeur vers le batiment concerné
 * @param x l'abscisse du clic
 * @param y l'ordonnée du clic
 * */
void gereClicDroitBatiment(Batiment* b, int x, int y);

/**
 * @brief Peuple un batiment en lui affectant le nombre d'habitant voulu
 * @param b le pointeur vers batiment concerné
 * @param nouvellePopulation le nombre d'habitant à affecter au batiment
 * */
void peupleBatiment(Batiment* b, int nouvellePopulation);

/**
 * Simue la production de ressource par le batiment
 * @param b le batiment de production
 * @param ressource la ressource prouite par le batiment
 * */
void genereRessource(Batiment b, float* ressource, int stockageEntrepot);

/**
 * @brief Gere le clic gauche de la souris sur un batiment
 * @param b l'adresse du batiment dont on veut gérer le clic
 * @param x l'abscisse du clic souris
 * @param y l'ordonnee du clic souris
 * @param popups l'adresse de la popup courante
 * */
void gereClicGaucheBatiment(Batiment*  b, int x, int y, Popups* popups);

/**
 * @brief Affiche les informations des batiments (population/population max & niveau / niveau max)
 * @param senat le batiment senat
 * @param infosBatiment l'image de fond des infos
 * @param ferme le batiment ferme
 * @param scierie le batiment scierie
 * @param entrepot le batiment entrepot
 * @param carriere le batiment carriere
 * @param caserne le batiment caserne
 * @param temple le batiment temple
 * @param mine le batiment mine
 * */
void afficheInfosBatiment(Batiment senat, DonneesImageRGB* infosBatiment, Batiment ferme, Batiment scierie, Batiment entrepot, Batiment carriere, Batiment caserne, Batiment temple, Batiment mine);

/**
 * @brief Initialise les batiments
 * @param modelSenat l'adresse du modele du senat
 * @param senat l'adresse du batiment senat
 * @param modeleFerme l'adresse du modele ferme
 * @param ferme l'adresse du batiment ferme
 * @param modeleCarriere l'adresse du modèle carrière
 * @param carriere l'adresse du batiment carriere
 * @param modeleScierie l'adresse du modele scierie
 * @param scierie l'adresse du batiment scierie
 * @param modeleMine l'adresse du modele mine
 * @param mine l'adresse du batiment mine
 * @param modeleEntrepot l'adresse du modele entrepot
 * @param entrepot l'adresse du batiment entrepot
 * @param modeleTemple l'adresse du modele temple
 * @param temple l'adresse du batiment temple
 * @param modeleCaserne l'adresse du modele caserne
 * @param caserne l'adresse du batiment caserne
 * */
void initBatiments(ModeleBatiment** modeleSenat, Batiment* senat, ModeleBatiment** modeleFerme, Batiment* ferme, ModeleBatiment** modeleCarriere, Batiment* carriere, ModeleBatiment** modeleScierie,
Batiment* scierie, ModeleBatiment** modeleMine, Batiment* mine, ModeleBatiment** modeleEntrepot, Batiment* entrepot, ModeleBatiment** modeleTemple, Batiment* temple, ModeleBatiment** modeleCaserne,
Batiment* caserne);

/**
 * @brief Remet à zéro les batiments
 * @param modelSenat le modele du senat
 * @param senat l'adresse du batiment senat
 * @param modeleFerme lle modele ferme
 * @param ferme l'adresse du batiment ferme
 * @param modeleCarriere le modèle carrière
 * @param carriere l'adresse du batiment carriere
 * @param modeleScierie le modele scierie
 * @param scierie l'adresse du batiment scierie
 * @param modeleMine le modele mine
 * @param mine l'adresse du batiment mine
 * @param modeleEntrepot le modele entrepot
 * @param entrepot l'adresse du batiment entrepot
 * @param modeleTemple le modele temple
 * @param temple l'adresse du batiment temple
 * @param modeleCaserne le modele caserne
 * @param caserne l'adresse du batiment caserne
 * */
void resetBatiments(ModeleBatiment* modeleSenat, Batiment* senat, ModeleBatiment* modeleFerme, Batiment* ferme, ModeleBatiment* modeleCarriere, Batiment* carriere, ModeleBatiment* modeleScierie,
Batiment* scierie, ModeleBatiment* modeleMine, Batiment* mine, ModeleBatiment* modeleEntrepot, Batiment* entrepot, ModeleBatiment* modeleTemple, Batiment* temple, ModeleBatiment* modeleCaserne,
Batiment* caserne);

/**
 * @brief Affiche les batiments
 * @param senat le batiment senat
 * @param ferme le batiment ferme
 * @param carriere le batiment carriere
 * @param scierie le batiment scierie
 * @param mine le batiment mine
 * @param entrepot le batiment entrepot
 * @param temple le batiment temple
 * @param caserne le batiment caserne
 * */
void afficheBatiments(Batiment senat, Batiment ferme, Batiment carriere, Batiment scierie, Batiment mine, Batiment entrepot, Batiment temple, Batiment caserne);
