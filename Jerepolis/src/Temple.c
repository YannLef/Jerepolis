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
#include "../headers/Batiment.h"

/**
 * Includes correspondant
 * */
#include "../headers/Temple.h"

void affichePopupTemple(Popups popups, Batiment temple){
	if(popups.actuel == POPUP_TEMPLE){
		if(temple.popup != NULL){ ecrisImage(167, 90, temple.popup->largeurImage, temple.popup->hauteurImage, temple.popup->donneesRGB);}
	}
}

void gereClicGauchePopupTemple(Popups* popups, int x, int y, Batiment* temple){
	if(popups->actuel == POPUP_TEMPLE){
		// Gère clic sur la croix
		if(x > 958 && x < 978 && y > 628 && y < 647){
			if(popups->actuel == popups->final){
				popups->final = POPUP_NONE;
				setPopupImage(temple, "popup");
			}
		}
		
		// Gère clic Zeus
		if(x > 184 && x < 249 && y > 184 && y < 243){
			setPopupImage(temple, "popupZeus");
		}
		
		// Gère clic Poséidon
		if(x > 249 && x < 314 && y > 184 && y < 243){
			setPopupImage(temple, "popupPoseidon");
		}
		
		// Gère clic Hades
		if(x > 314 && x < 381 && y > 184 && y < 243){
			setPopupImage(temple, "popupHades");
		}
	}
}
