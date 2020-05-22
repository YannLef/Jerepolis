CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(Jerepolis VERSION 0.1.0)

SET(SRC
	src/Batiment.c
	src/AmeliorationBatiment.c
	src/ModeleBatiment.c
	src/Senat.c
	src/Ferme.c
	src/Entrepot.c
	src/Mine.c
	src/Carriere.c
	src/Scierie.c
	src/Temple.c
	src/Caserne.c
	src/Simplifications.c
	src/RecrutementUnite.c
	src/Accueil.c
	src/Attaque.c
	src/Ennemi.c
	src/Evenement.c
	)

SET(HEADERS
	headers/structures.h
	headers/Batiment.h
	headers/AmeliorationBatiment.h
	headers/ModeleBatiment.h
	headers/Senat.h
	headers/Ferme.h
	headers/Entrepot.h
	headers/Mine.h
	headers/Carriere.h
	headers/Scierie.h
	headers/Temple.h
	headers/Caserne.h
	headers/Simplifications.h
	headers/RecrutementUnite.h
	headers/Accueil.h
	headers/Attaque.h
	headers/Ennemi.h
	headers/Evenement.h
	)
	
add_library(Jerepolis ${SRC} ${HEADERS})
target_link_libraries(Jerepolis CustomGfxComponents)
target_link_libraries(Jerepolis GfxLib)
