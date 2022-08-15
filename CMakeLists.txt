cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(space_shooter LANGUAGES CXX)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lGLU -lglut -lGL")

install(DIRECTORY DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_INSTALL_PREFIX}/bin/")

add_executable(space_shooter app/main.cpp lib/battleship.cpp lib/game.cpp lib/star.cpp lib/obstacle.cpp lib/bullet.cpp)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(space_shooter ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

file(WRITE demo "
    #! /usr/bin/env bash

    # Print an error message and exit.
    panic()
    {
        echo "ERROR: $@"
        exit 1
    }

    # Get the directory in which the currently running script is located.
    cmd_dir=$(dirname "$0") || panic "cannot determine command directory"

    hello_program="$cmd_dir/hello"
    goodbye_program="$cmd_dir/goodbye"

    echo "Running hello program"
    $hello_program || panic "hello program failed"

    echo "Running goodbye program"
    $goodbye_program || panic "goodbye program failed"

")

install(PROGRAMS demo DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")


