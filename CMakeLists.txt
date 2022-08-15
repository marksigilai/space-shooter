cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(space_shooter LANGUAGES CXX)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lGLU -lglut -lGL")
#set(INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin/demo")

install(DIRECTORY DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_INSTALL_PREFIX}/bin/")


add_executable(space_shooter app/main.cpp lib/battleship.cpp lib/game.cpp lib/star.cpp lib/obstacle.cpp lib/bullet.cpp)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(space_shooter ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )


#file(MAKE_DIRECTORY ${INSTALL_DIR})


file(WRITE demo
    "#!/usr/bin/env bash
    # Note that './main' is relative from whatever directory you are in
    # Use just main assuming the install prefix is in your bath
    # Or use $<TARGET_FILE:main> 
    # Or maybe ${CMAKE_INSTALL_PREFIX}/bin/main
    ./space_shooter options
")


# add execute permissions
#file(
#    COPY ${CMAKE_INSTALL_PREFIX}/bin/demo
#    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
#    FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#)

install(PROGRAMS demo DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")


