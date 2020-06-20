/**
 * @brief Initialise un evenement de troupes
 * @param e l'adresse de l'evenemet à initialiser
 * @param timer le temps restant avant la fin de l'evenement
 * @param type le type d'evenement
 * @param ennemi l'ennemi
 * @param nbEpee le nombre d'epee
 * @param nbFrondeur le nombre de frondeurs
 * @param nbArcher le nombre d'archers
 * @param nbHoplite le nombre d'hoplites
 * @param nbCavalier le nombre de cavaliers
 * @param nbChar le nombre de char
 * @param nbCatapulte le nombre de catapultes
 * @param victoire si l'évènement va de pair avec une victoir (1) ou pas (0) : utile pour les retour de troupe
 * */
void initEvenementTroupe(EvenementTroupe** e, int timer, TypeEvenement type, Ennemi* ennemi, int nbEpee, int nbFrondeur, int nbArcher, int nbHoplite, int nbCavalier, int nbChar, int nbCatapulte,
int victoire);

/**
 * @brief Permet d'ajouter un evenement de troupe dans la liste
 * @param e l'evenement à ajouter
 * @param listeEvenementTroupe l'adresse de la tete de liste
 * */
void insertEvenementTroupe(EvenementTroupe* e, EvenementTroupe** listeEvenementTroupe);

/**
 * @brief Affiche un evenement de troupe
 * @param e l'evenement à afficher
 * */
void printEvenementTroupe(EvenementTroupe* e);

/**
 * @brief Affiche la liste des evenements de troupe
 * @param e la tete de liste des evenements de troupes
 * */
void printListeEvenementTroupe(EvenementTroupe* e);

/**
 * @brief Gere la liste des evenements de troupe
 * @param listeEvenementTroupe l'adresse de la tete de liste
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * @param nbEpee l'adresse du nombre d'eppe
 * @param nbFrondeur l'adresse du nombre de frondeurs
 * @param nbArcher l'adresse du nombre d'archers
 * @param nbHoplite l'adresse du nombre d'hoplites
 * @param nbCavalier l'adresse du nombre de cavalier
 * @param nbChar l'adresse du nombre de chars
 * @param nbCatapulte l'adresse du nombre de catapultes
 * @param pierre l'adresse du nombre de pierre
 * @param bois l'adresse du nombre de bois
 * @param argent l'adresse du nombre d'argent
 * */
void gereListeEvenementTroupe(EvenementTroupe** listeEvenementTroupe, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, float* pierre, float* bois, float* argent);

/**
 * @brief Gere la fin d'un evenement de troupe
 * @param e l'evenement de troupe qui se termine
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * @param nbEpee l'adresse du nombre d'eppe
 * @param nbFrondeur l'adresse du nombre de frondeurs
 * @param nbArcher l'adresse du nombre d'archers
 * @param nbHoplite l'adresse du nombre d'hoplites
 * @param nbCavalier l'adresse du nombre de cavalier
 * @param nbChar l'adresse du nombre de chars
 * @param nbCatapulte l'adresse du nombre de catapultes
 * @param pierre l'adresse du nombre de pierre
 * @param bois l'adresse du nombre de bois
 * @param argent l'adresse du nombre d'argent
 * */
void finEvenementTroupe(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte, EvenementTroupe** listeEvenementTroupe,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, float* pierre, float* bois, float* argent);

/**
 * @brief calcule la capacité de ressources qu'une armée peut porter
 * @param e l'evenement de troupe dont on veut calculer la capacité
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * */
float calculeCapaciteArmee(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);

/**
 * @brief Simule un combat et en détermine l'issue
 * @param e l'evenement de troupe dont on veut déterminer l'issue du combat
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * */
int combat(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);

/**
 * @brief Calcule les unités restantes suite à un combat
 * @param nbEpee l'adresse du nombre d'eppe
 * @param nbFrondeur l'adresse du nombre de frondeurs
 * @param nbArcher l'adresse du nombre d'archers
 * @param nbHoplite l'adresse du nombre d'hoplites
 * @param nbCavalier l'adresse du nombre de cavalier
 * @param nbChar l'adresse du nombre de chars
 * @param nbCatapulte l'adresse du nombre de catapultes
 * @param resultat le résultat du combat
 * @param attaque la valeur totale d'attaque de l'armée survivante
 * */
void calculeUnitesRestantes(int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, int resultat, int attaque);

/**
 * @brief Gère un clic sur la liste des événements de troupes
 * @param listeEvenementTroupe l'adresse de la tete de liste
 * @param x l'abscisse du clic souris
 * @param y l'ordonnée du clic souris
 * @param p la popup courante
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * */
void gereClicListeEvenementTroupe(EvenementTroupe** listeEvenementTroupe, int x, int y, Popups p, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);

/**
 * @brief Affiche un évenement
 * @param e l'événement à afficher
 * @param numero le rang de l'événement dans la liste
 * @param attaqueSortante l'image d'un événement d'attaque sortante
 * @param retourTroupe l'image d'un événement de retour de troupe
 * */
void afficheEvenement(EvenementTroupe* e, int numero, DonneesImageRGB* attaqueSortante, DonneesImageRGB* retourTroupe);

/**
 * @brief Affiche la liste des événements de troupes
 * @param e la tête de liste des evenements de trouope
 * @param attaqueSortante l'image d'un événement d'attaque sortante
 * @param retourTroupe l'image d'un événement de retour de troupe
 * */
void afficheListeEvenementTroupe(EvenementTroupe* e, DonneesImageRGB* attaqueSortante, DonneesImageRGB* retourTroupe);
