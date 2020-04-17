CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(CustomGfxComponents VERSION 0.1.0)

SET(SRC
	src/Carre.c
	src/Checkbox.c
	src/DropDownMenuRight.c
	src/Mouse.c
	src/SliderHorizontal.c
	src/SliderVertical.c
	src/Rectangle.c
	src/BoundedRectangle.c
	src/Keyboard.c
	src/Couleur.c
	src/RadioButton.c
	src/Formulaire.c
	src/Page.c
	src/Conversation.c
	src/InputText.c
	src/Navbar.c
	src/FileExplorer.c
	src/ButtonChangeFile.c
	src/ButtonChangePage.c
	src/ButtonSendMessage.c
	)

SET(HEADERS
	headers/structures.h
	headers/Carre.h
	headers/Checkbox.h
	headers/DropDownMenuRight.h
	headers/Mouse.h
	headers/SliderHorizontal.h
	headers/SliderVertical.h
	headers/Rectangle.h
	headers/BoundedRectangle.h
	headers/Keyboard.h
	headers/Couleur.h
	headers/RadioButton.h
	headers/Formulaire.h
	headers/Page.h
	headers/Conversation.h
	headers/InputText.h
	headers/Navbar.h
	headers/FileExplorer.h
	headers/ButtonChangeFile.h
	headers/ButtonChangePage.h
	headers/ButtonSendMessage.h
	)
	
add_library(CustomGfxComponents ${SRC} ${HEADERS})
