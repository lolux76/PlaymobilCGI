/*
 * wall.c
 *
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 * 	Génère les murs de la scène
 */

#include "wall.h"

extern GLfloat groundSize;
extern TEXTURE_STRUCT *backWall_Texture;
extern TEXTURE_STRUCT *wall_Texture;

GLvoid backWall()
{
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, backWall_Texture->width, backWall_Texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, backWall_Texture->data);

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture);

    /* Mur de derrière CCW */
    glPushMatrix();
    {
        glTranslatef(0.0f, groundSize / 4, groundSize / 2);
        glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, groundSize / 4, 0.2f);
        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 2, groundSize / 4, 0.2f);

        glEnd();
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

GLvoid otherWalls()
{
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, wall_Texture->width, wall_Texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, wall_Texture->data);

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture);

    /* Mur de droite CCW */
    glPushMatrix();
    {
        glTranslatef(groundSize / 2, groundSize / 4, 0.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, groundSize / 4, 0.2f);
        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 2, groundSize / 4, 0.2f);

        glEnd();
    }
    glPopMatrix();

    /* Mur de gauche CCW */
    glPushMatrix();
    {
        glTranslatef(-groundSize / 2, groundSize / 4, 0.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, groundSize / 4, 0.2f);
        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 2, groundSize / 4, 0.2f);

        glEnd();
    }
    glPopMatrix();

    /* Mur de face CCW */
    glPushMatrix();
    {
        glTranslatef(0.0f, groundSize / 4, -groundSize / 2);
        glBegin(GL_QUADS);

        glTexCoord2f(0, 1);
        glVertex3f(-groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 1);
        glVertex3f(groundSize / 2, -groundSize / 4, 0.2f);
        glTexCoord2f(1, 0);
        glVertex3f(groundSize / 2, groundSize / 4, 0.2f);
        glTexCoord2f(0, 0);
        glVertex3f(-groundSize / 2, groundSize / 4, 0.2f);

        glEnd();
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
GLvoid createWall()
{
    backWall();
    otherWalls();
}