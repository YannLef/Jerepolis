/**
 * @brief Initialise une unité
 * @param u l'adresse de l'unité à initialiser
 * @param nom le nom de l'unité
 * @param prixBois le prix en bois de l'unité
 * @param prixPierre le prix en pierre de l'unité
 * @param prixArgent le prix en argent de l'unité
 * @param prixFaveur le prix en faveurs de l'unité
 * @param population le coût en population libre de l'unité
 * @param temps le temps de formation de l'unité
 * @param attauqe l'attaque de l'unité
 * @param vitesseTrp la vitesse de déplacement de l'unité
 * @param capactié la capactié de transport de ressources de l'unité
 * @param type le type d'unité
 * */
void initUnite(Unite* u, char* nom, int prixBois, int prixPierre, int prixArgent, int prixFaveur, int population, int temps, int attaque, int vitesseTrp, int capacite, Troupe type);

/**
 * @brief Initialise toutes les unités
 * @param epee l'adresse de l'unité épee
 * @param frondeur l'adresse de l'unité frondeur
 * @param archer l'adresse de l'unité archer
 * @param hopite l'adresse de l'unité hoplite
 * @param cavalier l'adresse de l'unité cavalier
 * @param charr l'adresse de l'unité char
 * @param catapulte l'adresse de l'unité catapulte 
 * */
void initUnites(Unite* epee, Unite* frondeur, Unite* archer, Unite* hoplite, Unite* cavalier, Unite* charr, Unite* catapulte);

/**
 * @brief Charge en mémoir l'affichage de l'unité
 * @param caserne le batiment caserne
 * @param prixBois l'affichage du prix en bois
 * @param prixPierre l'affichage du prix en pierre
 * @param prixArgent l'affichage du prix en argent
 * @param prixFaveur l'affichage du prix en faveurs
 * @param population l'affichage de la population occupée par l'unité
 * @param temps l'affichage du temps de foramation de l'unité
 * @param attaque l'affichage de l'attaque de l'unité
 * @param vitesseTrp l'affichage de la vitesse de déplacement de l'unité
 * @param capacité l'affichage de la capactié de pillage de l'unité
 * @param u l'unité à afficher
 * @param nb_troupe le nombre d'unité à afficher
 * */
void chargeAffichageUnite(Batiment caserne, char prixBois[100], char prixPierre[100], char prixArgent[100], char prixFaveur[100], char population[100], char temps[100], char attaque[100],
char vitesseTrp[100], char capacite[100], Unite u, int nb_troupe);

/**
 * @brief Affiche la popup du batiment caserne
 * @param popups la popup courante
 * @param caserne le batimen caserne
 * @param troupe la troupe affichée
 * @param nb_troupe le nombre de troupe affichée
 * @param epee l'unité épee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * */
void affichePopupCaserne(Popups popups, Batiment caserne, Troupe troupe, int nb_troupe, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);

/**
 * @brief Gère un clic gauche de souris sur la popup de la caserne
 * @param popups l'adresse de la popup courante
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * @param caserne l'adresse du batiment caserne
 * @param bois l'adresse du nombre de bois
 * @param pierre l'adresse du nombre de pierre
 * @param argent l'adresse du nombre d'argent
 * @param faveur l'adresse du nombre de faveurs
 * @param troupe la troupe affichée dans la popup
 * @param nb_troupe le nombre de troupes affichées dans la popup
 * @param epee l'unité épee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * @param fileDeRecrutement l'adresse de la tete de liste de la file de recrutement
 * */
void gereClicGauchePopupCaserne(Popups* popups, int x, int y, Batiment* caserne, float* bois, float* pierre, float* argent, float* faveur, Troupe* troupe, int* nb_troupe, Unite* epee, 
Unite* frondeur, Unite* archer, Unite* hoplite, Unite* cavalier, Unite* charr, Unite* catapulte, RecrutementUnite** fileDeRecrutement);

/**
 * @brief Ajoute une unité à l'armée
 * @param type le type d'unité à ajouter
 * @param nbEpee l'adresse du nombre d'épéé
 * @param nbFrondeur l'adresse du nombre de frondeurs
 * @param nbArcher l'adresse du nombre d'archer
 * @param nbHoplite l'adresse du nombre d'hoplites
 * @param nbCavalier l'adresse du nombre de cavalirs
 * @param nbChar l'adresse du nombre de char
 * @param nbCatapulte l'adresse du nombre de catapulte
 * */
void ajouteUnite(Troupe type, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte);
