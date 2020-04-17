#ifndef SLIDER_HORIZONTAL_H
#define SLIDER_HORIZONTAL_H


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
  
void initSliderHorizontal(sliderHorizontal* sli, int x, int y, int largeur, int epaisseurLigne, int epaisseurPointeur, couleur cLigne, couleur cPointeur, int min, int max, int* var);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheSliderHorizontal(sliderHorizontal sli);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereClicSliderHorizontal(sliderHorizontal* sli, int xSouris, int ySouris);

#endif
