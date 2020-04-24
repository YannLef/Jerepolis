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

/**
 * Includes correspondant
 * */
#include "../headers/Mouse.h"

extern Mouse souris;

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
void initMouse(){
	debug("<initMouse> begin");
	
	souris.clicRight = 0;
	souris.clicLeft = 0;
	
	debug("<initMouse> end");
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) UPDATES --------------------
  * ----------------------------------------------------
  * */

void mouseRightDown(){
	debug("<mouseRightDown> begin");
	
	souris.clicRight = 1;
	
	debug("<mouseRightDown> end");
}

void mouseLeftDown(){
	debug("<mouseLeftDown> begin");
	
	souris.clicLeft = 1;
	
	debug("<mouseLeftDown> end");
}

void mouseRightUp(){
	debug("<mouseRightUp> begin");
	
	souris.clicRight = 0;
	
	debug("<mouseRightUp> end");
}

void mouseLeftUp(){
	debug("<mouseLeftUp> begin");
	
	souris.clicLeft = 0;
	
	debug("<mouseLeftUp> end");
}

 /**
  * --------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * --------------------------------------------------
  * */

bool mouseRightIsUp(){
	debug("<mouseRightIsUp> begin");
	debug("<mouseRightIsUp> end");
	return !souris.clicRight;
}

bool mouseLeftIsUp(){
	debug("<mouseLeftIsUp> begin");
	debug("<mouseLeftIsUp> end");
	return !souris.clicLeft;
}

bool mouseRightIsDown(){
	debug("<mouseRightIsDown> begin");
	debug("<mouseRightIsDown> end");
	return souris.clicRight;
}

bool mouseLeftIsDown(){
	debug("<mouseLeftIsDown> begin");
	debug("<mouseRightIsUp> end");
	return souris.clicLeft;
}
