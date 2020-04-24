#ifndef COULEUR_H
#define COULEUR_H

 /**
  * -------------------------------------------------
  * -------------------- SUMMARY --------------------
  * -------------------------------------------------
  * 0) INTRODUCTION    - line ...
  * 1) INITIALISATION  - line ...
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
void initCouleurTab(CouleurTab* c);
void initCouleur(Couleur* c, unsigned char r, unsigned char v, unsigned char b);
void changeColor(Couleur c);

#endif
