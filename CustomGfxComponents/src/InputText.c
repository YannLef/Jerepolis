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
#include "../headers/Rectangle.h"

/**
 * Includes correspondant
 * */
#include "../headers/InputText.h"

extern Keyboard keys; // Synchronise le clavier avec les autres fichiers

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Fonction qui initialise un input de type texte.
 * @author Yann LEFEVRE
 * */
void initInputText(InputText* input, int etat, int x, int y, int largeur, int hauteur, int epaisseurBordure, Couleur cInterieur, Couleur cBordure){
	debug("<initInputText> begin");
	
	input->etat = etat; // l'état permet de savoir si l'input à le focus (=1) ou non (=0) : si on a le focus alors on peut nous écrire dedans
	input->size = 0; // la taille actuelle de la chaine, gérée dynamiquement
	input->string = NULL; // la chaine, initialement vide => NULL
	initRectangle(&(input->rect),x,y,largeur,hauteur,epaisseurBordure,cInterieur,cBordure);
	
	debug("<initInputText> end");
}

/**
 * @brief Fonction permettant de remettre à 0 proprement la chaine de l'input
 * @author Yann LEFEVRE
 * */
void resetInputText(InputText* input){
	debug("<resetInputText> begin");
	
	if(input->string != NULL){
		free(input->string); // On libère la mémoire allouée
		input->string = NULL; // On met le pointeur à null
		input->size = 0; // On indique que la taille de la chaine est = à 0
	}
	
	debug("<resetInputText> end");
}

/**
 * @brief Fonction permettant de modifier le texte d'un input text, vérifie si la chaine est vide
 * @param input L'input a actualiser
 * @param string la chaine à ajouter
 * @author Yann LEFEVRE
 * */
void setString(InputText* input, char* string){
	debug("<setString> begin");
	
	if(string != NULL){
		input->string = malloc(sizeof(char*)*(strlen(string) + 1));
		input->size = strlen(string) + 1;
		strcpy(input->string,string);
	}else{
		if(input->string != NULL){
			free(input->string);
		}
		input->string = NULL;
	}
	
	debug("<setString> end");
}
  
 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * Fonction affichant un input ( rectangle de base avec sa chaine centrée et automatiquement dimensionnée pour ne pas sortir du rectangle)
 * @author Yann LEFEVRE
 * */
void afficheInputTexte(InputText input){
	debug("<afficheInputTexte> begin");
	
	afficheRectangle(input.rect); // Affiche le rectangle servant pour limitation de l'input
	if(input.string != NULL){
		couleurCourante(0,0,0);
		float taille = 0;
		while(tailleChaine(input.string, taille) < input.rect.largeur-20 && taille < input.rect.hauteur - (15*input.rect.hauteur)/100)
			taille = taille + 0.1;
		
		int x = input.rect.x - tailleChaine(input.string,taille)/2;
		int y = input.rect.y - taille/3;
		afficheChaine(input.string,taille,x,y);
	}
	
	debug("<afficheInputTexte> end");
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de changer l'etat d'un input
 * @author Yann LEFEVRE
 * */
void toggleEtatInput(InputText* input){
	debug("<toggleEtatInput> begin");
	
	if(input->etat){
		input->etat = 0;
	}else{
		input->etat = 1;
	}
	
	debug("<toggleEtatInput> begin");
}

/**
 * Fonction permettant de définir l'etat d'un input
 * */
void setEtatInput(InputText* input, bool etat){
	debug("<setEtatInput> begin");
	
	input->etat = etat;
	
	debug("<setEtatInput> begin");
}

/**
 * Fonction permettant de mettre à jour la chaine de caractère d'un input texte en fonction du clavier
 * @author Yann LEFEVRE
 * */
void completeInputText(InputText* input, char c){
	debug("<completeInputText> begin");
	
	char* tmp; // On utilise un variable temporaire pour permutter entre l'ancienne chaine et la nouvelle
	if(c != 127 && c != 8){ // On ajoute une lettre (car la touche appué n'est ni del ni backspace)
			input->size ++; // On augmente la taille actuelle
			if(input->string != NULL){ // Selon si la chaine actuelle est vide ou non on agit différement
				// Si elle n'est pas vide,
				tmp = malloc(sizeof(char)*input->size); // On alloue une chaine avec 1 espace de plus que l'ancienne
				for(int i=0;i<input->size -2;i++){ // On recopie l'ancienne chaine dans la nouvelle
					tmp[i] = input->string[i];
				}
				tmp[input->size -2]=c; // On ajoute le nouveau caractère entré
				tmp[input->size -1]='\0'; // On n'oublie surtout pas le \0 indiquant la fin de la chaine
				free(input->string); // On libère l'ancienne chaine
				input->string = tmp; // On fait pointer la structure vers la nouvelle chaine
			}else{ // Si la chaine est vide,
				input->size ++; // On augmente la taille actuelle (encore une fois), pour prévoir la place occupée par le \0
				tmp = malloc(sizeof(char)*input->size); // On alloue une chaine permettant de stocker le premier caractère + \0
				tmp[0] = c; // On copie le caractère 
				tmp[1] = '\0'; // On ajoute le \0 pour indiquer la fin de la chaine
				input->string = tmp; // On fait pointer la structure vers la nouvelle chaine
			}
	}else{ // On supprime une lettre (car la touche appuyée est del ou backspace)
		if(input->string != NULL){ // On agit différemment en fonction de si la chaine est vide ou non
			// Si la chaine n'est pas vide,
			input->size --; // On diminue la taille actuelle
			if(input->size != 0){ // On vérifie que la nouvelle taille est différente de 0 (sinon il n'y a rien à recopier)
				tmp = malloc(sizeof(char)*input->size); // On alloue une nouvelle chaine avec la nouvelle taille
				for(int i=0;i<input->size -1;i++){ // On recopie l'ancienne chaine sauf le dernier caractère (en fait avant dernier car le dernier est \0)
					tmp[i] = input->string[i];
				}
				tmp[input->size -1] = '\0'; // On rajoute le \0 à la fin de la nouvelle chaine
				free(input->string); // On libère l'ancienne chaine 
				input->string = tmp; // On fait pointer la structure vers la nouvelle chaine
			}else{
				// Si la taille devient 0, alors il n'y a plus de chaine
				free(input->string); // On libère la chaine
				input->string = NULL; // On indique qu'il n'y à plus de chaine à cet emplacement (IMPORTANT)
			}
		}
	}
	
	debug("<completeInputText> end");
}

/**
 * Fonction permettant d'indiquer à l'input quel caractère va intervenir dans sa chaine
 * Sert d'interprête entre les informations du clavier et l'input
 * @author Yann LEFEVRE
 * */
void updateInputText(InputText* input){
	debug("<updateInputText> begin");
	
	if(input->etat){
			// On vérifie quelle touche a été enfoncée.
			// Si une touche est enfoncée, on indique à l'input qu'il doit la prendre en compte (modifier sa chaine en fonction).
			// Une fois que l'information est transmise, on indique que la touche n'est plus appuyée (même si cela peut être faux), afin de ne pas recopier la même lettre en boucle
			if(keys.key_a==0){ completeInputText(input, 'a'); keys.key_a = 1; }
			if(keys.key_A==0){ completeInputText(input, 'A'); keys.key_A = 1; }
			if(keys.key_b==0){ completeInputText(input, 'b'); keys.key_b = 1; }
			if(keys.key_B==0){ completeInputText(input, 'B'); keys.key_B = 1; }
			if(keys.key_c==0){ completeInputText(input, 'c'); keys.key_c = 1; }
			if(keys.key_C==0){ completeInputText(input, 'C'); keys.key_C = 1; }
			if(keys.key_d==0){ completeInputText(input, 'd'); keys.key_d = 1; }
			if(keys.key_D==0){ completeInputText(input, 'D'); keys.key_D = 1; }
			if(keys.key_e==0){ completeInputText(input, 'e'); keys.key_e = 1; }
			if(keys.key_E==0){ completeInputText(input, 'E'); keys.key_E = 1; }
			if(keys.key_f==0){ completeInputText(input, 'f'); keys.key_f = 1; }
			if(keys.key_F==0){ completeInputText(input, 'F'); keys.key_F = 1; }
			if(keys.key_g==0){ completeInputText(input, 'g'); keys.key_g = 1; }
			if(keys.key_G==0){ completeInputText(input, 'G'); keys.key_G = 1; }
			if(keys.key_h==0){ completeInputText(input, 'h'); keys.key_h = 1; }
			if(keys.key_H==0){ completeInputText(input, 'H'); keys.key_H = 1; }
			if(keys.key_i==0){ completeInputText(input, 'i'); keys.key_i = 1; }
			if(keys.key_I==0){ completeInputText(input, 'I'); keys.key_I = 1; }
			if(keys.key_j==0){ completeInputText(input, 'j'); keys.key_j = 1; }
			if(keys.key_J==0){ completeInputText(input, 'J'); keys.key_J = 1; }
			if(keys.key_k==0){ completeInputText(input, 'k'); keys.key_k = 1; }
			if(keys.key_K==0){ completeInputText(input, 'K'); keys.key_K = 1; }
			if(keys.key_l==0){ completeInputText(input, 'l'); keys.key_l = 1; }
			if(keys.key_L==0){ completeInputText(input, 'L'); keys.key_L = 1; }
			if(keys.key_m==0){ completeInputText(input, 'm'); keys.key_m = 1; }
			if(keys.key_M==0){ completeInputText(input, 'M'); keys.key_M = 1; }
			if(keys.key_n==0){ completeInputText(input, 'n'); keys.key_n = 1; }
			if(keys.key_N==0){ completeInputText(input, 'N'); keys.key_N = 1; }
			if(keys.key_o==0){ completeInputText(input, 'o'); keys.key_o = 1; }
			if(keys.key_O==0){ completeInputText(input, 'O'); keys.key_O = 1; }
			if(keys.key_p==0){ completeInputText(input, 'p'); keys.key_p = 1; }
			if(keys.key_P==0){ completeInputText(input, 'P'); keys.key_P = 1; }
			if(keys.key_q==0){ completeInputText(input, 'q'); keys.key_q = 1; }
			if(keys.key_Q==0){ completeInputText(input, 'Q'); keys.key_Q = 1; }
			if(keys.key_r==0){ completeInputText(input, 'r'); keys.key_r = 1; }
			if(keys.key_R==0){ completeInputText(input, 'R'); keys.key_R = 1; }
			if(keys.key_s==0){ completeInputText(input, 's'); keys.key_s = 1; }
			if(keys.key_S==0){ completeInputText(input, 'S'); keys.key_S = 1; }
			if(keys.key_t==0){ completeInputText(input, 't'); keys.key_t = 1; }
			if(keys.key_T==0){ completeInputText(input, 'T'); keys.key_T = 1; }
			if(keys.key_u==0){ completeInputText(input, 'u'); keys.key_u = 1; }
			if(keys.key_U==0){ completeInputText(input, 'U'); keys.key_U = 1; }
			if(keys.key_v==0){ completeInputText(input, 'v'); keys.key_v = 1; }
			if(keys.key_V==0){ completeInputText(input, 'V'); keys.key_V = 1; }
			if(keys.key_w==0){ completeInputText(input, 'w'); keys.key_w = 1; }
			if(keys.key_W==0){ completeInputText(input, 'W'); keys.key_W = 1; }
			if(keys.key_x==0){ completeInputText(input, 'x'); keys.key_x = 1; }
			if(keys.key_X==0){ completeInputText(input, 'X'); keys.key_X = 1; }
			if(keys.key_y==0){ completeInputText(input, 'y'); keys.key_y = 1; }
			if(keys.key_Y==0){ completeInputText(input, 'Y'); keys.key_Y = 1; }
			if(keys.key_z==0){ completeInputText(input, 'z'); keys.key_z = 1; }
			if(keys.key_Z==0){ completeInputText(input, 'Z'); keys.key_Z = 1; }
			
			if(keys.key_0==0){ completeInputText(input, '0'); keys.key_0 = 1; }
			if(keys.key_1==0){ completeInputText(input, '1'); keys.key_1 = 1; }
			if(keys.key_2==0){ completeInputText(input, '2'); keys.key_2 = 1; }
			if(keys.key_3==0){ completeInputText(input, '3'); keys.key_3 = 1; }
			if(keys.key_4==0){ completeInputText(input, '4'); keys.key_4 = 1; }
			if(keys.key_5==0){ completeInputText(input, '5'); keys.key_5 = 1; }
			if(keys.key_6==0){ completeInputText(input, '6'); keys.key_6 = 1; }
			if(keys.key_7==0){ completeInputText(input, '7'); keys.key_7 = 1; }
			if(keys.key_8==0){ completeInputText(input, '8'); keys.key_8 = 1; }
			if(keys.key_9==0){ completeInputText(input, '9'); keys.key_9 = 1; }
			
			if(keys.key_spacebar==0){ completeInputText(input, ' '); keys.key_spacebar = 1; }
			if(keys.key_slash==0){ completeInputText(input, '/'); keys.key_slash = 1; }
			
			// Pour les deux touches suivantes, on passe directement leur code ascii car elles ne correspondent à aucune touche visible sur le clavier
			// Ce sont celles servant à la suppression de caractères dans la chaine
			if(keys.key_del==0){ completeInputText(input, 127); keys.key_del = 1; }
			if(keys.key_backspace==0){ completeInputText(input, 8); keys.key_backspace = 1; }
		}
		
	debug("<updateInputText> end");
}

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction qui gère les clics sur un inputText
 * Passe son état à 1 si le clic est dessus / à 0 si le clic est en dehors
 * @author Yann LEFEVRE
 * */
void gereSourisInputText(InputText* input, int xSouris, int ySouris){
	debug("<gereSourisInputText> begin");
	
	if(isOnRectangle(xSouris,ySouris,input->rect)){
		setEtatInput(input,1);
	}else{
		setEtatInput(input,0);
	}
	
	debug("<gereSourisInputText> end");
}
