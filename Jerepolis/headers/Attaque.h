/**
 * @brief Gère un clic sur le bouton attaquer principal
 * @param x l'abscsisse du clic souris
 * @param y l'abscsisse du clic souris
 * @param p l'adresse de la popup courante
 * */
void gereClicAttaquerMain(int x, int y, Popups* p);

/**
 * @brief Affiche la popup d'attaque
 * @param p la popup courante
 * @param attaquer l'image du bouton attaquer
 * @param nbAttEpee le nombre d'epee selectionné pour l'attaque
 * @param nbAttFrondeur le nombre de frondeur selectionné pour l'attaque
 * @param nbAttArcher le nombre d'archer selectionné pour l'attaque
 * @param nbAttHoplite le nombre d'hoplite selectionné pour l'attaque
 * @param nbAttCavalier le nombre de cavalier selectionné pour l'attaque
 * @param nbAttChar le nombre de char selectionné pour l'attaque
 * @param nbAttCatapulte le nombre de catapulte selectionné pour l'attaque
 * @param e l'ennemi à attaquer
 * */
void affichePopupAttaque(Popups p, DonneesImageRGB* attaquer, int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Ennemi e);

/**
 * @brief Initialise les troupes sélectionnées pour l'attaque
 * @param nbAttEpee l'adresse du nombre d'epee selectionné pour l'attaque
 * @param nbAttFrondeur l'adresse du nombre de frondeur selectionné pour l'attaque
 * @param nbAttArcher l'adresse du nombre d'archer selectionné pour l'attaque
 * @param nbAttHoplite l'adresse du nombre d'hoplite selectionné pour l'attaque
 * @param nbAttCavalier l'adresse du nombre de cavalier selectionné pour l'attaque
 * @param nbAttChar l'adresse du nombre de char selectionné pour l'attaque
 * @param nbAttCatapulte l'adresse du nombre de catapulte selectionné pour l'attaque
 * */
void initAttTroupes(int* nbAttEpee, int* nbAttFrondeur, int* nbAttArcher, int* nbAttHoplite, int* nbAttCavalier, int* nbAttChar, int* nbAttCatapulte);

/**
 * @brief Gère le clic sur la popup d'attaque
 * @param x l'abscsisse du clic souris
 * @param y l'abscsisse du clic souris
 * @param p l'adresse de la popup courante
 * @param nbAttEpee l'adresse du nombre d'epee selectionné pour l'attaque
 * @param nbAttFrondeur l'adresse du nombre de frondeur selectionné pour l'attaque
 * @param nbAttArcher l'adresse du nombre d'archer selectionné pour l'attaque
 * @param nbAttHoplite l'adresse du nombre d'hoplite selectionné pour l'attaque
 * @param nbAttCavalier l'adresse du nombre de cavalier selectionné pour l'attaque
 * @param nbAttChar l'adresse du nombre de char selectionné pour l'attaque
 * @param nbAttCatapulte l'adresse du nombre de catapulte selectionné pour l'attaque
 * @param nbEpee l'adresse du nombre d'épée
 * @param nbFrondeur l'adresse du nombre de frondeurs
 * @param nbArcher l'adresse du nombre d'archers
 * @param nbHoplite l'adresse du nombre d'hoplites
 * @param nbCavalier l'adresse du nombre de cavaliers
 * @param nbChar l'adresse du nombre de chars
 * @param nbCatapulte l'adresse du nombre de catapultes
 * @param listeEvenementTroupe l'adresse de la tete de liste
 * @param ennemi l'ennemi à attaquer
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * */
void clicPopupAttaque(int x, int y, Popups* p, int* nbAttEpee, int* nbAttFrondeur, int* nbAttArcher, int* nbAttHoplite, int* nbAttCavalier, int* nbAttChar, int* nbAttCatapulte, int* nbEpee,
int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe, Ennemi* ennemi, Unite epee, Unite frondeur, Unite archer,
Unite hoplite, Unite cavalier, Unite charr, Unite catapulte);

/**
 * @brief Calcule la vitesse d'une armée en fonction des troupes qui en font partie
 * @param nbAttEpee le nombre d'epee selectionné pour l'attaque
 * @param nbAttFrondeur le nombre de frondeur selectionné pour l'attaque
 * @param nbAttArcher le nombre d'archer selectionné pour l'attaque
 * @param nbAttHoplite le nombre d'hoplite selectionné pour l'attaque
 * @param nbAttCavalier le nombre de cavalier selectionné pour l'attaque
 * @param nbAttChar le nombre de char selectionné pour l'attaque
 * @param nbAttCatapulte le nombre de catapulte selectionné pour l'attaque
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * @return la vitesse de l'armée
 * */
int calculeVitesseArmee(int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Unite epee, Unite frondeur, Unite archer, Unite hoplite,
Unite cavalier, Unite charr, Unite catapulte);

/**
 * @brief Calcule le temps de trajet d'une attaque
 * @param nbAttEpee le nombre d'epee selectionné pour l'attaque
 * @param nbAttFrondeur le nombre de frondeur selectionné pour l'attaque
 * @param nbAttArcher le nombre d'archer selectionné pour l'attaque
 * @param nbAttHoplite le nombre d'hoplite selectionné pour l'attaque
 * @param nbAttCavalier le nombre de cavalier selectionné pour l'attaque
 * @param nbAttChar le nombre de char selectionné pour l'attaque
 * @param nbAttCatapulte le nombre de catapulte selectionné pour l'attaque
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * @param ennemi l'ennemi à attaquer
 * @return le temps de trajet d'une attaque
 * */
int calculeTempsDeTrajet(int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Unite epee, Unite frondeur, Unite archer, Unite hoplite,
Unite cavalier, Unite charr, Unite catapulte, Ennemi ennemi);
