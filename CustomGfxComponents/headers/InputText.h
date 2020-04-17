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
  
void initInputText(inputText* input, int etat, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure);
void resetInputText(inputText* input);
void setString(inputText* input, char* string);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheInputTexte(inputText input, int xEcran, int yEcran, float coefZoom);

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */
  
void toggleEtatInput(inputText* input);
void setEtatInput(inputText* input, bool etat);
void completeInputText(inputText* input, char c);
void updateInputText(inputText* input);

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereSourisInputText(inputText* input, int xSouris, int ySouris);

#endif
