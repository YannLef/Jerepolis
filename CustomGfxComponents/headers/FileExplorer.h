#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

 /**
  * -------------------------------------------------
  * -------------------- SUMMARY --------------------
  * -------------------------------------------------
  * 0) INTRODUCTION    - line ...
  * 1) INITIALISATION  - line ...
  * 2) DISPLAY         - line ...
  * 3) EVENTS          - line ...
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
void recupereInfosFichiersDansDossier(char* cheminDossier, Fichier** fichiers, int* nombreFichiers);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheExplorateurDeFichiers(DonneesImageRGB* enteteFondExplorateur, DonneesImageRGB* fondExplorateur, Fichier* listeFichiers, BoutonChangePage exitOpenTree, BoutonChangeFichiers nextFichiers, BoutonChangeFichiers previousFichiers, int xEcran, int yEcran, float coefZoom, int debutAffichageExplorateur, int nombreFichiers);

 /**
  * ----------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ----------------------------------------------------
  * */
  
void gereSourisSelectionneFichier(int xSouris, int ySouris, int* debutAffichageExplorateur, int nombreFichiers, Pages* pActuel, Fichier* listeFichiers, Fichier* fichierCharge, char** fileNameI,
char** fileNameM);

#endif
