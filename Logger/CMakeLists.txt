CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(Logger VERSION 0.1.0)

SET(SRC
	src/Logger.c
	src/Image.c
	)

SET(HEADERS
	headers/Logger.h
	headers/Image.h
	)
	
add_library(Logger ${SRC} ${HEADERS})
