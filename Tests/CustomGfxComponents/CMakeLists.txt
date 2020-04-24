CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(test_CustomGfxComponents VERSION 0.1.0)

SET(SRC
	src/test_Carre.c
	)

SET(HEADERS
	../../../CustomGfxComponents/headers/structures.h
	headers/test_Carre.h
	)
	
add_library(test_CustomGfxComponents ${SRC} ${HEADERS})
