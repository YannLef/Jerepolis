/**
 * @brief Initialise un ennemi
 * @param e l'ennemi à initialiser
 * @param nom le nom du village ennemi
 * @param distance la distance entre la ville du joueur et la ville de l'ennemi
 * */
void initEnnemi(Ennemi* e, char* nom, unsigned long distance);

/**
 * @brief Gère l'armée de l'ennemi : recrute des troupes en adéquation avec la situation du joueur pour que ça reste équilbré
 * @param e l'ennemi dont on veut gérer l'armée
 * @param epee l'unité epee
 * @param frondeur l'unité frondeur
 * @param archer l'unité archer
 * @param hoplite l'unité hoplite
 * @param cavalier l'unité cavalier
 * @param charr l'unité char
 * @param catapulte l'unité catapulte
 * @param ferme le batiment ferme
 * */
void gereArmeeEnnemi(Ennemi* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte, Batiment ferme);

/**
 * @brief Calcule de manière aléatoire s'il faut générer une troupe ou non, basé sur les probabilité qu'on lui donne
 * @param chanceSurMille la probabilité sur 1000 de générer une troupe
 * */
int randTroupe(float chanceSurMille);

/**
 * @brief Affiche au terminal l'armée ennemie
 * */
void printArmeeEnnemi(Ennemi e);
