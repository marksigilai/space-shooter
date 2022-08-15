cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lGLU -lglut -lGL")
#set(INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin/demo")

project(space_shooter LANGUAGES CXX)

add_executable(demo app/main.cpp lib/battleship.cpp lib/game.cpp lib/star.cpp lib/obstacle.cpp lib/bullet.cpp)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(demo ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

install(DIRECTORY DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

#file(MAKE_DIRECTORY ${INSTALL_DIR})

install(PROGRAMS tmp_cmake/demo DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
