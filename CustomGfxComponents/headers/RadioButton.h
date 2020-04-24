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

void initRadioButton(Radiobutton* rb, char* type, int x, int y, int cote, int epaisseurBordure, Couleur cInterieur, Couleur cBordure, int nb, int on);

/**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
  void afficheRadioButton(Radiobutton rb);
  
 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */

void updateRadioButton(Radiobutton* rb);

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

void gereClicRadioButton(Radiobutton* rb, int xSouris, int ySouris);

#endif
