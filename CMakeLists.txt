cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)

project(space_shooter LANGUAGES CXX)

target_link_libraries(space_shooter "-framework OpenGL" "-framework GLUT")

add_executable(space_shooter app/main.cpp lib/battleship.cpp lib/game.cpp lib/star.cpp lib/obstacle.cpp lib/bullet.cpp)
