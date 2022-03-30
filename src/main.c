// gcc main.c axes.o actions.c normale.c lumiere.o switch_blend.o switch_light.o touches.h init.c VM_init.c -lm -lGL -lGLU -lglut -o Playmobil

#include "init.h"
#include "VM_init.h"
#include "normale.h"
#include "ground.h"
#include "playmobil.h"

#include <math.h>

int window = 0;
GLuint blend = 0;
GLuint light = 0;

GLfloat groundSize = 4.0f;

GLfloat rotate_x_sphere = 0.0f;
GLfloat rotate_y_sphere = 0.0f;

// Gestion de la caméra
GLfloat x_cam = 0.0f;
GLfloat y_cam = 0.0f;
GLfloat z_cam = -10.0f;

GLfloat rotate_x_cam = 15.0f;
GLfloat rotate_y_cam = 0.0f;
GLfloat rotate_z_cam = 0.0f;

// Gestion du playmobil
GLfloat play_x = 0.0f;
GLfloat play_y = 0.0f;
GLfloat play_z = 0.0f;

GLfloat play_rotation = 0.0f;

GLfloat play_member_rotate_x = 0.0f;

int time = 0;
int frames = 0, fps = 0, followingTime, timeSinceLastCalculation = 0, FPSCalculationFrequency = 100;
GLfloat angle = 0.0f, angularSpeed = 45;
GLfloat play_speed = 0.1f;
unsigned int updateMovement = 0;

GLvoid Modelisation()
{
  VM_init();

  // Calcul des FPS
  frames++;
  followingTime = glutGet(GLUT_ELAPSED_TIME);
  int timeBetweenTwoFrames = followingTime - time;
  timeSinceLastCalculation += timeBetweenTwoFrames;

  if (timeSinceLastCalculation > FPSCalculationFrequency)
  {
    timeSinceLastCalculation = 0;
    fps = frames * 1000 / FPSCalculationFrequency;
    frames = 0;
    updateMovement = 1;

    GLfloat realSpeed = angularSpeed / (float)fps;
    time = followingTime;
    angle += realSpeed;
  }
  else
  {
    updateMovement = 0;
  }

  glTranslatef(x_cam, y_cam, z_cam);
  glRotatef(rotate_x_cam, 1.0, 0.0, 0.0);
  glRotatef(rotate_y_cam, 0.0, 1.0, 0.0);
  glRotatef(rotate_z_cam, 0.0, 0.0, 1.0);

  glPushMatrix();
  {
    // groundCreate();
    playmobil(1.0f);
  }
  glPopMatrix();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  time = glutGet(GLUT_ELAPSED_TIME);
  return notre_init(argc, argv, &Modelisation);
}
