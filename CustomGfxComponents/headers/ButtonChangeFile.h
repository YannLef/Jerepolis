#ifndef BUTTON_CHANGE_FILE_H
#define BUTTON_CHANGE_FILE_H

 /**
  * -------------------------------------------------
  * -------------------- SUMMARY --------------------
  * -------------------------------------------------
  * 0) INTRODUCTION    - line ...
  * 1) INITIALISATION  - line ...
  * 2) DISPLAY         - line ...
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
void initBoutonChangeFichiers(BoutonChangeFichiers* b, char* string, int x, int y, int largeur, int hauteur, int epaisseurBordure, Couleur cInterieur, Couleur cBordure, Couleur cText, int epaisseurTrait, int effet);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheBoutonChangeFichiers(BoutonChangeFichiers b);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereSourisBoutonChangeFichiers(BoutonChangeFichiers b, int* debutAffichageExplorateur, int nombreFichiers, int xSouris, int ySouris);

#endif
