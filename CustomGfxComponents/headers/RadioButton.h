#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

 /**
  * -------------------------------------------------
  * -------------------- SUMMARY --------------------
  * -------------------------------------------------
  * 0) INTRODUCTION    - line ...
  * 1) INITIALISATION  - line ...
  * 2) DISPLAY         - line ...
  * 3) UPDATE          - line ...
  * 4) EVENTS          - line ...
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

void initRadioButton(radiobutton* rb, char* type, int x, int y, int cote, int epaisseurBordure, couleur cInterieur, couleur cBordure, int nb, int on);

/**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
  void afficheRadioButton(radiobutton rb);
  
 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */

void updateRadioButton(radiobutton* rb);

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

void gereClicRadioButton(radiobutton* rb, int xSouris, int ySouris);

#endif
