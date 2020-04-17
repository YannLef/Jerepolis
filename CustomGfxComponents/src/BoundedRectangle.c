#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Keyboard.h"

#include "../headers/BoundedRectangle.h"

/* Fonction de trace de cercle */
void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;
	
	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
	
}

void initBoundedRectangle(BoundedRectangle *b, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure){
    b->x = x;
    b->y = y;
    b->largeur = largeur;
    b->hauteur = hauteur;
    b->epaisseurBordure = epaisseurBordure;
    b->cInterieur = cInterieur;
    b->cBordure = cBordure;
}

void afficheBoundedRectangle(BoundedRectangle b){
	int marge = 40;

	changeColor(b.cBordure);
	
	rectangle(b.x - b.largeur/2 + marge, b.y - b.hauteur/2, b.x + b.largeur/2 - marge, b.y + b.hauteur/2); // Rectangle sur la hauteur
	rectangle(b.x - b.largeur/2, b.y - b.hauteur/2 + marge, b.x + b.largeur/2, b.y + b.hauteur/2 - marge); // Rectangle sur la largeur
	cercle(b.x - b.largeur/2 + marge, b.y - b.hauteur/2 + marge, marge-1); // En bas à gauche
	cercle(b.x + b.largeur/2 - marge, b.y - b.hauteur/2 + marge, marge-1); // En bas à droite
	cercle(b.x - b.largeur/2 + marge, b.y + b.hauteur/2 - marge, marge-1); // En haut à gauche
	cercle(b.x + b.largeur/2 - marge, b.y + b.hauteur/2 - marge, marge-1); // En haut à droite

	changeColor(b.cInterieur);
	rectangle(b.x - b.largeur/2 + marge + b.epaisseurBordure, b.y - b.hauteur/2 + b.epaisseurBordure, b.x + b.largeur/2 - marge - b.epaisseurBordure, b.y + b.hauteur/2 - b.epaisseurBordure); // Rectangle sur la hauteur
	rectangle(b.x - b.largeur/2 + b.epaisseurBordure, b.y - b.hauteur/2 + marge + b.epaisseurBordure, b.x + b.largeur/2 - b.epaisseurBordure, b.y + b.hauteur/2 - marge - b.epaisseurBordure); // Rectangle sur la largeur
	cercle(b.x - b.largeur/2 + marge + b.epaisseurBordure, b.y - b.hauteur/2 + marge + b.epaisseurBordure, marge); // En bas à gauche
	cercle(b.x + b.largeur/2 - marge - b.epaisseurBordure, b.y - b.hauteur/2 + marge + b.epaisseurBordure, marge); // En bas à droite
	cercle(b.x - b.largeur/2 + marge + b.epaisseurBordure, b.y + b.hauteur/2 - marge - b.epaisseurBordure, marge); // En haut à gauche
	cercle(b.x + b.largeur/2 - marge - b.epaisseurBordure, b.y + b.hauteur/2 - marge - b.epaisseurBordure, marge); // En haut à droite
	
}

