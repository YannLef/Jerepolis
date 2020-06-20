/**
 * @brief Génère le chemin du fichier .csv correspondant à un batiment
 * @return le chemin du fichier .csv correspondant au batiment
 * @param nom le nom du batiment dont on veut récupérer le chemin du fichier .csv
 * */
char* getCheminFichierBatiment(char* nom);

/**
 * @brief Initialise le modèle d'un batiment
 * @param m l'adresse du modèle à initialiser
 * @param nom le nom du batiment correspondant au modèle à initialiser
 * @param type le type de batiment : production ou normal
 * */
void initModeleBatiment(ModeleBatiment** m, char* nom, typeBatiment type);

/**
 * @brief Initialise le niveau d'un batiment
 * @param lvl l'adresse du niveau à initialiser
 * @param nom le nom du batiment
 * @param type le type du batiment : production ou normal
 * @param niveau le niveau correspondant
 * @param populationMax la population max qui pourra travailler dans ce batiment
 * @param prixAmeliorationBois le bois nécessaire pour accéder à ce niveau
 * @param prixAmeliorationPierre la pierre nécessaire pour accéder à ce niveau
 * @param prixAmeliorationArgent l'argent nécessaire pour accéder à ce niveau
 * @param tempsAmelioration le temps qu'il faudra attendre pour atteidnre ce niveau (en ms)
 * */
void initNiveauBatiment(ModeleBatiment** lvl, char* nom, typeBatiment type, int niveau, int populationMax, int prixAmeliorationBois, int prixAmeliorationPierre, int prixAmeliorationArgent, int tempsAmelioration, char image[10], float production);

/**
 * @brief Ajoute un niveau de batiment à la liste chainée du modèle du batiment
 * @param m l'adresse du modèle de batiment
 * @param lvl le niveau du batiment à rajouter au modèle
 * */
void ajouteNiveauBatiment(ModeleBatiment** m, ModeleBatiment* lvl);

/**
 * @brief Affiche dans la console un niveau de batiment
 * @param lvl le niveau de batiment à afficher
 * */
void printNiveauBatiment(ModeleBatiment* lvl);

/**
 * @brief Affiche dans la console un modèle de batiment
 * @param m le modele de batiment à afficher
 * */
void printModeleBatiment(ModeleBatiment* m);

/**
 * @brief Récupère un maillon particulier du modèle en fonction du niveau demandé
 * @return le niveau de batiment demandé
 * @param m le modèle du batiment
 * @param niveau le niveau recherché dans le modèle
 * */
ModeleBatiment* getModeleNiveauBatiment(ModeleBatiment* m, int niveau);
