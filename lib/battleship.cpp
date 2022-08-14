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

    //wings
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(0.5); 

    glBegin(GL_TRIANGLES);
        glVertex2i(x_, y_ + 10);
        glVertex2i(x_ - 20, y_ - 20);
        glVertex2i(x_ + 20, y_ - 20);
	glEnd();


    //body
	glColor3f(0.5, 0, 0.9);
	glLineWidth(0.5); 

	glBegin(GL_POLYGON);
        glVertex2i(x_, y_ + 30);
        glVertex2i(x_ + 15, y_);
        glVertex2i(x_ + 10, y_ - 20);
        glVertex2i(x_ - 10, y_ - 20);
        glVertex2i(x_ - 15, y_);
	glEnd();

    glColor3f(0.7, 0.8, 0.9);
	glLineWidth(0.5); 

	glBegin(GL_POLYGON);
        glVertex2i(x_, y_ + 24);
        glVertex2i(x_ + 11, y_);
        glVertex2i(x_ + 8, y_ - 16);
        glVertex2i(x_ - 8, y_ - 16);
        glVertex2i(x_ - 11, y_);
	glEnd();

    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_TRIANGLES);
        glVertex2i(x_, y_ + 20);
        glVertex2i(x_ + 5, y_ + 5);
        glVertex2i(x_ - 5, y_ + 5);
	glEnd();


    //flames
	glColor3f( 0.9, 0.6, 0.0);
	glLineWidth(0.5); 

    glBegin(GL_QUADS);
        glVertex2i(x_ - 12, y_ - 35);
        glVertex2i(x_ - 12, y_ - 22);
        glVertex2i(x_ - 20, y_ - 35);
        glVertex2i(x_ - 20, y_ - 22);
	glEnd();

    glBegin(GL_QUADS);
        glVertex2i(x_ + 20, y_ - 35);
        glVertex2i(x_ + 20, y_ - 22);
        glVertex2i(x_ + 12, y_ - 35);
        glVertex2i(x_ + 12, y_ - 22);
	glEnd();

}

void Battleship::init(){
    x_ = glutGet(GLUT_WINDOW_WIDTH) / 2;
    y_ = 100;
}

void Battleship::moveLeft(){

    if (x_ > 0){
        for(int i = 0; i < 10; ++i){
            x_ -= 2;
        }
    }
}

std::vector<Bullet>& Battleship::getBullets(){
    return bullets_;
}

void Battleship::moveRight(){

    if ( x_ < glutGet(GLUT_WINDOW_WIDTH)){
        for(int i = 0; i < 10; ++i){
            x_ += 2;
        }
    }
}

//adds a new bullet to the bullets vector with the current coordinates of the battleship
void Battleship::shoot(){

    int bullets = 3;

    if (getLiveBulletsCount() < bullets){
        bullets_.push_back(Bullet(x_, y_));
    }
    
}

int Battleship::getLiveBulletsCount(){
    
    int liveBullets = 0;
    for (int i = 0; i < bullets_.size(); ++i) {
        if(bullets_[i].isLive()){
            ++liveBullets;
        }
    }
    return liveBullets;
}


int Battleship::getX(){
    return x_;
}

int Battleship::getY(){
    return y_;
}

int Battleship::getWidth(){
    return 20;
}

int Battleship::getHeight(){
    return 30;
}