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
#include "../headers/Page.h"
#include "../headers/ButtonChangePage.h"
#include "../headers/ButtonChangeFile.h"

/**
 * Includes Jerepolis
 * */
#include "../../Jerepolis/headers/structures.h"
#include "../../Jerepolis/headers/AmeliorationBatiment.h"
#include "../../Jerepolis/headers/RecrutementUnite.h"
#include "../../Jerepolis/headers/Batiment.h"
#include "../../Jerepolis/headers/Simplifications.h"
#include "../../Jerepolis/headers/Evenement.h"

/**
 * Includes correspondant
 * */
#include "../headers/FileExplorer.h"

extern CouleurTab c; // Synchronise le clavier avec les autres fichiers

void recupereInfosFichiersDansDossier(char* cheminDossier, Fichier** fichiers, int* nombreFichiers){
	debug("<recupereInfosFichiersDansDossier> begin");
	
	// Formule la commande
	int taille = strlen("ls ") + strlen(cheminDossier) + strlen(" -lt>infosFichiers.txt") + 1;
	char* commande = (char*) malloc(sizeof(char)*taille);
	strcpy(commande,"ls ");
	strcat(commande, cheminDossier);
	strcat(commande," -lt>infosFichiers.txt");
	// Execute la commande
	system(commande);
				
	// Ouvre le fichier contenant le résultat de la commande ls exécutée précedement
	FILE* f = fopen("infosFichiers.txt","rt");
	

	char* tmp= (char*)malloc(sizeof(char)*50); // Stockera le nom des fichiers une fois récupéres
	strcpy(tmp,"");

	int tmpInt = 0;
	fscanf(f,"total %d", &tmpInt); // Pour la première ligne
	
	
	if(tmpInt != 0){
		int cpt =  0; // Permet de compter les lignes
		while(feof(f) == 0){ // Boucle jusqu'à ce que la fin du fichier soit atteinte
			
			if(*fichiers != NULL){ // On regarde si le tableau est déjà initilisé ou non
				// Si il est déjà initialisé on doit l'agrandir pour accueillir la prochaine ligne
				Fichier* fichierTmp = (Fichier*)malloc(sizeof(Fichier)*(cpt+1)); // On crée un tableau temporaire de 1 case de plus que l'ancient
				for(int i=0; i<cpt; i++){ // On recopie toutes les informations déjà récupérées dans le nouveau tableau
					strcpy(fichierTmp[i].nom,(*fichiers)[i].nom);
					strcpy(fichierTmp[i].heure,(*fichiers)[i].heure);
					strcpy(fichierTmp[i].jour,(*fichiers)[i].jour);
					strcpy(fichierTmp[i].mois,(*fichiers)[i].mois);
				}
				free(*fichiers); // On libère l'ancien tableau, devenu obsolète
				// On redirige le tableau officiel vers le nouveau tableau
				*fichiers = fichierTmp;
				fichierTmp = NULL;
			}else{ // Si il n'est pas encore initialisé on l'initialise pour qu'il accueille la première donnée
				*fichiers = (Fichier*)malloc(sizeof(Fichier)*(cpt+1));
			}
			
			// Pour chaque ligne on passe les 5 premiers termes (inutiles pour nous) renvoyés par la commande système.
			for(int i=0;i<5;i++)
				fscanf(f, "%s ", tmp);
				
			fscanf(f, "%s ", tmp); // On récupère terme de chaque ligne qui correspond au mois de fichier.
			strcpy((*fichiers)[cpt].mois, tmp);
				
			fscanf(f, "%s ", tmp); // On récupère terme de chaque ligne qui correspond au jour de fichier.
			strcpy((*fichiers)[cpt].jour, tmp);
				
			fscanf(f, "%s ", tmp); // On récupère terme de chaque ligne qui correspond à l'heure de fichier.
			strcpy((*fichiers)[cpt].heure, tmp);

			fscanf(f, "%[^\n]\n", tmp); // On récupère le dernier terme de chaque ligne qui correspond au nom de fichier.
			strcpy((*fichiers)[cpt].nom, tmp);
			
			
			cpt++; // on incrémente le compteur
		}
		*nombreFichiers = cpt;
	}
	
	free(tmp); // On libère la chaine de caractère tmeporaire
	free(commande); // On libère la chaine de caractère utilisée pour exécuter la commande
	fclose(f);	// On ferme le fichier

	debug("<recupereInfosFichiersDansDossier> end");
}

void afficheExplorateurDeFichiers(Fichier* listeFichiers, int nombreFichiers, int debut){
	debug("<afficheExplorateurDeFichiers> begin");
	
	int cpt=debut;
	for(int i=648; i>=0;i=i-72){
		DonneesImageRGB* fondExplorer = lisBMPRGB("../Jerepolis/ressources/images/FondExplorateurFichier.bmp");
		if(fondExplorer != NULL){ ecrisImage(0, i, fondExplorer->largeurImage, fondExplorer->hauteurImage, fondExplorer->donneesRGB);}
		if(cpt < nombreFichiers){
			couleurCourante(c.blanc.r,c.blanc.v,c.blanc.b);
			epaisseurDeTrait(3);
			afficheChaine(listeFichiers[cpt].nom, 25, 90, i+25);
			int taille = strlen(listeFichiers[cpt].mois) + strlen(listeFichiers[cpt].jour) + strlen(listeFichiers[cpt].heure) + 3; // + 4 pour avoir la place de mettre les / et le \0
			char* date = (char*) malloc(sizeof(char)*taille);
			strcpy(date,listeFichiers[cpt].mois);
			strcat(date,"/");
			strcat(date,listeFichiers[cpt].jour);
			strcat(date,"/");
			strcat(date,listeFichiers[cpt].heure);
			afficheChaine(date, 25, 780, i+25);
			cpt++;
		}
	}
	
	DonneesImageRGB* menuExplorer = lisBMPRGB("../Jerepolis/ressources/images/menuExplorer.bmp");
	if(menuExplorer != NULL){ ecrisImage(0, 0, menuExplorer->largeurImage, menuExplorer->hauteurImage, menuExplorer->donneesRGB);}
	
	debug("<afficheExplorateurDeFichiers> end");
}

void gereSourisSelectionneFichier(int x, int y, Pages* pActuel, int* debutExplorer, int nombreFichiers, Fichier* fichiers, char** nomSave){
	debug("<gereSourisSelectionneFichier> begin");
	
	if(pActuel->pActuel == pActuel->pFinal){
		if(x > 0 && x < 384 && y > 0 && y < 72){ // Flèche gauche
			if(*debutExplorer - 9 >= 0){
				*debutExplorer = *debutExplorer - 9;
			}
		}else if(x > 384 && x < 768 && y > 0 && y < 72){ // Quitter
			pActuel->pFinal = accueil;
		}else if(x > 768 && x < 1152  && y > 0 && y < 72){ // Flèche droite
			if(*debutExplorer + 9 < nombreFichiers){
				*debutExplorer = *debutExplorer + 9;
			}
		}
	}
	
	int cpt = *debutExplorer;
	for(int i=648; i>=0;i=i-72){
		if(x > 0 && x < 1152 && y > i && y < i+72){
			if(cpt < nombreFichiers){
				*nomSave = malloc(sizeof(char)*200);
				strcpy(*nomSave, "./sauvegardes/");
				strcat(*nomSave, fichiers[cpt].nom);
			}
		}
		cpt++;
	}
	
	
	debug("<gereSourisSelectionneFichier> end");
}
