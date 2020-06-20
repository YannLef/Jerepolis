/**
 * @brief Initialise une amélioration de batiment
 * @param amelioration l'adresse de l'amélioration à initialiser
 * @param batiment l'adresse du batiment à améliorer
 * */
void initAmeliorationBatiment(ameliorationBatiment** amelioration, Batiment* batiment);

/**
 * @brief Récupère la taille de la file de construction
 * @return le taille de la file de constructions (le nombre d'améliorations de batiment en cours)
 * @param fileDeConstructions la file de constructions
 * */
int getTailleFileDeConstruction(ameliorationBatiment* fileDeConstructions);

/**
 * @brief Ajoute une amélioration de batiment à la file de constructions
 * @param fileDeConstructions la file de constructions
 * @param amelioration l'amélioration à ajouter à la file de construction
 * */
void ajouteAmeliorationBatiment(ameliorationBatiment** fileDeConstructions, ameliorationBatiment* amelioration);

/**
 * @brief Gere la file de constructions à chaque temporisation
 * @param fileDeCOnstructions la file de constructions
 * */
void gereFileDeConstructions(ameliorationBatiment** fileDeConstructions);

/**
 * @brief Affiche dans la console une amélioration de batiment
 * @param amelioration l'amélioration de batiment à afficher
 * */
void printAmeliorationBatiment(ameliorationBatiment* amelioration);

/**
 * @brief Affiche dans la console la file de constructions complète
 * @param fileDeConstructions la file de constructions à afficher
 * */
void printFileDeConstructions(ameliorationBatiment* fileDeConstructions);

/**
 * @brief Affiche la file de constructions
 * @param fileDeConstruction la tete de liste
 * @param annuler l'image d'annulation de construction/amélioration
 * */
void afficheFileDeConstructions(ameliorationBatiment* fileDeConstructions, DonneesImageRGB* annuler);

/**
 * @brief Gère un clic sur la file de constructions
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * @param fileDeConstructions l'adresse de la tete de liste de la file de constructions
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * */
void gereClicFileDeConstruction(int x, int y, ameliorationBatiment** fileDeConstructions, float* bois, float* pierre, float* argent);

/**
 * @brief Annule une construction/amélioration de la liste
 * @param numero le rang de la construction à annuler dans la liste
 * @param fileDeConstruction l'adresse de la tete de liste
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * */
void annulerConstruction(int numero, ameliorationBatiment** fileDeConstructions, float* bois, float* pierre, float* argent);

/**
 * @brief Vérifie s'il y a déjà une amélioration en cours du batiment
 * @param amelioration l'amélioration 
 * */
int ameliorationsBatimentSuiteFile(ameliorationBatiment* amelioration);

/**
 * @brief Remet à zéro la file de constructions
 * @param fileDeConstruction l'adresse de la tete de liste 
 * */
void resetFileDeConstructions(ameliorationBatiment** fileDeConstructions);

/**
 * @brief Actualise un batiment en fonction de son noveau niveau via l'utilisation de son modèle
 * @param b le batiment à actualiser
 * */
void actualiseNiveauBatiment(Batiment* b);
