#ifndef BUTTON_CHANGE_PAGE_H
#define BUTTON_CHANGE_PAGE_H

 /**
  * -------------------------------------------------
  * -------------------- SUMMARY --------------------
  * -------------------------------------------------
  * 0) INTRODUCTION    - line ...
  * 1) INITIALISATION  - line ...
  * 2) DISPLAY         - line ...
  * 3) EVENTS          - line ...
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
void initBoutonChangePage(boutonChangePage* b, char* string, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure, couleur cText, int epaisseurTrait, page pageSuivante);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheBoutonChangePage(boutonChangePage b, int xEcran, int yEcran, float coefZoom);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereSourisBoutonChangePage(boutonChangePage b, pages* pActuel, int xSouris, int ySouris);

#endif
