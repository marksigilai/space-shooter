#include "../include/obstacle.hpp"

#ifdef __APPLE__
   #include <GLUT/glut.h>
   #include <stdlib.h>
#else
   #include <GL/glut.h>
#endif

#include <random>

Obstacle::Obstacle(){
    x_ = 0;
    y_ = 0;
    radius_ = 0;
    dropRate_ = 1;
    isDropping_ = false;
}

void Obstacle::init(){
    x_ = rand() % glutGet(GLUT_WINDOW_WIDTH);
    y_ = glutGet(GLUT_WINDOW_HEIGHT);
    radius_ = rand() % 30 + 30;
}


void Obstacle::draw(){
    
    if(isDropping()){
        
        double pi = 3.142;

        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(0.5); 
        
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x_, y_);
            for (int i = 0; i <= 20; i++)   {
                glVertex2f ((x_ + (radius_ * cos(i * double(2) * pi / 20))), (y_ + (radius_ * sin(i * double(2) * pi / 20))));
            }
        glEnd();

    }
}

//if obstacle has dropped out of view, redrop
void Obstacle::drop(){
    isDropping_ = true;
    y_ -= dropRate_;

    if(y_ <= 0){
        increaseDroprate();
        init();
    }
}

//max drop rate is 5
void Obstacle::increaseDroprate(){
    
    if(dropRate_ < 5){
        dropRate_ += 1;
    } else{
        dropRate_ = 1;
    }
}

bool Obstacle::isDropping(){
    return isDropping_;
}