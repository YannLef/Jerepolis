CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(projet VERSION 0.1.0)

# find OpenGL
find_package(OpenGL REQUIRED)
# find GLUT
find_package(GLUT REQUIRED)

# Verify that OpenGL is available
if(NOT ${OPENGL_FOUND})
    message("OPENGL not found")
endif()

if(NOT ${GLUT_FOUND})
    message("GLUT not found")
endif()

# add GLUT and OpenGL include directories
include_directories( 
    ${GLUT_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIRS} 
    ${X11_INCLUDE_DIRS}   
)

add_subdirectory(GfxLib)
add_subdirectory(CustomGfxComponents)
add_subdirectory(Logger)
add_subdirectory(BetterTerminal)
add_subdirectory(Jerepolis)

add_subdirectory(Tests)

add_dependencies(Jerepolis Logger)

SET(SRC
	main.c
	)

ADD_EXECUTABLE(main ${SRC})

target_link_libraries(main
    GfxLib
    CustomGfxComponents
    Logger
    BetterTerminal
    Jerepolis
    ${OPENGL_LIBRARY}
    ${GLUT_LIBRARY}
    m
    X11
)
