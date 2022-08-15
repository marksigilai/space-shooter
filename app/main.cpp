
#include <GL/freeglut.h>
#include <stdlib.h>
#include <iostream>
#include "../include/game.hpp"


int V_WIDTH = 640;
int V_HEIGHT = 800;

Game game;


void renderTimer(int);
void dropTimer(int t);


void init(void) 
{

   //Select Pixel Format Attributes
   glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE);

   //Configure Window
   glutInitWindowSize (V_WIDTH, V_HEIGHT);
   glutInitWindowPosition (100, 100);

   //Create the Window and Set up Rendering Context
   glutCreateWindow ("Space Shooter");

   //Put OpenGL Initializing Code here
   glClearColor(0, 0, 0, 1);
   glMatrixMode (GL_PROJECTION);
   gluOrtho2D (0.0, V_WIDTH, 0.0, V_HEIGHT);

   //game.init();
}

void display(void)
{  
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //Put Drawing Code Here
   if(!game.isGameOver()){
      game.detectCollisions();
      game.draw();

   }
   else{
      game.showMenu();
   }

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   //Put Resizing Code Here

}

void keyboard(unsigned char key, int x, int y)
{

   switch (key) {
      case 27:
      case 'q':
      case 'Q':
         exit(0); 
         break;
      case 'a':
      case 'A':
      case 75:
         game.getBattleShip().moveLeft();
         break;
      case 'd':
      case 'D':
      case GLUT_KEY_RIGHT:
      case 77:
         game.getBattleShip().moveRight();
         break;
      case ' ':
         game.getBattleShip().shoot();
         break;
      case 13:
         game.start();
         break;
   }
}


int main(int argc, char** argv)
{

   glutInit(&argc, argv);

   //Configure Rendering Context
   init();

   //Connect callback functions that will respond to events
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(1000, renderTimer, 0);


   glutTimerFunc(1000, dropTimer, 3000);

   //Start listening for events
   glutMainLoop();

   return 0;
}

//rerenders the page every 1000ms
void renderTimer(int t){

   glutPostRedisplay();

   glutTimerFunc(1, renderTimer, 0);

}

//drops a new obstacle every 3 seconds
void dropTimer(int t){

   if(!game.isGameOver()){

      game.dropObstacle();

   }
   glutTimerFunc(t, dropTimer, t - 2);
}