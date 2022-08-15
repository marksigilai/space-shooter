Since this is a OpenGL project using GLUT to render a window, the assignment precheck is failing on the test demo step i believe this is because a new game window cant be rendered while using SSH


from the project pdf, i'm assuming that $INSTALL_DIR will be replaced by a directory name when running the makefile takes the directory name and creates it ie:
    
    cmake -H. - Btmp_cmake - DCMAKE_INSTALL_PREFIX =install_folder
    
running:
    
    install_folder/bin/demo

will run the project file
