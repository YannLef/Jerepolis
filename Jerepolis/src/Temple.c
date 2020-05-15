/**
 * Includes Classiques
 * */
#include <stdlib.h>
#include <stdio.h>
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

void gereClicGauchePopupTemple(Popups* popups, int x, int y, Batiment* temple, float* faveur, Divinite* divinite){
	static Divinite diviniteTmp = DIVINITE_NONE;
	
	if(popups->actuel == POPUP_TEMPLE){
		// Gère clic sur la croix
		if(x > 958 && x < 978 && y > 628 && y < 647){
			if(popups->actuel == popups->final){
				popups->final = POPUP_NONE;
				setPopupImage(temple, "popup");
				diviniteTmp = DIVINITE_NONE;
			}
		}
		
		// Gère clic Zeus
		if(x > 184 && x < 249 && y > 184 && y < 243){
			setPopupImage(temple, "popupZeus");
			diviniteTmp = DIVINITE_ZEUS;
		}
		
		// Gère clic Poséidon
		if(x > 249 && x < 314 && y > 184 && y < 243){
			setPopupImage(temple, "popupPoseidon");
			diviniteTmp = DIVINITE_POSEIDON;
		}
		
		// Gère clic Hades
		if(x > 314 && x < 381 && y > 184 && y < 243){
			setPopupImage(temple, "popupHades");
			diviniteTmp = DIVINITE_HADES;
		}
		
		if(x > 339 && x < 425 && y > 285 && y < 306){
			if(diviniteTmp == DIVINITE_ZEUS){
				if(*divinite != diviniteTmp){
					*faveur = 0;
					*divinite = diviniteTmp;
					
				}
			}else if(diviniteTmp == DIVINITE_POSEIDON){
				if(*divinite != diviniteTmp){
					*faveur = 0;
					*divinite = diviniteTmp;
				}
			}else if(diviniteTmp == DIVINITE_HADES){
				if(*divinite != diviniteTmp){
					*faveur = 0;
					*divinite = diviniteTmp;
					
				}
			}
		}
	}
}

void genereFaveurs(Batiment temple, Divinite divinite, float* faveur){
	if(divinite != DIVINITE_NONE){
		genereRessource(temple, faveur, 500);
	}
}
