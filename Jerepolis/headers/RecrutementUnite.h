/**
 * @brief Initialise le recrutement d'une unité
 * @param recrutement le recrutement à initialiser
 * @param nbUnité le nombre d'unité à recrutement
 * @param u l'adresse de l'unité à recruter
 * */
void initRecrutementUnite(RecrutementUnite** recrutement, int nbUnite, Unite* u);

/**
 * @brief Ajoute le recrutement à la liste de recrutement
 * @param fileDeRecrutement l'adresse de la tête de liste
 * @param recrutement le recrutement à ajouter
 * */
void ajouteRecrutementUnite(RecrutementUnite** fileDeRecrutement, RecrutementUnite* recrutement);

/**
 * @brief Affiche la file de recrutement
 * @param fileDeRecrutement al tête de liste de la file de recrutement
 * @param annuler l'image du bouton annuler
 * @param popups la popup courante
 * */
void afficheFileDeRecrutement(RecrutementUnite* fileDeRecrutement, DonneesImageRGB* annuler, Popups popups);

/**
 * @brief Détermine la taille de la file de rerutement
 * @param fileDeRecrutement la tete de lste de la file de recrutement
 * @return la taille de la file de recrutement
 * */
int getTailleFileDeRecrutement(RecrutementUnite* fileDeRecrutement);

/**
 * @brief Affiche dans le terminal un recrutement d'unité
 * @param recrutement le recrutement d'unité à afficher
 * */
void printRecrutementUnite(RecrutementUnite recrutement);

/**
 * @brief Gère un clic sur la file de recrutement
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * @param fileDeRecrutement l'adresse de la tête de liste de la file de recrutement
 * @param popups la popup courante
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * @param faveur l'adresse du nombre d'argent
 * */
void gereClicFileDeRecrutement(int x, int y, RecrutementUnite** fileDeRecrutement, Popups popups, float* bois, float* pierre, float* argent, float* faveur);

/**
 * @brief Annule un recrutement
 * @param numero le rang du recrutement à annuler dans la file de recrutement
 * @param fileDeRecrutement l'adresse de la tête de liste de la file de recrutement
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * @param faveur l'adresse du nombre de faveurs
 * */
void annulerRecrutement(int numero, RecrutementUnite** fileDeRecrutement, float* bois, float* pierre, float* argent, float* faveur);

/**
 * @brief Gère la file de recrutement à chaque boucle
 * @param caserne le batiment caserne
 * @param fileDeRecrutement l'adresse de la tête de liste de la file de recrutement
 * @param nbEpee l'adresse du nombre d'épée 
 * @param nbFrondeur l'adresse du nombre de frondeur
 * @param nbArcher l'adresse du nombre d'archers
 * @param nbHoplite l'adresse du nombre d'hoplites
 * @param nbCavalier l'adresse du nombre de cavaliers
 * @param nbChar l'adresse du nombre de chars
 * @param nbCatapulte l'adresse du nombre de catapultes
 * */
void gereFileDeRecrutement(Batiment caserne, RecrutementUnite** fileDeRecrutement, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte);

/**
 * @brief Remet à zéro la file de recrutement
 * @param fileDeRecrutement l'adresse de la tête de liste de la file de recrutement
 * */
void resetFileDeRecrutement(RecrutementUnite** fileDeRecrutement);
