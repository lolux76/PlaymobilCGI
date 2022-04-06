/*
 * lumiere.c
 *  
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 *  Génère la lumiere de base de la scène
 */

#include "lumiere.h"

extern GLfloat ambienteLight;

GLvoid generer_lumiere()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    GLfloat ambiente[4] = {ambienteLight, ambienteLight, ambienteLight, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
    GLfloat diff_et_spec[4] = {0.5f, 0.5f, 0.5f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff_et_spec);
    glLightfv(GL_LIGHT0, GL_SPECULAR, diff_et_spec);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);
    GLfloat position[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}