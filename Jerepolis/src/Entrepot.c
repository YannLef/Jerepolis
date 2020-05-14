/**
 * Includes Classiques
 * */
#include <stdlib.h>
#include <stdio.h>

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
#include "../../CustomGfxComponents/headers/structures.h"
#include "../../CustomGfxComponents/headers/Couleur.h"
#include "../../CustomGfxComponents/headers/Image.h"

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"

/**
 * Includes correspondant
 * */
#include "../headers/Entrepot.h"

extern CouleurTab c;

void actualiseStockageEntrepot(int* stockageEntrepot, Batiment entrepot){
	*stockageEntrepot = entrepot.population * 50 + 200;
}

void affichePopupEntrepot(Popups popups, Batiment entrepot, float bois, float pierre, float argent, int stockageEntrepot){
	if(popups.actuel == POPUP_ENTREPOT){
		if(entrepot.popup != NULL){ ecrisImage(167, 90, entrepot.popup->largeurImage, entrepot.popup->hauteurImage, entrepot.popup->donneesRGB);}
		
		changeColor(c.noir);
		
		char texteBois[100];
		sprintf(texteBois,"( %.0f / %d )", bois, stockageEntrepot);
		afficheChaine(texteBois, 10, 342, 596);
		
		char textePierre[100];
		sprintf(textePierre,"( %.0f / %d )", pierre, stockageEntrepot);
		afficheChaine(textePierre, 10, 349, 532);
		
		char texteArgent[100];
		sprintf(texteArgent,"( %.0f / %d )", argent, stockageEntrepot);
		afficheChaine(texteArgent, 10, 387, 468);
		
	}
}

void gereClicGauchePopupEntrepot(Popups* popups, int x, int y){
	if(popups->actuel == POPUP_ENTREPOT){
		// Gère clic sur la croix
		if(x > 928 && x < 947 && y > 632 && y < 650){
			if(popups->actuel == popups->final){
				popups->final = NONE;
			}
		}
	}
}
