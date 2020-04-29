#ifndef NAVBAR_H
#define NAVBAR_H

 /**
  * --------------------------------------------------
  * -------------------- SOMMAIRE --------------------
  * --------------------------------------------------
  * 1) INITIALISATION  - line 42
  * 2) MISE A JOUR     - line 58
  * 3) EVENEMENTS      - line 102
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
 /**
 * Fonction permettant d'initialiser la Navbar
 * -> c'est un tableau de 9 entiers correspondants aux 9 boutons de la Navbar
 * @author Yann LEFEVRE
 * */
void initNavbar(int nav[10]);

 /**
  * --------------------------------------------------------
  * -------------------- 2) MISE A JOUR --------------------
  * --------------------------------------------------------
  * */
  
 /**
 * Fonction transformant les clics sur la Navbar en actions concrètes
 * @author Yann LEFEVRE
 * */
void actualiseNavbar(int nbBouton, int nav[10]);
  
 /**
  * -------------------------------------------------------
  * -------------------- 3) EVENEMENTS --------------------
  * -------------------------------------------------------
  * */
  
 /**
 * Fonction permettant de gérer les clics sur la Navbar
 * Appelle une fonction qui gère les clics en fonction du bouton cliqué dans la navbar
 * @author Yann LEFEVRE
 * */
void gereSourisNavbar(int xSouris, int ySouris, int nav[10]);

#endif

