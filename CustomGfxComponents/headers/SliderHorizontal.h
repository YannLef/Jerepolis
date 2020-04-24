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
  
void initSliderHorizontal(SliderHorizontal* sli, int x, int y, int largeur, int epaisseurLigne, int epaisseurPointeur, Couleur cLigne, Couleur cPointeur, int min, int max, int* var);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheSliderHorizontal(SliderHorizontal sli);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereClicSliderHorizontal(SliderHorizontal* sli, int xSouris, int ySouris);

#endif
