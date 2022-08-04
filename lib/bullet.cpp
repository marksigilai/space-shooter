#include "../include/bullet.hpp"
#ifdef __APPLE__
   #include <GLUT/glut.h>
   #include <stdlib.h>
#else
   #include <GL/glut.h>
#endif


Bullet::Bullet(int x, int y){

    x_ = x;
    y_ = y;
}

void Bullet::moveUp(){

    if( y_ < glutGet(GLUT_WINDOW_HEIGHT)){
        y_ += 5;
    }
}

void Bullet::draw(){

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2i(x_ + 2, y_ + 2);
        glVertex2i(x_ - 2, y_ - 2);
        glVertex2i(x_ - 2, y_ + 2);
        glVertex2i(x_ + 2, y_ - 2);
    glEnd();

}

