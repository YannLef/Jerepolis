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
  
void recupereInfosFichiersDansDossier(char* cheminDossier, fichier** fichiers, int* nombreFichiers);

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
void afficheExplorateurDeFichiers(DonneesImageRGB* enteteFondExplorateur, DonneesImageRGB* fondExplorateur, fichier* listeFichiers, boutonChangePage exitOpenTree, boutonChangeFichiers nextFichiers, boutonChangeFichiers previousFichiers, int xEcran, int yEcran, float coefZoom, int debutAffichageExplorateur, int nombreFichiers);

 /**
  * ----------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ----------------------------------------------------
  * */
  
void gereSourisSelectionneFichier(int xSouris, int ySouris, int* debutAffichageExplorateur, int nombreFichiers, pages* pActuel, fichier* listeFichiers, fichier* fichierCharge, char** fileNameI,
char** fileNameM);

#endif
