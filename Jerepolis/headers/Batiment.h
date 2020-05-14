/**
 * Donne la version textuelle du type de batiment (énumération)
 * @return le type en version textuelle
 * @param type le type en version énuméré
 * @author Yann.LEFEVRE
 * */
char* getBatimentTypeName(typeBatiment type);

/**
 * Affiche dans la console le descriptif d'un batiment
 * @param batiment le batiment à afficher
 * @author Yann LEFEVRE
 * */
void printBatiment(Batiment batiment);

/**
 * Initialise un batiment au niveau 1 à partir du modèle associé
 * @param b le batiment à initialiser
 * @param m le modèle du batiment
 * @author Yann LEFEVRE
 * */
void initBatiment(Batiment* b, ModeleBatiment* m, int x, int y, int xDebutHitBox, int xFinHitBox, int yDebutHitBox, int yFinHitBox, Popup popup);

/**
 * Ameliore un batiment sous certaines conditions :
 * - la file de constructions ne doit pas être pleine
 * - le batiment ne doit pas déjà être au niveau maximum ou en amélioration pour le niveau maximum
 * - le joueur doit posséder suffisement de bois, pierre, argent
 * @param batiment le batiment à améliorer
 * @param bois le stock de bois
 * @param pierre le stock de pierre
 * @param argent le stock d'argent
 * @param fileDeConstructions la file de constructions
 * @author Yann LEFEVRE
 * */
void amelioreBatiment(Batiment* batiment, float* bois, float* pierre, float* argent, ameliorationBatiment** fileDeConstructions);

/**
 * Affiche un batiment graphiquement
 * @author Yann LEFEVRE
 * */
void afficheBatiment(Batiment b);

/**
 * Gere les clics : détermine s'il est surla hitbox du batiment et agit en fonction
 * @param b le pointeur vers le batiment concerné
 * @param x l'abscisse du clic
 * @param y l'ordonnée du clic
 * @author Yann LEFEVRE
 * */
void gereClicDroitBatiment(Batiment* b, int x, int y);

/**
 * Peuple un batiment en lui affectant le nombre d'habitant voulu
 * @param b le pointeur vers batiment concerné
 * @param nouvellePopulation le nombre d'habitant à affecter au batiment
 * @author Yann LEFEVRE
 * */
void peupleBatiment(Batiment* b, int nouvellePopulation);

/**
 * Simue la production de ressource par le batiment
 * @param b le batiment de production
 * @param ressource la ressource prouite par le batiment
 * @author Yann LEFEVRE
 * */
void genereRessource(Batiment b, float* ressource, int stockageEntrepot);

void gereClicGaucheBatiment(Batiment*  b, int x, int y, Popups* popups);

void afficheInfosBatiment(Batiment senat, DonneesImageRGB* infosBatiment, Batiment ferme, Batiment scierie, Batiment entrepot, Batiment carriere, Batiment caserne, Batiment temple, Batiment mine);
