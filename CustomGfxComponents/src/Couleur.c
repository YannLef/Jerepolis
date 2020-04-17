#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"

extern couleurTab c; // Synchronise le clavier avec les autres fichiers

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Initialise le tableau de couleurs utilisé dans le programme entier :
 * -> permet d'utiliser facilement des couleurs grâce à leur nom commun ce qui évite d'avoir à retenir les codes RGB 
 * @author Yann LEFEVRE
 * */
void initCouleurTab(couleurTab* c){
	initCouleur(&(c->couleurHomme), 49, 140, 231);
	initCouleur(&(c->couleurFemme), 223, 115, 255);
	initCouleur(&(c->couleurMenuDeroulant), 130, 224, 170);
	initCouleur(&(c->gris180), 180, 180, 180);
	initCouleur(&(c->gris125), 125, 125, 125);
	initCouleur(&(c->blanc), 255, 255, 255);
	initCouleur(&(c->noir), 0, 0, 0);
	initCouleur(&(c->vertPrincipal), 139, 195, 74);
	initCouleur(&(c->bleuEcriture), 38, 193, 225);
	initCouleur(&(c->fondPrincipal), 241, 255, 251);
}

/**
 * Initialise une couleur à partir des nuances de R, V et B :
 * -> permet de simplifier les prototypes de nombreuses fonctions (1 paramètre couleur au lieu de 3 paramètres pour R, V et B)
 * @author Yann LEFEVRE
 * */
void initCouleur(couleur* c, unsigned char r, unsigned char v, unsigned char b){
	c->r = r;
	c->v = v;
	c->b = b;
}

/**
 * Change la couleur de tracé de la GFX en lui appliquant la couleur passée en paramètre
 * @author Yann LEFEVRE
 * */
void changeColor(couleur c){
	couleurCourante(c.r,c.v,c.b);
}
