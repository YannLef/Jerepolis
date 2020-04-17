#ifndef RECTANGLE_H
#define RECTANGLE_H

 /**
  * -------------------------------------------------
  * -------------------- SUMMARY --------------------
  * -------------------------------------------------
  * 0) INTRODUCTION    - line ...
  * 1) INITIALISATION  - line ...
  * 2) DISPLAY         - line ...
  * 3) TESTS           - line ...
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
void initRectangle(rec* rect, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure);
  
  
 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheRectangle(rec rect, bool mobile, int xEcran, int yEcran, float coefZoom);
  
 /**
  * --------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * --------------------------------------------------
  * */

bool isOnRectangle(int x, int y, rec rect);
bool isOnRectangleMobile(int x, int y, rec rect, int xEcran, int yEcran, float coefZoom);

#endif
