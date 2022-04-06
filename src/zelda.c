/*
 * zelda.c
 *  
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 *  Génère l'animation de Zelda
 */

#include "zelda.h"

extern GLfloat groundSize;
extern unsigned int zeldaIndex;
extern TEXTURE_STRUCT *zelda[6];

GLvoid zeldaAnim()
{
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, zelda[zeldaIndex]->width, zelda[zeldaIndex]->height, 0, GL_RGB, GL_UNSIGNED_BYTE, zelda[zeldaIndex]->data);

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();
    {
        glTranslatef(0.0f, groundSize / 4, -groundSize / 3);
        glBegin(GL_QUADS);

        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 4, -groundSize / 8, 0.2f);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 4, -groundSize / 8, 0.2f);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 4, groundSize / 8, 0.2f);
        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 4, groundSize / 8, 0.2f);

        glEnd();
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}