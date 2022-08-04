#include "../include/battleship.hpp"

#ifdef __APPLE__
   #include <GLUT/glut.h>
   #include <stdlib.h>
#else
   #include <GL/glut.h>
#endif

#include <iostream>

Battleship::Battleship(){
    x_ = 0;
    y_ = 0;
}

void Battleship::draw(){

	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(0.5); 

	glBegin(GL_TRIANGLES);
      glVertex2i(x_ + 15, y_);
      glVertex2i(x_, y_ + 15);
      glVertex2i(x_ - 15, y_);
	glEnd();

}

void Battleship::init(){
    x_ = glutGet(GLUT_WINDOW_WIDTH) / 2;
    y_ = 100;
}

void Battleship::moveLeft(){

    if( x_ > 0){
        x_ -= 10;
    }
}

std::vector<Bullet>& Battleship::getBullets(){
    return bullets_;
}

void Battleship::moveRight(){

    if( x_ < glutGet(GLUT_WINDOW_WIDTH)){
        x_ += 10;
    }
}

//adds a new bullet to the bullets vector with the current coordinates of the battleship
void Battleship::shoot(){

    bullets_.push_back(Bullet(x_, y_));
}
