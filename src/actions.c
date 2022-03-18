#include "actions.h"
#include <stdio.h>

extern GLfloat rotate_x_sphere;
extern GLfloat rotate_y_sphere; 
extern int blend;
extern int light;

GLvoid touche(unsigned char key, int x, int y) 
{
  switch(key){

    case ESCAPE :
      exit(1);
  }
}

GLvoid touche_speciale(int key, int x, int y) 
{
  switch(key){

    case TOUCHE_MIN_B :
      rotate_x_sphere += 10.0;
      break;

    case GLUT_KEY_UP :
      rotate_x_sphere += 10.0;
      break;

    case GLUT_KEY_DOWN :
      rotate_x_sphere -= 10.0;
      break;

    case GLUT_KEY_LEFT :
      rotate_y_sphere -= 10.0;
      break;

    case GLUT_KEY_RIGHT :
      rotate_y_sphere += 10.0;
      break;
    
    case ESPACE :
      break;

  }
}