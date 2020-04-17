CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(GfxLib VERSION 0.1.0)

SET(SRC
	src/BmpLib.c
	src/ErreurLib.c
	src/ESLib.c
	src/GfxLib.c
	src/OutilsLib.c
	src/SocketLib.c
	src/ThreadLib.c
	src/VectorLib.c
	src/WavLib.c
	)

SET(HEADERS
	headers/BmpLib.h
	headers/ErreurLib.h
	headers/ESLib.h
	headers/GfxLib.h
	headers/OutilsLib.h
	headers/SocketLib.h
	headers/ThreadLib.h
	headers/VectorLib.h
	headers/WavLib.h
	)
	
add_library(GfxLib ${SRC} ${HEADERS})
