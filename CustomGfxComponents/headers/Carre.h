#ifndef CARRE_H
#define CARRE_H

 /**
  * --------------------------------------------------
  * -------------------- SOMMAIRE --------------------
  * --------------------------------------------------
  * 1) INITIALISATION  - ligne 37
  * 2) AFFICHAGE       - ligne 56
  * 3) TESTS           - ligne 97
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Initialise un carre , nécessite de nombreux paramètres pour être le plus complet possible
 * @param square le pointeur vers le carré à initialiser
 * @param x l'abscisse du centre du carré
 * @param y l'odronnée du centre du carré
 * @param cote la taille du côté du carré
 * @param epaisseurBordure l'épaisseur de trait du carré
 * @param cInterieur la couleure intérieure du carré
 * @param cBordure la couleur des contours du carré
 * @author Yann LEFEVRE
 * */
void initCarre(Carre* square, int x, int y, int cote, int epaisseurBordure, Couleur cInterieur, Couleur cBordure);
  
  
 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * Affiche un carre à partir de ses valeurs
 * @param square le carré à afficher
 * @author Yann LEFEVRE
 * */
void afficheCarre(Carre square);
  
 /**
  * --------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * --------------------------------------------------
  * */

/**
 * Fonction vérifiant si un point de coordonnée (x,y) appartient à un carré donné
 * @param x l'abscisse du point à tester
 * @param y l'ordonnée du point à tester
 * @param carre le carré par rapport auquel on veut tester
 * @author Yann LEFEVRE
 * */
bool isOnCarre(int x, int y, Carre square);

#endif
