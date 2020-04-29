#ifndef CHECKBOX_H
#define CHECKBOX_H

 /**
  * --------------------------------------------------
  * -------------------- SOMMAIRE --------------------
  * --------------------------------------------------
  * 1) INITIALISATION  - line 38
  * 2) AFFICHAGE       - line 53
  * 3) MISE A JOUR     - line 74
  * 4) EVENEMENTS      - line 100
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

/**
 * Fonction permettant d'initialiser une checkbox
 * @author Yann LEFEVRE
 * */
void initCheckbox(Checkbox* cb, int x, int y, int cote, int epaisseurBordure, Couleur cInterieur, Couleur cBordure, bool etat);

 /**
  * ------------------------------------------------------
  * -------------------- 2) AFFICHAGE --------------------
  * ------------------------------------------------------
  * */
  
 /**
 * Fonction permettant d'afficher une checkbox
 * @author Yann LEFEVRE
 * */
void afficheCheckbox(Checkbox cb);

 /**
  * --------------------------------------------------------
  * -------------------- 3) MISE A JOUR --------------------
  * --------------------------------------------------------
  * */

/**
 * Fonction permettant de définir l'etat d'une checkbox
 * @author Yann LEFEVRE
 * */
void setEtatCheckbox(Checkbox* cb, bool etat);

/**
 * Fonction permettant de changer l'etat d'une checkbox
 * @author Yann LEFEVRE
 * */
void toggleEtatCheckbox(Checkbox* cb);

 /**
  * -------------------------------------------------------
  * -------------------- 4) EVENEMENTS --------------------
  * -------------------------------------------------------
  * */

/**
 * Fonction permettant de gérer le clic sur une checkbox
 * Permet de changer son état (principe même d'une checkbox)
 * @author Yann LEFEVRE
 * */
void gereClicCheckbox(Checkbox* cb, int xSouris, int ySouris);

#endif
