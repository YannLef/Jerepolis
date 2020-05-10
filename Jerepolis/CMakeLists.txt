CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(Jerepolis VERSION 0.1.0)

SET(SRC
	src/Batiment.c
	src/AmeliorationBatiment.c
	src/ModeleBatiment.c
	)

SET(HEADERS
	headers/structures.h
	headers/Batiment.h
	headers/AmeliorationBatiment.h
	headers/ModeleBatiment.h
	)
	
add_library(Jerepolis ${SRC} ${HEADERS})
target_link_libraries(Jerepolis Logger)
