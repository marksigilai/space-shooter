#include "../include/star.hpp"
#include <random>
#include <GLUT/glut.h>


Star::Star(){   
    x_ = 0;
    y_ = 0;
}

void Star::draw(){

    glColor3f(0.0, 1.0, 1.0);
	glLineWidth(1); 

	glBegin(GL_POINTS);
      glVertex2i( x_, y_ );
	glEnd();

}

Star Star::init(){
    x_ = rand() % (glutGet(GLUT_WINDOW_WIDTH) + 1);
    y_ = rand() % (glutGet(GLUT_WINDOW_HEIGHT) + 1);

    return *this;
}

void Star::animate(){
    --y_;

    if (y_ < 0){
        y_ = glutGet(GLUT_WINDOW_HEIGHT);
    }
}


