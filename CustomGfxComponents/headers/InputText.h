#ifndef INPUT_TEXT_H
#define INPUT_TEXT_H

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
  
void initInputText(InputText* input, int etat, int x, int y, int largeur, int hauteur, int epaisseurBordure, Couleur cInterieur, Couleur cBordure);
void resetInputText(InputText* input);
void setString(InputText* input, char* string);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheInputTexte(InputText input, int xEcran, int yEcran, float coefZoom);

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */
  
void toggleEtatInput(InputText* input);
void setEtatInput(InputText* input, bool etat);
void completeInputText(InputText* input, char c);
void updateInputText(InputText* input);

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereSourisInputText(InputText* input, int xSouris, int ySouris);

#endif
