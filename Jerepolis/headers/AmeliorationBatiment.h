/**
 * Initialise une amélioration de batiment
 * @param amelioration l'adresse de l'amélioration à initialiser
 * @param batiment l'adresse du batiment à améliorer
 * @author Yann LEFEVRE
 * */
void initAmeliorationBatiment(ameliorationBatiment** amelioration, Batiment* batiment);

/**
 * Récupère la taille de la file de construction
 * @return le taille de la file de constructions (le nombre d'améliorations de batiment en cours)
 * @param fileDeConstructions la file de constructions
 * @author Yann LEFEVRE
 * */
int getTailleFileDeConstruction(ameliorationBatiment* fileDeConstructions);

/**
 * Ajoute une amélioration de batiment à la file de constructions
 * @param fileDeConstructions la file de constructions
 * @param amelioration l'amélioration à ajouter à la file de construction
 * @author Yann LEFEVRE
 * */
void ajouteAmeliorationBatiment(ameliorationBatiment** fileDeConstructions, ameliorationBatiment* amelioration);

/**
 * Gere la file de constructions à chaque temporisation
 * @param fileDeCOnstructions la file de constructions
 * @author Yann LEFEVRE
 * */
void gereFileDeConstructions(ameliorationBatiment** fileDeConstructions);

/**
 * Affiche dans la console une amélioration de batiment
 * @param amelioration l'amélioration de batiment à afficher
 * @author Yann LEFEVRE
 * */
void printAmeliorationBatiment(ameliorationBatiment* amelioration);

/**
 * Affiche dans la console la file de constructions complète
 * @param fileDeConstructions la file de constructions à afficher
 * @author Yann LEFEVRE
 * */
void printFileDeConstructions(ameliorationBatiment* fileDeConstructions);

void afficheFileDeConstructions(ameliorationBatiment* fileDeConstructions, DonneesImageRGB* annuler);

void gereClicFileDeConstruction(int x, int y, ameliorationBatiment** fileDeConstructions, float* bois, float* pierre, float* argent);

void annulerConstruction(int numero, ameliorationBatiment** fileDeConstructions, float* bois, float* pierre, float* argent);
int ameliorationsBatimentSuiteFile(ameliorationBatiment* amelioration);
void resetFileDeConstructions(ameliorationBatiment** fileDeConstructions);

void actualiseNiveauBatiment(Batiment* b);
