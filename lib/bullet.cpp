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
    isLive_ = true;
}

void Bullet::moveUp(){

    if( y_ <= glutGet(GLUT_WINDOW_HEIGHT)){
        y_ += 5;
    } 
    else {
        isLive_ = false;
    }

}

void Bullet::draw(){

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2i(x_ + 1, y_ + 6);
        glVertex2i(x_ + 1, y_ - 6);
        glVertex2i(x_ - 1, y_ - 6);
        glVertex2i(x_ - 1, y_ + 6);
    glEnd();

}

int Bullet::getX(){
    return x_;
}
int Bullet::getY(){
    return y_;
}

bool Bullet::isLive(){
    return isLive_;
}

void Bullet::destroy(){
    isLive_ = false;
}