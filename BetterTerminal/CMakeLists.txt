CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(BetterTerminal VERSION 0.1.0)

SET(SRC
	src/BetterTerminal.c
	)

SET(HEADERS
	headers/BetterTerminal.h
	)
	
add_library(BetterTerminal ${SRC} ${HEADERS})
