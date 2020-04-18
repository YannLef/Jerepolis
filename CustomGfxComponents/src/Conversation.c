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
#include "../headers/Couleur.h"
#include "../headers/Keyboard.h"
#include "../headers/BoundedRectangle.h"

/**
 * Includes correspondant
 * */
#include "../headers/Conversation.h"

extern couleurTab c; // Synchronise le tableau de couleurs

/**
 * @brief Fonction permettant d'initialiser un message
 * @param msg le message a initialiser
 * @param sender la valeur correspondant à l'envoyeur (0 si assistant, 1 si utilisateur)
 * @param string le message
 * @author Yann LEFEVRE
 * */
void initMessage(message* msg, bool sender, char* string){
	debug("<initMessage> begin");
	
	msg->sender = sender;
	msg->string = malloc(sizeof(char)*(strlen(string) + 1));
	strcpy(msg->string,string);
	
	debug("<initMessage> end");
}

/**
 * @brief Fonction permettant de supprimer un message de la mémoire, permettant de faire une rotation propre des messages dans ajouteMessage()
 * @author Yann LEFEVRE
 * */
void libereMessage(message* msg){
	debug("<libereMessage> begin");
	
	if(msg != NULL && msg->string != NULL){
		free(msg->string);
	}
	
	debug("<libereMessage> end");
}

/**
 * @brief Fonction permettant d'ajouter un message à la conversation entre l'assistant et l'utilisateur
 * @param messages L'adresse du tableau contenant les adresses des messages
 * @param nbMessageMax Le nombre maximum de messages qui vont être stockés/affichés dans la conversation
 * @brief nbMessage Le nombre actuel de messages dans la conversation
 * */
void ajouteMessage(message*** messages, message* msg, int nbMessageMax, int* nbMessage){
	debug("<ajouteMessage> begin");
	
	if(*nbMessage < nbMessageMax){ // Si on a pas atteint le nombre max de messages, on rajoute simplement le nouveau message à la suite
		*nbMessage = *nbMessage +1;
		message** tmp = malloc(sizeof(message*)*(*nbMessage));
		for(int i=0;i<(*nbMessage)-1;i++){ // On recopie le début du tableau dans la variable temporaire
			tmp[i] = (*messages)[i];
		}
		tmp[*nbMessage-1] = msg; // On ajoute le dernier élément au tableau
		if(*messages != NULL) // Si l'ancien tableau n'est pas nul on libère la mémoire car il est devenu obsolète
			free(*messages);
		*messages = tmp;
		tmp = NULL;
	}else{ // Si on a déjà atteint le nombre max de messages, il faut supprimer le plus vieux pour faire de la place et accueillir le nouveau message
		message** tmp = malloc(sizeof(message*)*nbMessageMax);
		for(int i=0;i<(*nbMessage);i++){ // On recopie le début du tableau dans la variable temporaire, excepté la première case qui va être supprimée
			if(i != 0){
				tmp[i-1] = (*messages)[i];
			}
		}
		libereMessage((*messages)[0]);
		tmp[nbMessageMax-1] = msg; // On ajoute le dernier élément au tableau
		if(*messages != NULL) // Si l'ancien tableau n'est pas nul on libère la mémoire car il est devenu obsolète
			free(*messages);
		*messages = tmp;
		tmp = NULL;
	}
	
	debug("<ajouteMessage> end");
}

void afficheConversation(message** messages, int nbMessage, DonneesImageRGB* user, DonneesImageRGB* help){
	debug("<afficheConversation> begin");
	
	BoundedRectangle b;
	int decalageCentre = 40;
	int ordonneeBaseMessage = 700;
	int abscisseBaseMessage = 70 + (620-70)/2;
	int largeurMessage = 400;
	int hauteurMessage = 100;
	int decalageMessage = 120;
	int radiusMessages = 40;
	int epaisseurMessages = 5;
	float epaisseurTexteMessage;
	
	float taille; // S'adapte au message
	
	for(int i=0;i<nbMessage;i++){
		taille = 0;
		while(tailleChaine(messages[i]->string, taille) < largeurMessage-100 && taille < hauteurMessage && taille < 25){
			taille = taille + 0.1;
		}
		epaisseurTexteMessage = taille / 10;
		
		if(messages[i]->sender == 1){ // Si le message est de l'utilisateur
			initBoundedRectangle(&b, abscisseBaseMessage + decalageCentre, ordonneeBaseMessage - i*decalageMessage, largeurMessage, hauteurMessage, 5, c.couleurHomme, c.couleurHomme);
			afficheBoundedRectangle(b);
			
			ecrisImage(abscisseBaseMessage + decalageCentre - user->largeurImage + largeurMessage/2 - 10, ordonneeBaseMessage - i*decalageMessage - user->hauteurImage/2, user->largeurImage, user->hauteurImage, user->donneesRGB); // icon
			
			epaisseurDeTrait(epaisseurTexteMessage);
			changeColor(c.blanc);
			afficheChaine(messages[i]->string, taille, abscisseBaseMessage + decalageCentre - tailleChaine(messages[i]->string,taille)/2 - 30, ordonneeBaseMessage - decalageMessage*i - taille/2);
		}else{ // Si le message est de l'assistant
			initBoundedRectangle(&b, abscisseBaseMessage - decalageCentre, ordonneeBaseMessage - i*decalageMessage, largeurMessage, hauteurMessage, 5, c.vertPrincipal, c.vertPrincipal);
			afficheBoundedRectangle(b);
			
			ecrisImage(abscisseBaseMessage - decalageCentre - largeurMessage/2 + 10, ordonneeBaseMessage - i*decalageMessage - help->hauteurImage/2, help->largeurImage, help->hauteurImage, help->donneesRGB); // icon
			
			epaisseurDeTrait(epaisseurTexteMessage);
			changeColor(c.blanc);
			afficheChaine(messages[i]->string, taille, abscisseBaseMessage - decalageCentre - tailleChaine(messages[i]->string,taille)/2 + 30, ordonneeBaseMessage - decalageMessage*i - taille/2);

		}
	}
	
	debug("<afficheConversation> end");
}
