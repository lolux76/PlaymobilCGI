/*
 * ground.c
 *  
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 * 	Génère le sol de la scène
 */

#include "ground.h"

extern GLfloat groundSize;
extern TEXTURE_STRUCT * ground_Texture;

GLvoid groundCreate()
{   
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ground_Texture->width, ground_Texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, ground_Texture->data);

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();
    {
        glBegin(GL_QUADS);
        /* face avant ccw */
        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, -0.1f, 0.2f);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 2, -0.1f, 0.2f);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, 0.1f, 0.2f);
        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 2, 0.1f, 0.2f);

        /* face arrière ccw */
        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, -0.1f, -groundSize / 2);
        glTexCoord2f(1, 0);
        glVertex3f(-groundSize / 2, 0.1f, -groundSize / 2);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, 0.1f, -groundSize / 2);
        glTexCoord2f(0, 1);
        glVertex3f(groundSize / 2, -0.1f, -groundSize / 2);

        /* face dessus ccw */
        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, 0.1f, -groundSize / 2);
        glTexCoord2f(1, 0);
        glVertex3f(-groundSize / 2, 0.1f, groundSize / 2);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, 0.1f, groundSize / 2);
        glTexCoord2f(0, 1);
        glVertex3f(groundSize / 2, 0.1f, -groundSize / 2);

        

        /* face dessous ccw */
        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, -0.1f, -groundSize / 2);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 2, -0.1f, -groundSize / 2);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, -0.1f, groundSize / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 2, -0.1f, groundSize / 2);

        /* face droite ccw */
        glTexCoord2f(0, 0);
        glVertex3f(groundSize / 2, -0.1f, -groundSize / 2);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 2, 0.1f, -groundSize / 2);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, 0.1f, groundSize / 2);
        glTexCoord2f(0, 1);
        glVertex3f(groundSize / 2, -0.1f, groundSize / 2);

        /* face gauche ccw */
        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, -0.1f, -groundSize / 2);
        glTexCoord2f(1, 0);
        glVertex3f(-groundSize / 2, -0.1f, groundSize / 2);
        glTexCoord2f(1, 1);
        glVertex3f(-groundSize / 2, 0.1f, groundSize / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 2, 0.1f, -groundSize / 2);

        glEnd();
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}