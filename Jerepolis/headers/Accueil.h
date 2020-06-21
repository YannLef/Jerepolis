/**
 * @brief Gère le clic de la souris sur l'accueil
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * @brief Quitte le programme proprement
 * @param accueilBackground l'adresse de l'image accueilBackground
 * @param background l'adresse de l'image background
 * @param backgroundZeus l'adresse de l'image backgroundZeus
 * @param backgroundPoseidon l'adresse de l'image backgroundPoseidon
 * @param backgroundHades l'adresse de l'image backgroundHades
 * @param ameliorer l'adresse de l'image ameliorer
 * @param construire l'adresse de l'image construire
 * @param impossible l'adresse de l'image impossible
 * @param maximum l'adresse de l'image maximum
 * @param infosBatiment l'adresse de l'image infosBatiment
 * @param annuler l'adresse de l'image annuler
 * @param p l'adresse de la page courante
 * @param modeleSenat le modele du batiment senat
 * @param senat l'adresse du batiment senat
 * @param modeleFerme le modele du batiment ferme
 * @param ferme l'adresse du batiment ferme
 * @param modeleCarriere le modele du batiment carriere
 * @param carriere l'adresse du batiment carriere
 * @param modeleScierie le modele du batiment scierie
 * @param scierie l'adresse du batiment scierie
 * @param modeleMine le modele du batiment mine
 * @param mine l'adresse du batiment mine
 * @param modeleEntrepot le modele du batiment entrepot
 * @param entrepot l'adresse du batiment entrepot
 * @param modeleTemple le modele du batiment temple
 * @param temple l'adresse du batiment temple
 * @param modeleCaserne le modele du batiment caserne
 * @param caserne l'adresse du batiment caserne
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * @param faveur l'adresse du nombre de faveurs
 * @param nbEpee l'adresse du nombre d'epee
 * @param nbFrondeur l'adresse du nombre de frondeurs
 * @param nbArcher l'adresse du nombre d'archers
 * @param nbHoplite l'adresse du nombre d'hoplites
 * @param nbCavalier l'adresse du nombre de cavalirs
 * @param nbChar l'adresse du nombre de char
 * @param nbCatapulte l'adresse du nombre de catapultes
 * @param fileDeConstruction l'adresse de la tete de liste de la file de constuctions
 * @param fileDeRecrutement l'adresse de la tete e liste de las file de recrutement
 * @param divinite l'adresse de la divinité actuelle
 * @param popups l'adresse de la popups courante
 * @param divinite_selec l'adresse du choix de la divinité actuelle dans le temple
 * @param troupe l'adresse de du choix de la troupe actuelle dans la caserne
 * @param nb_troupe l'adresse du nombre de troupe dans la caserne
 * @param nomVille l'adresse de l'input text permettant de choisir le nom de la ville actuelle

 * */
void gereClicAccueil(int x, int y, DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon,
DonneesImageRGB** backgroundHades, DonneesImageRGB** ameliorer, DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment,
DonneesImageRGB** annuler, Pages* p, ModeleBatiment* modeleSenat, Batiment* senat, ModeleBatiment* modeleFerme, Batiment* ferme, ModeleBatiment* modeleCarriere, Batiment* carriere,
ModeleBatiment* modeleScierie, Batiment* scierie, ModeleBatiment* modeleMine, Batiment* mine, ModeleBatiment* modeleEntrepot, Batiment* entrepot, ModeleBatiment* modeleTemple, Batiment* temple,
ModeleBatiment* modeleCaserne, Batiment* caserne, float* bois, float* pierre, float* argent, float* faveur, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier,
int* nbChar, int* nbCatapulte, ameliorationBatiment** fileDeConstructions, RecrutementUnite** fileDeRecrutement, Divinite* divinite, Popups* popups, Divinite* divinite_selec, Troupe* troupe,
int* nb_troupe, InputText* nomVille, EvenementTroupe** listeEvenementTroupe, Ennemi* ennemi);

/**
 * @brief Libère une image
 * @param img l'adresse de l'image à libérer
 * */
void freeImage(DonneesImageRGB** img);

/**
 * @brief Quitte le programme proprement
 * @param accueilBackground l'adresse de l'image accueilBackground
 * @param background l'adresse de l'image background
 * @param backgroundZeus l'adresse de l'image backgroundZeus
 * @param backgroundPoseidon l'adresse de l'image backgroundPoseidon
 * @param backgroundHades l'adresse de l'image backgroundHades
 * @param ameliorer l'adresse de l'image ameliorer
 * @param construire l'adresse de l'image construire
 * @param impossible l'adresse de l'image impossible
 * @param maximum l'adresse de l'image maximum
 * @param infosBatiment l'adresse de l'image infosBatiment
 * @param annuler l'adresse de l'image annuler
 * */
void quitteProgramme(DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades,
DonneesImageRGB** ameliorer, DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler);
