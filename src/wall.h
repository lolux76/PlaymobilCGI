#pragma once

/*
 * wall.h
 *  
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 * 	Génère les murs de la scène
 */

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "ppm.h"

GLvoid backWall();
GLvoid otherWalls();
GLvoid createWall();