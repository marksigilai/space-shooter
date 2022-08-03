#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif


void init(void) 
{
   //Put OpenGL Initializing Code here
   glClearColor(0, 0, 0, 1);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

   //Put Drawing Code Here



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
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);

   //Select Pixel Format Attributes
   glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE);

   //Configure Window
   glutInitWindowSize (640, 800);
   glutInitWindowPosition (100, 100);

   //Create the Window and Set up Rendering Context
   glutCreateWindow ("Space Shooter");


   //Connect callback functions that will respond to events
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   //Configure Rendering Context
   init ();

   //Start listening for events
   glutMainLoop();
   return 0;
}