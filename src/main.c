// gcc main.c axes.o actions.c normale.c lumiere.o switch_blend.o switch_light.o touches.h init.c VM_init.c -lm -lGL -lGLU -lglut -o Playmobil

#include "init.h"
//#include "axes.h"
#include "VM_init.h"
#include "normale.h"
#include "ground.h"

#include <math.h>

int window = 0;
GLuint blend = 0;
GLuint light = 0;

GLfloat groundSize = 4.0f;

GLfloat rotate_x_sphere = 0.0f;
GLfloat rotate_y_sphere = 0.0f;

GLfloat x_cam = 0;
GLfloat y_cam = 0;
GLfloat z_cam = 0;

int time = 0;
int frames = 0, fps = 0, followingTime, timeSinceLastCalculation = 0, FPSCalculationFrequency = 100;
GLfloat angle = 0.0f, angularSpeed = 45;

GLvoid Modelisation()
{
  VM_init();
  glRotatef(rotate_x_sphere, 1.0, 0.0, 0.0);
  glRotatef(rotate_y_sphere, 0.0, 1.0, 0.0);

  glPushMatrix();{
    groundCreate();
  }
  glPopMatrix();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  return notre_init(argc, argv, &Modelisation);
}
