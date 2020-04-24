#ifndef CHECKBOX_H
#define CHECKBOX_H

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

void initCheckbox(Checkbox* cb, int x, int y, int cote, int epaisseurBordure, Couleur cInterieur, Couleur cBordure, bool etat);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheCheckbox(Checkbox cb);

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */

void setEtatCheckbox(Checkbox* cb, bool etat);
void toggleEtatCheckbox(Checkbox* cb);

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

void gereClicCheckbox(Checkbox* cb, int xSouris, int ySouris);

#endif
