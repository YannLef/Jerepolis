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

void initCheckbox(checkbox* cb, int x, int y, int cote, int epaisseurBordure, couleur cInterieur, couleur cBordure, bool etat);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheCheckbox(checkbox cb);

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */

void setEtatCheckbox(checkbox* cb, bool etat);
void toggleEtatCheckbox(checkbox* cb);

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

void gereClicCheckbox(checkbox* cb, int xSouris, int ySouris);

#endif
