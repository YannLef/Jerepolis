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
 * Includes Jerepolis
 * */
#include "../headers/structures.h"

/**
 * Includes correspondant
 * */
#include "../headers/Mine.h"

void affichePopupMine(Popups popups, Batiment mine){
	if(popups.actuel == POPUP_MINE){
		if(mine.popup != NULL){ ecrisImage(167, 90, mine.popup->largeurImage, mine.popup->hauteurImage, mine.popup->donneesRGB);}
	}
}

void gereClicGauchePopupMine(Popups* popups, int x, int y){
	if(popups->actuel == POPUP_MINE){
		// Gère clic sur la croix
		if(x > 960 && x < 978 && y > 633 && y < 647){
			if(popups->actuel == popups->final){
				popups->final = POPUP_NONE;
			}
		}
	}
}
