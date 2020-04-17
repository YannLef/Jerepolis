#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "stdbool.h"

/**
 * Structure couleur contenant les nuances de rouge (r), vert (v) et bleu (b)
 * */
typedef struct couleur{
	unsigned char r,v,b; // nuances de rouge, vert, bleu
}couleur;

/**
 * Structure contenant toutes les couleurs utiles de manière récurente
 * On justifie l'utilisation d'une structure et non d'un tableau pour pouvoir se servir des noms et non des indices (plus abstrait mais haut niveau et facile d'utilisation)
 * */
typedef struct couleurTab{
	couleur couleurHomme; // 49, 140, 231
	couleur couleurFemme; // 223, 115, 255
	couleur couleurMenuDeroulant; // 130, 224, 170
	couleur gris180; // 180,180,180
	couleur gris125; //125,125,125
	couleur blanc; // 255, 255, 255
	couleur noir; // 0, 0, 0
	couleur vertPrincipal; // 139,195,74
	couleur bleuEcriture; // 38, 193, 225
	couleur fondPrincipal; // 241, 255, 251
}couleurTab;

/**
 * Structure matérialisant un rectangle, contient de nombreux paramètres pour répondre à tous les besoins
 * */
typedef struct rec{
	int x,y; // coordonnées du centre du rectangle -> on calculera les différents point à partir de là
	int hauteur, largeur; // hauteur et largeur du rectangle
	int epaisseurBordure; // largeur de la bordure
	couleur cInterieur; // couleur de l'intérieur du rectangle
	couleur cBordure; // couleur des contours du rectangle
}rec;

/**
 * Structure matérialisant un lien de parenté entre deux personnes (d'un point de vu graphique)
 * Contient les adresses des deux rectangles à relier
 * */
typedef struct lien{
	rec* r1;
	rec* r2;
}lien;

/**
 * Structure matérialisant un menu déroulant pouvant se dérouler vers la droite
 * */
typedef struct menuDeroulantVersDroite{
	
	// Générales, ne changent pas
	int yBas,yHaut; // Le haut et le bas du menu déroulant à afficher
	int xGauche; // La gauche du menu quand celui ci est entierement ouvert
	int xDroite; // La droite du menu quand celui ci est entierement ouvert
	int etat; // =1 si le menu est ENTIEREMENT ouvert, =0 sinon
	
	// En cours
	int xActuel; // Utile pour l'animation : variable qui évolue et permet de faire évoluer l'affichage
	int xFinal; // Utile pour l'animation : variable à atteindre qui permet de faire évoluer xActuel dans un sens ou dans l'autre
}menuDeroulantVersDroite;

/**
 * Structure contenant des booléens pour chaque touche utilisé dans le programme
 * On justifie l'utilisation d'une structure et non d'un tableau pour pouvoir se servir des noms et non des indices (plus abstrait mais haut niveau et facile d'utilisation)
 * */
typedef struct keyboard{
	bool key_a; // Touche a minuscule
	bool key_A; // Touche A majuscule
	bool key_b; // Touche b minuscule
	bool key_B; // Touche B majuscule
	bool key_c; // Touche c minuscule
	bool key_C; // Touche C majuscule
	bool key_d; // Touche d minuscule
	bool key_D; // Touche D majuscule
	bool key_e; // Touche e minuscule
	bool key_E; // Touche E majuscule
	bool key_f; // Touche f minuscule
	bool key_F; // Touche F majuscule
	bool key_g; // Touche g minuscule
	bool key_G; // Touche G majuscule
	bool key_h; // Touche h minuscule
	bool key_H; // Touche H majuscule
	bool key_i; // Touche i minuscule
	bool key_I; // Touche I majuscule
	bool key_j; // Touche j minuscule
	bool key_J; // Touche J majuscule
	bool key_k; // Touche k minuscule
	bool key_K; // Touche K majuscule
	bool key_l; // Touche l minuscule
	bool key_L; // Touche L majuscule
	bool key_m; // Touche m minuscule
	bool key_M; // Touche M majuscule
	bool key_n; // Touche n minuscule
	bool key_N; // Touche N majuscule
	bool key_o; // Touche o minuscule
	bool key_O; // Touche O majuscule
	bool key_p; // Touche p minuscule
	bool key_P; // Touche P majuscule
	bool key_q; // Touche q minuscule
	bool key_Q; // Touche Q majuscule
	bool key_r; // Touche r minuscule
	bool key_R; // Touche R majuscule
	bool key_s; // Touche s minuscule
	bool key_S; // Touche S majuscule
	bool key_t; // Touche t minuscule
	bool key_T; // Touche T majuscule
	bool key_u; // Touche u minuscule
	bool key_U; // Touche U majuscule
	bool key_v; // Touche v minuscule
	bool key_V; // Touche V majuscule
	bool key_w; // Touche w minuscule
	bool key_W; // Touche W majuscule
	bool key_x; // Touche x minuscule
	bool key_X; // Touche X majuscule
	bool key_y; // Touche y minuscule
	bool key_Y; // Touche Y majuscule
	bool key_z; // Touche z minuscule
	bool key_Z; // Touche Z majuscule
	
	
	bool key_0; // Touche 0
	bool key_1; // Touche 1
	bool key_2; // Touche 2
	bool key_3; // Touche 3
	bool key_4; // Touche 4
	bool key_5; // Touche 5
	bool key_6; // Touche 6
	bool key_7; // Touche 7
	bool key_8; // Touche 8
	bool key_9; // Touche 9
	
	bool key_spacebar; // Touche espace
	bool key_esc; // Touche echape
	bool key_del; // Touche supprimer
	bool key_backspace; // Touche backsapce
	
	bool key_up; // Touche flèche du haut
	bool key_down; // Touche flèche du bas
	bool key_left; // Touche flèche du gauche
	bool key_right; // Touche flèche de droite
	bool key_page_up; // Touche haut de page (flèche peu utilisée)
	bool key_page_down; // Touche bas de page (flèche peu utilisée)
	
	bool key_slash;
}keyboard;

/**
 * Enumération permettant de générer différents affichages sous forme de "pages"
 * */
typedef enum {accueil, newArbre, openArbre, arbre} page;

/**
 * Structure permettant de gérer l'affichage des pages : pFinal permet de ne pas changer de page brusquement en plein milieu d'un traitement.
 * */
typedef struct pages{
	page pActuel;
	page pFinal;
}pages;

/**
 * Structure permettant d'avoir un bouton qui permet de changer de page au clic
 * */
typedef struct boutonChangePage{
	rec rect;
	page pageSuivante;
	char* string;
	couleur cText;
	int epaisseurTrait;
}boutonChangePage;

/**
 * Structure matérialisant un input de type texte (permettant à l'utilisateur de rentrer du texte depuis le programme directement)
 * @author Yann LEFEVRE
 * */
typedef struct inputText{
	bool etat; // définit si l'input est selectionné(=1) ou non(=0)
	int size; // taille actuelle de la chaine entrée
	char* string; // la chaine de caractères écrite par l'utilisateur
	rec rect; // rectangle utilisé pour l'affichage
}inputText;

/**
 * Structure permettant de rassember toutes les informations récupérées concernant un fichier stocké sur l'ordinateur
 * */
typedef struct fichier{
	char nom[50];
	char heure[10];
	char jour[10];
	char mois[15];
	
}fichier;

/**
 * Structure permettant d'avoir un bouton qui permet de changer les fichiers affichés
 * */
typedef struct boutonChangeFichiers{
	rec rect;
	char* string;
	couleur cText;
	int epaisseurTrait;
	int effet; // la valeur dont sera incrémenté le numéro du premier élément affiché
}boutonChangeFichiers;

/**
 * Structure permettant d'avoir un slider (input type range) qui permet de faire évoluer une variable qui lui est affecté en utilisant la souris
 * Ce slider est horizontal et permet donc de changer la valeur en bougeant la souris de droite à gauche
 * */
typedef struct sliderHorizontal{ 
	int x;
	int y;
	int largeur;
	int epaisseurLigne;
	int epaisseurPointeur;
	couleur cLigne;
	couleur cPointeur;
	int* var;
	int min;
	int max;
}sliderHorizontal;

/**
 * Structure permettant d'avoir un slider (input type range) qui permet de faire évoluer une variable qui lui est affecté en utilisant la souris
 * Ce slider est vertical et permet donc de changer la valeur en bougeant la souris de haut en bas
 * */
typedef struct sliderVertical{ 
	int x;
	int y;
	int hauteur;
	int epaisseurLigne;
	int epaisseurPointeur;
	couleur cLigne;
	couleur cPointeur;
	int* var;
	int min;
	int max;
}sliderVertical;

/**
 * Structure permettant de gérer la souris : de savoir en temps réel si les boutons sont appuyés ou relachés
 * */
typedef struct mouse{
	bool clicLeft;
	bool clicRight;
}mouse;

/**
 * Structure permettant de matérialiser un carré
 * */
typedef struct carre{
	int x,y; // coordonnées du centre du rectangle -> on calculera les différents point à partir de là
	int cote; // hauteur et largeur du rectangle
	int epaisseurBordure; // largeur de la bordure
	couleur cInterieur; // couleur de l'intérieur du rectangle
	couleur cBordure; // couleur des contours du rectangle
}carre;

/**
 * Structure matérialisant une checkbox (carré pouvant avoir deux états uniquement : 0 ou 1 en fonction de si elle est cochée ou non)
 * */
typedef struct checkbox{
	bool etat; // l'état signalisant si la checkbox est cochée ou non
	carre square; // Le carré servant de fond pour la checkbox
}checkbox;

/**
 * Structure matérialisant un radiobutton
 * */
typedef struct radiobutton{
	int on; // numéro de l'unique case selectionnée (-1 si aucun)
	int nb; // le nombre de cases
	checkbox* cases; // le tableau contenant les différentes checkbox matérialisant les différentes cases du radiobutton
}radiobutton;

/**
 * Structure matérialisant un input de type select, permettant de choisir parmi différentes options proposées
 * */
typedef struct inputSelect{
	char** options; // La liste des mots représentant les options
	int nbOptions; // Le nombre d'options
	int initial; // La valeur initialement selectionnée
}inputSelect;

/**
 * @brief Structure permettatn de farie des rectangles avec les angles arrondis
 */
typedef struct BoundedRectangle
{
    int x;
    int y;
    int largeur;
    int hauteur;
    int epaisseurBordure;
    couleur cInterieur;
    couleur cBordure;
}BoundedRectangle;

/**
 * @brief Structure matérialisant les messages permettant le communication avec l'assistant
 * */
typedef struct message{
	bool sender; // 0 si assistant, 1 si utilisateur
	char* string; // Le message
}message;

/**
 * Structure permettant d'avoir un bouton qui permet de changer de page au clic
 * */
typedef struct boutonSendMessage{
	rec rect;
	char* string;
	couleur cText;
	int epaisseurTrait;
}boutonSendMessage;

typedef struct Form {
	int nbCheckbox, nbRadioButton, nbInpuText; // Les compteurs d'inputs
	    
    checkbox** tabCheckbox; //tableau des adresses de checkbox
    radiobutton** tabRadioButton; //tableau des adresses de radio button
    inputText** tabInpuText; //tableau des adresses de input text
}Form;


#endif



