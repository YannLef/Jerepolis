#ifndef KEYBOARD_H
#define KEYBOARD_H

 /**
  * -------------------------------------------------
  * -------------------- SUMMARY --------------------
  * -------------------------------------------------
  * 0) INTRODUCTION    - line ...
  * 1) INITIALISATION  - line ...
  * 2) EVENTS          - line ...
  * 2) TESTS           - line ...
  * 
  * 
*/

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
void initKeyboard(void);

 /**
  * ---------------------------------------------------
  * -------------------- 2) EVENTS --------------------
  * ---------------------------------------------------
  * */

void keyDown(unsigned  char key, int x, int y);
void keyUp(unsigned  char key, int x, int y);
void specialKeyDown(int key, int x, int y);
void specialKeyUp(int key, int x, int y);

 /**
  * ---------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * ---------------------------------------------------
  * */
  
bool keyIsDown(bool key);
bool keyIsUp(bool key);

#endif
