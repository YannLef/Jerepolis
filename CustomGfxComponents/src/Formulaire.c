#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <unistd.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Keyboard.h"
#include "../headers/Mouse.h"
#include "../headers/Rectangle.h"
#include "../headers/ButtonChangePage.h"
#include "../headers/ButtonChangeFile.h"
#include "../headers/Page.h"
#include "../headers/DropDownMenuRight.h"
#include "../headers/Navbar.h"
#include "../headers/InputText.h"
#include "../headers/FileExplorer.h"
#include "../headers/SliderVertical.h"
#include "../headers/SliderHorizontal.h"
#include "../headers/Carre.h"
#include "../headers/Checkbox.h"
#include "../headers/RadioButton.h"
#include "../headers/Formulaire.h"

extern couleurTab c;

void initForm(Form* formulaire){
	formulaire->nbCheckbox = 0;
	formulaire->nbRadioButton = 0;
	formulaire->nbInpuText = 0;
	formulaire->tabCheckbox = NULL; // tableau des checkbox
	formulaire->tabRadioButton = NULL; // tableau des radio button
    formulaire->tabInpuText = NULL; // tableau des input text
}

void freeForm(Form* formulaire){
	
	// Il n'y a pas besoin de free les inputs eux même car ils sont en static et non malloc
	
	// Les checkbox
	free(formulaire->tabCheckbox);
	formulaire->tabCheckbox = NULL;
	
	// Les radiobutton
	free(formulaire->tabRadioButton);
	formulaire->tabRadioButton = NULL;
	
	// Les radiobutton
	for(int i=0;i<formulaire->nbInpuText;i++){
		if(formulaire->tabRadioButton != NULL){
			resetInputText(formulaire->tabInpuText[i]);
		}
	}
	free(formulaire->tabInpuText);
	formulaire->tabInpuText = NULL;
}

void addCheckboxToForm(Form* formulaire, checkbox* cb){
	if(formulaire->nbCheckbox == 0){ // Si le tableau est vide
		formulaire->nbCheckbox = 1;
		formulaire->tabCheckbox = (checkbox**)malloc(sizeof(checkbox*)*formulaire->nbCheckbox);
		formulaire->tabCheckbox[0] = cb;
	}else{ // Si le tableau n'est pas vide, il faut penser à recopier l'ancien tableau dans le nouveau
		formulaire->nbCheckbox = formulaire->nbCheckbox + 1;
		checkbox** tmp  = (checkbox**)malloc(sizeof(checkbox*)*formulaire->nbCheckbox);
		
		// On recopie l'ancien tableau
		for(int i=0;i<formulaire->nbCheckbox-1;i++){
			tmp[i] = formulaire->tabCheckbox[i];
		}
		
		// On ajoute le nouvel élément en fin de tableau
		tmp[formulaire->nbCheckbox - 1] = cb;
		
		// On remplace l'ancien tableau par le nouveau, sans oublier de libérer la mémoire
		free(formulaire->tabCheckbox);
		formulaire->tabCheckbox = tmp;
		tmp = NULL;
	}
}

void addRadioButtonToForm(Form* formulaire, radiobutton* rb){
	if(formulaire->nbRadioButton == 0){ // Si le tableau est vide
		formulaire->nbRadioButton = 1;
		formulaire->tabRadioButton = (radiobutton**)malloc(sizeof(radiobutton*)*formulaire->nbRadioButton);
		formulaire->tabRadioButton[0] = rb;
	}else{ // Si le tableau n'est pas vide, il faut penser à recopier l'ancien tableau dans le nouveau
		formulaire->nbRadioButton = formulaire->nbRadioButton + 1;
		radiobutton** tmp  = (radiobutton**)malloc(sizeof(radiobutton*)*formulaire->nbRadioButton);
		
		// On recopie l'ancien tableau
		for(int i=0;i<formulaire->nbRadioButton-1;i++){
			tmp[i] = formulaire->tabRadioButton[i];
		}
		
		// On ajoute le nouvel élément en fin de tableau
		tmp[formulaire->nbRadioButton - 1] = rb;
		
		// On remplace l'ancien tableau par le nouveau, sans oublier de libérer la mémoire
		free(formulaire->tabRadioButton);
		formulaire->tabRadioButton = tmp;
		tmp = NULL;
	}
}

void addInputTextToForm(Form* formulaire, inputText* input){
	if(formulaire->nbInpuText == 0){ // Si le tableau est vide
		formulaire->nbInpuText = 1;
		formulaire->tabInpuText = (inputText**)malloc(sizeof(inputText*)*formulaire->nbInpuText);
		formulaire->tabInpuText[0] = input;
	}else{ // Si le tableau n'est pas vide, il faut penser à recopier l'ancien tableau dans le nouveau
		formulaire->nbInpuText = formulaire->nbInpuText + 1;
		inputText** tmp  = (inputText**)malloc(sizeof(inputText*)*formulaire->nbInpuText);
		
		// On recopie l'ancien tableau
		for(int i=0;i<formulaire->nbInpuText-1;i++){
			tmp[i] = formulaire->tabInpuText[i];
		}
		
		// On ajoute le nouvel élément en fin de tableau
		tmp[formulaire->nbInpuText - 1] = input;
		
		// On remplace l'ancien tableau par le nouveau, sans oublier de libérer la mémoire
		free(formulaire->tabInpuText);
		formulaire->tabInpuText = tmp;
		tmp = NULL;
	}
}

void afficheForm(Form formulaire, int xEcran, int yEcran, float coefZoom){
	
	// On affiche les checkbox
	for(int i=0;i<formulaire.nbCheckbox;i++){
		afficheCheckbox(*(formulaire.tabCheckbox[i]));
	}
	
	// On affiche les radioButtons
	for(int i=0;i<formulaire.nbRadioButton;i++){
		afficheRadioButton(*(formulaire.tabRadioButton[i]));
	}
	
	// On affiche les inputText
	for(int i=0;i<formulaire.nbInpuText;i++){
		//~ printf("%d\n",i);
		//~ printf("%s\n",(formulaire.tabInpuText[i])->string);
		afficheInputTexte(*(formulaire.tabInpuText[i]),xEcran,yEcran,coefZoom);
	}
}

void gereClicForm(Form formulaire, int xSouris, int ySouris){
	
	// On gère les clis des checkbox
	for(int i=0;i<formulaire.nbCheckbox;i++){
		gereClicCheckbox(formulaire.tabCheckbox[i],xSouris,ySouris);
	}
	
	// On gère les clics des radioButtons
	for(int i=0;i<formulaire.nbRadioButton;i++){
		gereClicRadioButton(formulaire.tabRadioButton[i],xSouris,ySouris);
	}
	
	// On gère les clics des inputText
	for(int i=0;i<formulaire.nbInpuText;i++){
		gereSourisInputText(formulaire.tabInpuText[i],xSouris,ySouris);
	}
}

void updateForm(Form formulaire){
	
	for(int i=0;i<formulaire.nbInpuText;i++){
		updateInputText(formulaire.tabInpuText[i]);
	}
	
	for(int i=0;i<formulaire.nbRadioButton;i++){
		updateRadioButton(formulaire.tabRadioButton[i]);
	}
}
