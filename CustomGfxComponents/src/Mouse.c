#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Mouse.h"

extern mouse souris;

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
void initMouse(){
	souris.clicRight = 0;
	souris.clicLeft = 0;
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) UPDATES --------------------
  * ----------------------------------------------------
  * */

void mouseRightDown(){
	souris.clicRight = 1;
}

void mouseLeftDown(){
	souris.clicLeft = 1;
}

void mouseRightUp(){
	souris.clicRight = 0;
}

void mouseLeftUp(){
	souris.clicLeft = 0;
}

 /**
  * --------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * --------------------------------------------------
  * */

bool mouseRightIsUp(){
	return !souris.clicRight;
}

bool mouseLeftIsUp(){
	return !souris.clicLeft;
}

bool mouseRightIsDown(){
	return souris.clicRight;
}

bool mouseLeftIsDown(){
	return souris.clicLeft;
}
