#ifdef _WIN32
	#include <windows.h>
#endif

#ifdef __APPLE__
//	#include <OpenGL/gl.h>
//	#include <OpenGL/CGLMacro.h>
	#include <GLUT/glut.h>		// Header File For The GLut Library
#else
	#include <GL/glut.h>			// Header File For The GLut Library
	#ifdef _WIN32
		#include <GL/glext.h>
	#else
		#include <X11/Xlib.h>
		#include <GL/glx.h>
	#endif
#endif

/**
 * Includes Classiques
 * */
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

/**
 * Includes GfxLib
 * */
#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

/**
 * Includes Logger
 * */
#include "../../Logger/headers/Logger.h"

/**
 * Includes CustomGfxComponents
 * */
#include "../headers/structures.h"
#include "../headers/Page.h"

/**
 * Includes correspondant
 * */
#include "../headers/Keyboard.h"

extern keyboard keys; // Synchronise le clavier avec les autres fichiers

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Initialise le clavier :
 * Chaque touche nécessaire dans le programme correspond à un booléen.
 * Le booléen est égal à 1 si la touche est relachée
 * Le booléen est égal à 0 si la touche est appuyée
 * Le clavier doit être transmit dans les différents fichiers qui en ont besoin en utilisant le mot clé "extern"
 * Initialise les callbacks utilisés par glut et permettant de gérer le clavier.
 * @author Yann LEFEVRE
 * */
void initKeyboard(void){
	debug("<initKeyboard> begin");
	
	glutIgnoreKeyRepeat(1); // empêche de générer différents évènements si on reste appuyé sur une touche
	glutKeyboardFunc(keyDown); // callback pour quand une touche normale est appuyée
	glutKeyboardUpFunc(keyUp); // callback pour quand une touche normale est relachée
	glutSpecialFunc(specialKeyDown); // callback pour quand une touche spéciale est appuyée
	glutSpecialUpFunc(specialKeyUp); // callback pour quand une touche spéciale est relachée
	
	// Touches normales
	keys.key_a = 1; // Touche a minuscule
	keys.key_A = 1; // Touche A majuscule
	keys.key_b = 1; // Touche b minuscule
	keys.key_B = 1; // Touche B majuscule
	keys.key_c = 1; // Touche c minuscule
	keys.key_C = 1; // Touche C majuscule
	keys.key_d = 1; // Touche d minuscule
	keys.key_D = 1; // Touche D majuscule
	keys.key_e = 1; // Touche e minuscule
	keys.key_E = 1; // Touche E majuscule
	keys.key_f = 1; // Touche f minuscule
	keys.key_F = 1; // Touche F majuscule
	keys.key_g = 1; // Touche g minuscule
	keys.key_G = 1; // Touche G majuscule
	keys.key_h = 1; // Touche h minuscule
	keys.key_H = 1; // Touche H majuscule
	keys.key_i = 1; // Touche i minuscule
	keys.key_I = 1; // Touche I majuscule
	keys.key_j = 1; // Touche j minuscule
	keys.key_J = 1; // Touche J majuscule
	keys.key_k = 1; // Touche k minuscule
	keys.key_K = 1; // Touche K majuscule
	keys.key_l = 1; // Touche l minuscule
	keys.key_L = 1; // Touche L majuscule
	keys.key_m = 1; // Touche m minuscule
	keys.key_M = 1; // Touche M majuscule
	keys.key_n = 1; // Touche n minuscule
	keys.key_N = 1; // Touche N majuscule
	keys.key_o = 1; // Touche o minuscule
	keys.key_O = 1; // Touche O majuscule
	keys.key_p = 1; // Touche p minuscule
	keys.key_P = 1; // Touche P majuscule
	keys.key_q = 1; // Touche q minuscule
	keys.key_Q = 1; // Touche Q majuscule
	keys.key_r = 1; // Touche r minuscule
	keys.key_R = 1; // Touche R majuscule
	keys.key_s = 1; // Touche s minuscule
	keys.key_S = 1; // Touche S majuscule
	keys.key_t = 1; // Touche t minuscule
	keys.key_T = 1; // Touche T majuscule
	keys.key_u = 1; // Touche u minuscule
	keys.key_U = 1; // Touche U majuscule
	keys.key_v = 1; // Touche v minuscule
	keys.key_V = 1; // Touche V majuscule
	keys.key_w = 1; // Touche w minuscule
	keys.key_W = 1; // Touche W majuscule
	keys.key_x = 1; // Touche x minuscule
	keys.key_X = 1; // Touche X majuscule
	keys.key_y = 1; // Touche y minuscule
	keys.key_Y = 1; // Touche Y majuscule
	keys.key_z = 1; // Touche z minuscule
	keys.key_Z = 1; // Touche Z majuscule
	
	keys.key_0 = 1; // Touche 0
	keys.key_1 = 1; // Touche 1
	keys.key_2 = 1; // Touche 2
	keys.key_3 = 1; // Touche 3
	keys.key_4 = 1; // Touche 4
	keys.key_5 = 1; // Touche 5
	keys.key_6 = 1; // Touche 6
	keys.key_7 = 1; // Touche 7
	keys.key_8 = 1; // Touche 8
	keys.key_9 = 1; // Touche 9
	
	keys.key_spacebar = 1; // Touche espace
	keys.key_esc = 1; // Touche echape
	keys.key_del = 1; // Touche supprimer
	keys.key_backspace = 1; // Touche backspace
	
	//Touches spéciales
	keys.key_up = 1; // Touche flèche du haut
	keys.key_down = 1; // Touche flèche du bas
	keys.key_left = 1; // Touche flèche de gauche
	keys.key_right = 1; // Touche flèche de droite
	keys.key_page_up = 1; // Touche haut de page (flèche peu utilisée)
	keys.key_page_down = 1; // Touche bas de page (flèche peu utilisée)
	
	
	
	keys.key_slash = 1;
	
	debug("<initKeyboard> end");
}

 /**
  * ---------------------------------------------------
  * -------------------- 2) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Vérifie quel touche du clavier [NORMALE] a été appuyée pour engendré son appel
 * Passe le booléen correspondant à la touche appuyée à 0 (permet d'informer le reste du programme que cette touche est enfoncée)
 * @author Yann LEFEVRE
 * */
void keyDown(unsigned  char key, int x, int y){
	debug("<keyDown> begin");
	
	if(key=='a'){ keys.key_a = 0;} // a est appuyé
	if(key=='A'){ keys.key_A = 0;} // A est appuyé
	if(key=='b'){ keys.key_b = 0; } // b est appuyé
	if(key=='B'){ keys.key_B = 0; } // B est appuyé
	if(key=='c'){ keys.key_c = 0; } // c est appuyé
	if(key=='C'){ keys.key_C = 0; } // C est appuyé
	if(key=='d'){ keys.key_d = 0; } // d est appuyé
	if(key=='D'){ keys.key_D = 0; } // D est appuyé
	if(key=='e'){ keys.key_e = 0; } // e est appuyé
	if(key=='E'){ keys.key_E = 0; } // E est appuyé
	if(key=='f'){ keys.key_f = 0; } // f est appuyé
	if(key=='F'){ keys.key_F = 0; } // F est appuyé
	if(key=='g'){ keys.key_g = 0; } // g est appuyé
	if(key=='G'){ keys.key_G = 0; } // G est appuyé
	if(key=='h'){ keys.key_h = 0; } // h est appuyé
	if(key=='H'){ keys.key_H = 0; } // H est appuyé
	if(key=='i'){ keys.key_i = 0; } // i est appuyé
	if(key=='I'){ keys.key_I = 0; } // I est appuyé
	if(key=='j'){ keys.key_j = 0; } // j est appuyé
	if(key=='J'){ keys.key_J = 0; } // J est appuyé
	if(key=='k'){ keys.key_k = 0; } // k est appuyé
	if(key=='K'){ keys.key_K = 0; } // K est appuyé
	if(key=='l'){ keys.key_l = 0; } // l est appuyé
	if(key=='L'){ keys.key_L = 0; } // L est appuyé
	if(key=='m'){ keys.key_m = 0; } // m est appuyé
	if(key=='M'){ keys.key_M = 0; } // M est appuyé
	if(key=='n'){ keys.key_n = 0; } // n est appuyé
	if(key=='N'){ keys.key_N = 0; } // N est appuyé
	if(key=='o'){ keys.key_o = 0; } // o est appuyé
	if(key=='O'){ keys.key_O = 0; } // O est appuyé
	if(key=='p'){ keys.key_p = 0; } // p est appuyé
	if(key=='P'){ keys.key_P = 0; } // P est appuyé
	if(key=='q'){ keys.key_q = 0; } // q est appuyé
	if(key=='Q'){ keys.key_Q = 0; } // Q est appuyé
	if(key=='r'){ keys.key_r = 0; } // r est appuyé
	if(key=='R'){ keys.key_R = 0; } // R est appuyé
	if(key=='s'){ keys.key_s = 0; } // s est appuyé
	if(key=='S'){ keys.key_S = 0; } // S est appuyé
	if(key=='t'){ keys.key_t = 0; } // t est appuyé
	if(key=='T'){ keys.key_T = 0; } // T est appuyé
	if(key=='u'){ keys.key_u = 0; } // u est appuyé
	if(key=='U'){ keys.key_U = 0; } // U est appuyé
	if(key=='v'){ keys.key_v = 0; } // v est appuyé
	if(key=='V'){ keys.key_V = 0; } // V est appuyé
	if(key=='w'){ keys.key_w = 0; } // w est appuyé
	if(key=='W'){ keys.key_W = 0; } // W est appuyé
	if(key=='x'){ keys.key_x = 0; } // x est appuyé
	if(key=='X'){ keys.key_X = 0; } // X est appuyé
	if(key=='y'){ keys.key_y = 0; } // y est appuyé
	if(key=='Y'){ keys.key_Y = 0; } // Y est appuyé
	if(key=='z'){ keys.key_z = 0; } // z est appuyé
	if(key=='Z'){ keys.key_Z = 0; } // Z est appuyé
	
	if(key=='0'){ keys.key_0 = 0; } // 0 est appuyé
	if(key=='1'){ keys.key_1 = 0; } // 1 est appuyé
	if(key=='2'){ keys.key_2 = 0; } // 2 est appuyé
	if(key=='3'){ keys.key_3 = 0; } // 3 est appuyé
	if(key=='4'){ keys.key_4 = 0; } // 4 est appuyé
	if(key=='5'){ keys.key_5 = 0; } // 5 est appuyé
	if(key=='6'){ keys.key_6 = 0; } // 6 est appuyé
	if(key=='7'){ keys.key_7 = 0; } // 7 est appuyé
	if(key=='8'){ keys.key_8 = 0; } // 8 est appuyé
	if(key=='9'){ keys.key_9 = 0; } // 9 est appuyé
	
	if(key==32){ keys.key_spacebar = 0; } // espace est appuyé
	if(key==27){ keys.key_esc = 0; } // eschape est appuyé
	if(key==127){ keys.key_del = 0; } // supprimer est appuyé
	if(key==8){ keys.key_backspace = 0; } // backspace est appuyé
	
	if(key=='/'){ keys.key_slash = 0; } // slash est appuyé
	
	debug("<keyDown> end");
}

/**
 * Vérifie quel touche du clavier [NORMALE] a été relachée pour engendré son appel
 * Passe le booléen correspondant à la touche appuyée à 1 (permet d'informer le reste du programme que cette touche est relachée)
 * @author Yann LEFEVRE
 * */
void keyUp(unsigned char key, int x, int y){
	debug("<keyUp> begin");
	
	if(key=='a'){ keys.key_a = 1;} // a est relaché
	if(key=='A'){ keys.key_A = 1;} // A est relaché
	if(key=='b'){ keys.key_b = 1; } // b est relaché
	if(key=='B'){ keys.key_B = 1; } // B est relaché
	if(key=='c'){ keys.key_c = 1; } // c est relaché
	if(key=='C'){ keys.key_C = 1; } // C est relaché
	if(key=='d'){ keys.key_d = 1; } // d est relaché
	if(key=='D'){ keys.key_D = 1; } // D est relaché
	if(key=='e'){ keys.key_e = 1; } // e est relaché
	if(key=='E'){ keys.key_E = 1; } // E est relaché
	if(key=='f'){ keys.key_f = 1; } // f est relaché
	if(key=='F'){ keys.key_F = 1; } // F est relaché
	if(key=='g'){ keys.key_g = 1; } // g est relaché
	if(key=='G'){ keys.key_G = 1; } // G est relaché
	if(key=='h'){ keys.key_h = 1; } // h est relaché
	if(key=='H'){ keys.key_H = 1; } // H est relaché
	if(key=='i'){ keys.key_i = 1; } // i est relaché
	if(key=='I'){ keys.key_I = 1; } // I est relaché
	if(key=='j'){ keys.key_j = 1; } // j est relaché
	if(key=='J'){ keys.key_J = 1; } // J est relaché
	if(key=='k'){ keys.key_k = 1; } // k est relaché
	if(key=='K'){ keys.key_K = 1; } // K est relaché
	if(key=='l'){ keys.key_l = 1; } // l est relaché
	if(key=='L'){ keys.key_L = 1; } // L est relaché
	if(key=='m'){ keys.key_m = 1; } // m est relaché
	if(key=='M'){ keys.key_M = 1; } // M est relaché
	if(key=='n'){ keys.key_n = 1; } // n est relaché
	if(key=='N'){ keys.key_N = 1; } // N est relaché
	if(key=='o'){ keys.key_o = 1; } // o est relaché
	if(key=='O'){ keys.key_O = 1; } // O est relaché
	if(key=='p'){ keys.key_p = 1; } // p est relaché
	if(key=='P'){ keys.key_P = 1; } // P est relaché
	if(key=='q'){ keys.key_q = 1; } // q est relaché
	if(key=='Q'){ keys.key_Q = 1; } // Q est relaché
	if(key=='r'){ keys.key_r = 1; } // r est relaché
	if(key=='R'){ keys.key_R = 1; } // R est relaché
	if(key=='s'){ keys.key_s = 1; } // s est relaché
	if(key=='S'){ keys.key_S = 1; } // S est relaché
	if(key=='t'){ keys.key_t = 1; } // t est relaché
	if(key=='T'){ keys.key_T = 1; } // T est relaché
	if(key=='u'){ keys.key_u = 1; } // u est relaché
	if(key=='U'){ keys.key_U = 1; } // U est relaché
	if(key=='v'){ keys.key_v = 1; } // v est relaché
	if(key=='V'){ keys.key_V = 1; } // V est relaché
	if(key=='w'){ keys.key_w = 1; } // w est relaché
	if(key=='W'){ keys.key_W = 1; } // W est relaché
	if(key=='x'){ keys.key_x = 1; } // x est relaché
	if(key=='X'){ keys.key_X = 1; } // X est relaché
	if(key=='y'){ keys.key_y = 1; } // y est relaché
	if(key=='Y'){ keys.key_Y = 1; } // Y est relaché
	if(key=='z'){ keys.key_z = 1; } // z est relaché
	if(key=='Z'){ keys.key_Z = 1; } // Z est relaché
	
	if(key=='0'){ keys.key_0 = 1; } // 0 est relaché
	if(key=='1'){ keys.key_1 = 1; } // 1 est relaché
	if(key=='2'){ keys.key_2 = 1; } // 2 est relaché
	if(key=='3'){ keys.key_3 = 1; } // 3 est relaché
	if(key=='4'){ keys.key_4 = 1; } // 4 est relaché
	if(key=='5'){ keys.key_5 = 1; } // 5 est relaché
	if(key=='6'){ keys.key_6 = 1; } // 6 est relaché
	if(key=='7'){ keys.key_7 = 1; } // 7 est relaché
	if(key=='8'){ keys.key_8 = 1; } // 8 est relaché
	if(key=='9'){ keys.key_9 = 1; } // 9 est relaché
	
	if(key==32){ keys.key_spacebar = 1; } // espace est relaché
	if(key==27){ keys.key_esc = 1; } // echape est relaché
	if(key==127){ keys.key_del = 1; } // supprimer est relaché
	if(key==8){ keys.key_backspace = 1; } // backsapce est relaché
	
	if(key=='/'){ keys.key_slash = 1; } // slash est relaché
	
	debug("<keyUp> end");
}

/**
 * Vérifie quel touche du clavier [SPECIALE] a été appuyée pour engendré son appel
 * Passe le booléen correspondant à la touche appuyée à 0 (permet d'informer le reste du programme que cette touche est enfoncée)
 * @author Yann LEFEVRE
 * */
void specialKeyDown(int key, int x, int y){
	debug("<specialKeyDown> begin");
	
	if(key==GLUT_KEY_UP){ keys.key_up = 0; } // flèche du haut est appuyé
	if(key==GLUT_KEY_DOWN){ keys.key_down = 0; } // flèche du bas est appuyé
	if(key==GLUT_KEY_LEFT){ keys.key_left = 0; } // flèche de gauche appuyé 
	if(key==GLUT_KEY_RIGHT){ keys.key_right = 0; } // flèche de droite appuyé
	if(key==GLUT_KEY_PAGE_UP){ keys.key_page_up = 0; } // flèche haut de page appuyé
	if(key==GLUT_KEY_PAGE_DOWN){ keys.key_page_down = 0; } // flèche bas de page appuyé
	
	debug("<specialKeyDown> end");
}

/**
 * Vérifie quel touche du clavier [SPECIALE] a été relachée pour engendré son appel
 * Passe le booléen correspondant à la touche appuyée à 1 (permet d'informer le reste du programme que cette touche est relachée)
 * @author Yann LEFEVRE
 * */
void specialKeyUp(int key, int x, int y){
	debug("<specialKeyUp> begin");
	
	if(key==GLUT_KEY_UP){ keys.key_up = 1; } // flèche du haut relaché
	if(key==GLUT_KEY_DOWN){ keys.key_down = 1; } // flèche du bas relaché
	if(key==GLUT_KEY_LEFT){ keys.key_left = 1; } // flèche de gauche relaché
	if(key==GLUT_KEY_RIGHT){ keys.key_right = 1; } // flèche de droite relaché
	if(key==GLUT_KEY_PAGE_UP){ keys.key_page_up = 1; } // flèche haut de page relaché
	if(key==GLUT_KEY_PAGE_DOWN){ keys.key_page_down = 1; } // flèche bas de page relaché
	
	debug("<specialKeyUp> end");
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction testant si une touche est appuyée ou non
 * Renvoi 1 si oui, 0 sinon
 * @author Yann LEFEVRE
 * */
bool keyIsDown(bool key){
	debug("<keyIsDown> begin");
	
	return !key;
	
	debug("<keyIsDown> end");
}

/**
 * Fonction testant si une touche est relachée ou non
 * Renvoi 1 si oui, 0 sinon
 * @author Yann LEFEVRE
 * */
bool keyIsUp(bool key){
	debug("<keyIsUp> begin");
	
	return key;
	
	debug("<keyIsUp> end");
}
