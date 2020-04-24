/**
 * Includes Classiques
 * */
#include <stdlib.h> 
#include <stdio.h>

/**
 * Includes MinUnit
 * */
#include "../../minunit/minunit.h"

/**
 * Includes CustomGfxComponents
 * */
#include "../../../CustomGfxComponents/headers/structures.h"

MU_TEST(test_check){
	mu_check(5 == 7);
}
