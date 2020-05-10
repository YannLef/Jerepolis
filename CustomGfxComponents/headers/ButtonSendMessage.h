 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  

void initBoutonSendMessage(BoutonSendMessage* b, int x, int y, int largeur, int hauteur, int epaisseurBordure, Couleur cInterieur, Couleur cBordure, Couleur cText, int epaisseurTrait);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  

void afficheBoutonSendMessage(BoutonSendMessage b);

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
void gereSourisBoutonSendMessage(BoutonSendMessage b, InputText* inputAssistant, Message*** messages, int nbMessageMax, int* nbMessage, int xSouris, int ySouris);
