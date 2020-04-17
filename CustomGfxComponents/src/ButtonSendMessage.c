#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Page.h"
#include "../headers/Rectangle.h"
#include "../headers/Conversation.h"
#include "../headers/InputText.h"

#include "../headers/ButtonSendMessage.h"


 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * @brief Fonction permettant d'initialiser un bouton ayant pour unique but d'envoyer un message via l'assistant
 * @author Yann LEFEVRE
 * */
void initBoutonSendMessage(boutonSendMessage* b, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure, couleur cText, int epaisseurTrait){

	b->string = malloc(sizeof(char)*3);
	strcpy(b->string,"OK");
	b->cText = cText;
	b->epaisseurTrait = epaisseurTrait;
	initRectangle(&(b->rect),x,y,largeur,hauteur,epaisseurBordure,cInterieur, cBordure);
	
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * @brief Fonction permettant d'afficher un bouton permettant denvoyer un message
 * @author Yann LEFEVRE
 * */
void afficheBoutonSendMessage(boutonSendMessage b, int xEcran, int yEcran, float coefZoom){
	afficheRectangle(b.rect,0,xEcran,yEcran,coefZoom);
	if(b.string != NULL){
		couleurCourante(b.cText.r,b.cText.v,b.cText.b);
		epaisseurDeTrait(b.epaisseurTrait);
		
		int i=0; // compteur
		int maxSize=1; // On calcule la taille maximum de la chaîne
		while(b.string[i] != '\0'){
			maxSize++;
			i++;
		}
	
		float taille;
		
		if(b.rect.largeur > b.rect.hauteur){
			taille = b.rect.hauteur/(maxSize*0.3); // Calcule la taille de la police pour qu'elle s'adapte à la taille du bouton
		}else{
			taille = b.rect.largeur/(maxSize*0.7); // Calcule la taille de la police pour qu'elle s'adapte à la taille du bouton
		}
		int x = b.rect.x - tailleChaine(b.string,taille)/2;
		int y = b.rect.y - taille/3;
		afficheChaine(b.string,taille,x,y);
	}
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
/**
 * @brief Fonction permettant d'envoyer un message en fonction du clic sur le bouton
 * @author Yann LEFEVRE
 * */
void gereSourisBoutonSendMessage(boutonSendMessage b, inputText* inputAssistant, message*** messages, int nbMessageMax, int* nbMessage, int xSouris, int ySouris){
	// On vérifie que le clic est bel est bien sur le bouton
	if(isOnRectangle(xSouris,ySouris,b.rect)){
		message* msg = (message*)malloc(sizeof(message));
		initMessage(msg, 1, inputAssistant->string);
		ajouteMessage(messages, msg, nbMessageMax, nbMessage);

		resetInputText(inputAssistant);
	}
}
