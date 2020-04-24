#ifndef DROPDOWN_MENU_RIGHT_H
#define DROPDOWN_MENU_RIGHT_H

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
  
void initMenuDeroulantVersDroite(MenuDeroulantVersDroite* menu, int yBas, int yHaut, int xGauche, int xDroite, bool etat);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheMenuDeroulantVersDroite(MenuDeroulantVersDroite* menu, int xEcran, int yEcran, float coefZoom);
void afficheDetailMenu(int nav[10], Pages p, MenuDeroulantVersDroite* menuDeroulant);

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */
  
void agrandiMenuDeroulantVersDroite(MenuDeroulantVersDroite* menu);
void reduiMenuDeroulantVersDroite(MenuDeroulantVersDroite* menu);

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereMenuDeroulantVersDroite(int nav[10], MenuDeroulantVersDroite* menuDeroulant);

#endif
