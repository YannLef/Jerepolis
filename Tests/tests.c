#include <stdlib.h>
#include <stdio.h>

/**
 * Includes MinUnit
 * */
#include "minunit/minunit.h"

#include "CustomGfxComponents/src/test_Carre.c"

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_check);
}

int main(){
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	
	return 0;
}
