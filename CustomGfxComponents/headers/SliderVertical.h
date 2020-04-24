#ifndef SLIDER_VERTICAL_H
#define SLIDER_VERTICAL_H

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
  
void initSliderVertical(SliderVertical* sli, int x, int y, int hauteur, int epaisseurLigne, int epaisseurPointeur, Couleur cLigne, Couleur cPointeur, int min, int max, int* var);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheSliderVertical(SliderVertical sli);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereClicSliderVertical(SliderVertical* sli, int xSouris, int ySouris);

#endif
