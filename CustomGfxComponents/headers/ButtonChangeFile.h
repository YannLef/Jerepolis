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
  
void initBoutonChangeFichiers(boutonChangeFichiers* b, char* string, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure, couleur cText, int epaisseurTrait, int effet);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheBoutonChangeFichiers(boutonChangeFichiers b, int xEcran, int yEcran, float coefZoom);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereSourisBoutonChangeFichiers(boutonChangeFichiers b, int* debutAffichageExplorateur, int nombreFichiers, int xSouris, int ySouris);

#endif
