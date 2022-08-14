#include "../include/obstacle.hpp"

#include <GLUT/glut.h>

#include <random>

Obstacle::Obstacle(){
    radius_ = rand() % 40 + 20;
    x_ = rand() % glutGet(GLUT_WINDOW_WIDTH);
    y_ = glutGet(GLUT_WINDOW_HEIGHT) + 70;
    speed_ = 2;
    isDropping_ = false;
}

void Obstacle::reset(){
    radius_ = rand() % 30 + 30;
    x_ = rand() % glutGet(GLUT_WINDOW_WIDTH);
    y_ = glutGet(GLUT_WINDOW_HEIGHT) + 60;
}


void Obstacle::draw(){
    
    if(isDropping()){
        
        double pi = 3.142;

        glColor3f(0.3, 0.3, 0.3);
        glLineWidth(2.5); 
        
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x_, y_);
            for (int i = 0; i <= 20; ++i)   {
                glVertex2f ((x_ + ((radius_) * cos(i * double(2) * pi / 20))), (y_ + ((radius_) * sin(i * double(2) * pi / 20))));
            }
        glEnd();

        //draw fade on obstacle
        float f = 0.4;
        
        for(int j = 5; j <= 30; j+=3){
            glColor3f(f, f, f);
            
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(x_, y_);
                for (int i = 0; i <= 20; ++i)   {
                    glVertex2f ((x_ + ((radius_ - j) * cos(i * double(2) * pi / 20))), (y_ + ((radius_ - j) * sin(i * double(2) * pi / 20))));
                }
            glEnd();
            f+= 0.1;
       }


        glColor3f(1, 1, 1);
        
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x_, y_);
            for (int i = 0; i <= 20; ++i)   {
                glVertex2f ((x_ + ((5) * cos(i * double(2) * pi / 20))), (y_ + ((5) * sin(i * double(2) * pi / 20))));
            }
        glEnd();
        f+= 0.1;

    }
}

//if obstacle has dropped out of view, redrop
void Obstacle::drop(){
    isDropping_ = true;
    y_ -= speed_;

    if(y_ <= 0){
        increaseSpeed();
        reset();
    }
}

//max drop rate is 5
void Obstacle::increaseSpeed(){
    int maxSpeed = 50;
    
    if(speed_ < maxSpeed){
        speed_ += 1;
    } else{
        speed_ = 5;
    }
}

void Obstacle::destroy(){
    x_ = 0;
    y_ = 0;
    radius_ = 0;
    //speed_ = 1;
    isDropping_ = false;
}

bool Obstacle::isDropping(){
    return isDropping_;
}

int Obstacle::getRadius(){
    return radius_;
}

int Obstacle::getX(){
    return x_;
}

int Obstacle::getY(){
    return y_;
}