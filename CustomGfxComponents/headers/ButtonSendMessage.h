 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  

void initBoutonSendMessage(boutonSendMessage* b, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure, couleur cText, int epaisseurTrait);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  

void afficheBoutonSendMessage(boutonSendMessage b, int xEcran, int yEcran, float coefZoom);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereSourisBoutonSendMessage(boutonSendMessage b, inputText* inputAssistant, message*** messages, int nbMessageMax, int* nbMessage, int xSouris, int ySouris);
