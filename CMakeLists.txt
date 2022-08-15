cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lGLU -lglut -lGL")

project(space_shooter LANGUAGES CXX)

add_executable(space_shooter app/main.cpp lib/battleship.cpp lib/game.cpp lib/star.cpp lib/obstacle.cpp lib/bullet.cpp)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(space_shooter ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

install(TARGETS main RUNTIME DESTINATION bin)