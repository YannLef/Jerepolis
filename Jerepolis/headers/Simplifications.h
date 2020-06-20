/**
 * @brief Charge toutes les images utilisées par le programme
 * @param accueilBackground l'adresse de la variable qui contiendra l'image du fond de la page d'accueil
 * @param background l'adresse de la variable qui contiendra l'image du fond sans aucune divinité
 * @param backgroundZeus l'adresse de la variable qui contiendra l'image du fond avec Zeus en divinité
 * @param backgroundPoseidon l'adresse de la variable qui contiendra l'image du fond avec Poséidon en divinité
 * @param backgroundHades l'adresse de la variable qui contiendra l'image du fond avec la Hades en divinité
 * @param ameliorer l'adresse de la variable qui contiendra l'image du bouton améliorer
 * @param construire l'adresse de la variable qui contiendra l'image du bouton construire
 * @param impossible l'adresse de la variable qui contiendra l'image du bouton impossible
 * @param maximum l'adresse de la variable qui contiendra l'image du bouton maximum
 * @param infosBatiment l'adresse de la variable qui contiendra l'image des infos batiments
 * @param annuler l'adresse de la variable qui contiendra l'image du bouton annuler
 * @param attaquer l'adresse de la variable qui contiendra l'image du bouton attaquer
 * @param attaqueSortante l'adresse de la variable qui contiendra l'image d'attaque sortante
 * @param retourTroupe l'adresse de la variable qui contiendra l'image de retour de troupes
 * */
void chargeImages(DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades,
DonneesImageRGB** ameliorer, DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler,
DonneesImageRGB** attaquer, DonneesImageRGB** attaqueSortante, DonneesImageRGB** retourTroupe);
void initPopups(Popups* popups);

/**
 * @brief Affiche le fond du jeu en mode partie
 * @param divinite la divinite actuellement vénérée par le joueur
 * @param background le fond sans divinité
 * @param backgroundZeus le fond avec Zeus en divnité
 * @param backgroundPoseidon le fond avec Posédion en divinité
 * @param backgroundHades le fond avec Hades en divinite
 * */
void afficheBackground(Divinite divinite, DonneesImageRGB* background, DonneesImageRGB* backgroundZeus, DonneesImageRGB* backgroundPoseidon, DonneesImageRGB* backgroundHades);

/**
 * @brief gère un clic sur les boutons qui gèrent la vitesse du jeu
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * */
void gereClicVitesse(int x, int y);

/**
 * @brief gère le clic sur le bouton quitter
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * @param p l'adresse des pages
 * */
void gereClicQuitter(int x, int y, Pages* p);

/**
 * @brief Affiche l'armée du joueur
 * @param nbEpee le nombre d'eppee
 * @param nbFrondeur le nombre de frondeur
 * @param nbArcher le nombre d'archers
 * @param nbHoplite le nombre d'hoplites
 * @param nbCavalier le nombre de cavaliers
 * @param nbChar le nombre de char
 * @param nbCatapulte le nombre de catapulte
 * */
void afficheArmee(int nbEpee, int nbFrondeur, int nbArcher, int nbHoplite, int nbCavalier, int nbChar, int nbCatapulte);

/**
 * @brief Affiche les ressources du joueur
 * @param faveur le nombre de faveurs
 * @param bois le nombre de bois
 * @param pierre le nombre de pierre
 * @param argent le nombre d'argent
 * @param capactiePopulationRestante la capacité de population pouvant encore être nourrie
 * */
void afficheRessources(float faveur, float bois, float pierre, float argent, int capacitePopulationRestante);
