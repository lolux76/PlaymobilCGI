#include "actions.h"
#include <stdio.h>

extern GLfloat rotate_x_cam;
extern GLfloat rotate_y_cam;
extern GLfloat rotate_z_cam;
extern int blend;
extern int light;

extern GLfloat groundSize;

extern GLfloat ambienteLight;

// Récupération des fps
extern int fps;
extern unsigned int updateMovement;

// Gestion du playmobil
extern GLfloat play_x;
extern GLfloat play_z;
extern GLfloat play_rotation;

extern GLfloat play_member_rotate_x;
int rotation_direction = 1;

extern GLfloat play_speed;

GLvoid touche(unsigned char key, int x, int y)
{
  switch (key)
  {
  case TOUCHE_MIN_Z:
    // Vérification des limites du terrain
    if (play_z > -groundSize / 2)
    {
      play_z -= 0.1;
    }
    // Animation
    if (play_member_rotate_x > 45 || play_member_rotate_x < -45)
      rotation_direction = rotation_direction * -1;
    play_member_rotate_x += 10 * rotation_direction;
    break;

  case TOUCHE_MIN_S:
    // Vérification des limites du terrain
    if (play_z < groundSize / 2)
    {
      play_z += 0.1;
    }
    // Animation
    if (play_member_rotate_x > 45 || play_member_rotate_x < -45)
      rotation_direction = rotation_direction * -1;
    play_member_rotate_x += 10 * rotation_direction;
    break;

  case TOUCHE_MIN_Q:
    play_rotation += 10;
    break;

  case TOUCHE_MIN_D:
    play_rotation -= 10;
    break;

  case TOUCHE_MIN_B:
    rotate_z_cam += 10.0;
    break;

  case TOUCHE_MIN_R:
    rotate_z_cam -= 10.0;
    break;

  case TOUCHE_MIN_L:
    if (ambienteLight == 1.0f)
    {
      ambienteLight = 0.0f;
    }
    else
    {
      ambienteLight = 1.0f;
    }
    break;

  case ESCAPE:
    exit(1);
  }
}

GLvoid touche_speciale(int key, int x, int y)
{
  switch (key)
  {

  case GLUT_KEY_UP:
    rotate_x_cam += 10.0;
    break;

  case GLUT_KEY_DOWN:
    rotate_x_cam -= 10.0;
    break;

  case GLUT_KEY_LEFT:
    rotate_y_cam -= 10.0;
    break;

  case GLUT_KEY_RIGHT:
    rotate_y_cam += 10.0;
    break;

  case ESPACE:
    break;
  }
}