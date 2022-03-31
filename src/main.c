/*
 * main.c
 *  
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 * 	Ce programme génère la modélisation d'un Playmobil et de son environnement
 */


#include "init.h"
#include "VM_init.h"
#include "normale.h"
#include "ground.h"
#include "playmobil.h"
#include "lumiere.h"
#include "wall.h"

#include <math.h>

int window = 0;
GLuint blend = 0;
GLuint light = 0;

GLfloat ambienteLight = 1.0f;

GLfloat groundSize = 50.0f;

GLfloat rotate_x_sphere = 0.0f;
GLfloat rotate_y_sphere = 0.0f;

// Gestion de la caméra
GLfloat x_cam = 0.0f;
GLfloat y_cam = 0.0f;
GLfloat z_cam = -40.0f;

GLfloat rotate_x_cam = 15.0f;
GLfloat rotate_y_cam = 0.0f;
GLfloat rotate_z_cam = 0.0f;

// Gestion du playmobil
GLfloat play_x = 0.0f;
GLfloat play_y = 1.0f;
GLfloat play_z = 0.0f;

GLfloat play_rotation = 0.0f;

GLfloat play_member_rotate_x = 0.0f;

// Réplique autonome du playmobil
GLfloat play_x_auto = 10.0f;
GLfloat play_y_auto = 1.0f;
GLfloat play_z_auto = 0.0f;

GLfloat play_rotation_auto = 0.0f;

GLfloat play_member_rotate_x_auto = 0.0f;
int rotation_direction_auto = 1;

int direction_auto = 1;

int time = 0;
int frames = 0, fps = 0, followingTime, timeSinceLastCalculation = 0, FPSCalculationFrequency = 100;
GLfloat play_speed = 3.0f;
unsigned int updateMovement = 0;

GLvoid Modelisation()
{
  VM_init();

  generer_lumiere();

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

    GLfloat realSpeed = play_speed / (float)fps;
    time = followingTime;

    // Calcul des mouvements du playmobil autonome
    if (play_z_auto < -15.0f)
    {
      direction_auto = 1;
    }
    else if( play_z_auto > 15.0f){
      direction_auto = -1;
    }

    play_z_auto += realSpeed * direction_auto;
      if (play_member_rotate_x_auto > 45 || play_member_rotate_x_auto < -45)
        rotation_direction_auto = rotation_direction_auto * -1;
      play_member_rotate_x_auto += 10 * rotation_direction_auto;
  }

  glTranslatef(x_cam, y_cam, z_cam);
  glRotatef(rotate_x_cam, 1.0, 0.0, 0.0);
  glRotatef(rotate_y_cam, 0.0, 1.0, 0.0);
  glRotatef(rotate_z_cam, 0.0, 0.0, 1.0);

  glPushMatrix();
  {
    groundCreate();
    createWall();
    playmobil(1.0f);
    playmobil_auto(1.0f);
  }
  glPopMatrix();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  time = glutGet(GLUT_ELAPSED_TIME);
  return notre_init(argc, argv, &Modelisation);
}
