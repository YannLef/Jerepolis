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
void initBatiment(Batiment* b, ModeleBatiment* m, int x, int y);

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
void amelioreBatiment(Batiment* batiment, int* bois, int* pierre, int* argent, ameliorationBatiment** fileDeConstructions);

/**
 * Affiche un batiment graphiquement
 * @author Yann LEFEVRE
 * */
void afficheBatiment(Batiment b);

void gereClicBatiment(Batiment* senat, int x, int y, int* bois, int* pierre, int* argent, ameliorationBatiment** fileDeConstructions);
