/*
 * playmobil.c
 *
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 * 	Génère le playmobile contrôlé manuellement, ainsi que celui qui est autonome et celui qui tourne seul sur lui même
 */

#include "playmobil.h"

// Variables playmobil "joueur"
extern GLfloat play_x;
extern GLfloat play_y;
extern GLfloat play_z;

extern GLfloat play_rotation;

extern GLfloat play_member_rotate_x;

// Variables playmobil "auto"

extern GLfloat play_x_auto;
extern GLfloat play_y_auto;
extern GLfloat play_z_auto;

extern GLfloat play_member_rotate_x_auto;

// Variables playmobil "rotation auto"
extern GLfloat play_rotation_auto;
extern GLfloat play_positionX_rotate_auto;
extern GLfloat play_positionY_rotate_auto;
extern GLfloat play_positionZ_rotate_auto;

// Tableau statique des concordances sommets/faces
static int faces[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}};

// Lumière plastique
static GLfloat mat_ambient[4] = {0.0f, 0.1f, 0.06f, 1.0f};
static GLfloat mat_diffuse[4] = {0.0f, 0.50980392f, 0.50980392f, 1.0f};
static GLfloat mat_specular[4] = {0.50196078f, 0.50196078f, 0.50196078f, 1.0f};
float shine = 32.0f;

// Affichage des jambes
GLvoid afficher_jambes(struct jambe jambes)
{
    int j = 0;
    for (j = 0; j <= 5; j++)
    {
        glPushMatrix();
        {
            glTranslatef(-jambes.taille / 3, 0.0f, 0.0f);
            glRotatef(play_member_rotate_x, 1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(jambes.couleurs[j].rouge, jambes.couleurs[j].vert, jambes.couleurs[j].bleu);
            int i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(jambes.sommets[faces[j][i]].x, jambes.sommets[faces[j][i]].y, jambes.sommets[faces[j][i]].z);
            }
            glEnd();

            // 2eme jambe

            glTranslatef(jambes.taille, 0.0f, 0.0f);
            glRotatef(play_member_rotate_x * 2, -1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(jambes.couleurs[j].rouge, jambes.couleurs[j].vert, jambes.couleurs[j].bleu);
            i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(jambes.sommets[faces[j][i]].x, jambes.sommets[faces[j][i]].y, jambes.sommets[faces[j][i]].z);
            }
            glEnd();
        }
        glPopMatrix();
    }
}

// Création des jambes
GLvoid creer_jambes(GLfloat taille)
{

    struct coordonnees coo1 = {.x = -taille / 3, .y = -taille, .z = taille / 3};
    struct coordonnees coo2 = {.x = taille / 3, .y = -taille, .z = taille / 3};
    struct coordonnees coo3 = {.x = taille / 3, .y = taille, .z = taille / 3};
    struct coordonnees coo4 = {.x = -taille / 3, .y = taille, .z = taille / 3};
    struct coordonnees coo5 = {.x = taille / 3, .y = -taille, .z = -taille / 3};
    struct coordonnees coo6 = {.x = -taille / 3, .y = -taille, .z = -taille / 3};
    struct coordonnees coo7 = {.x = -taille / 3, .y = taille, .z = -taille / 3};
    struct coordonnees coo8 = {.x = taille / 3, .y = taille, .z = -taille / 3};

    struct couleur coul1 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul2 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul3 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul4 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul5 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul6 = {.rouge = 0, .vert = 125, .bleu = 255};

    struct normale *norm1 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm2 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm3 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm4 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm5 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm6 = (struct normale *)malloc(sizeof(float) * 3);

    struct jambe jambe;

    jambe.taille = taille;

    jambe.sommets[0] = coo1;
    jambe.sommets[1] = coo2;
    jambe.sommets[2] = coo3;
    jambe.sommets[3] = coo4;
    jambe.sommets[4] = coo5;
    jambe.sommets[5] = coo6;
    jambe.sommets[6] = coo7;
    jambe.sommets[7] = coo8;

    jambe.couleurs[0] = coul1;
    jambe.couleurs[1] = coul2;
    jambe.couleurs[2] = coul3;
    jambe.couleurs[3] = coul4;
    jambe.couleurs[4] = coul5;
    jambe.couleurs[5] = coul6;

    calcul_normale(coo1.x, coo1.y, coo1.z, coo2.x, coo2.y, coo2.z, coo3.x, coo3.y, coo3.z, norm1);
    calcul_normale(coo5.x, coo5.y, coo5.z, coo6.x, coo6.y, coo6.z, coo7.x, coo7.y, coo7.z, norm2);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo5.x, coo5.y, coo5.z, coo8.x, coo8.y, coo8.z, norm3);
    calcul_normale(coo1.x, coo1.y, coo1.z, coo4.x, coo4.y, coo4.z, coo7.x, coo7.y, coo7.z, norm4);
    calcul_normale(coo3.x, coo3.y, coo3.z, coo8.x, coo8.y, coo8.z, coo7.x, coo7.y, coo7.z, norm5);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo1.x, coo1.y, coo1.z, coo6.x, coo6.y, coo6.z, norm6);

    jambe.normales[0] = *norm1;
    jambe.normales[1] = *norm2;
    jambe.normales[2] = *norm3;
    jambe.normales[3] = *norm4;
    jambe.normales[4] = *norm5;
    jambe.normales[5] = *norm6;

    afficher_jambes(jambe);
}

//---------------------------------------------------------------------------------------

GLvoid afficher_corps(struct corps corps)
{
    int j = 0;
    for (j = 0; j <= 5; j++)
    {
        glPushMatrix();
        {
            // On active la lumière plastique
            glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
            glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);

            glTranslatef(corps.taille / 6, corps.taille * 1.5 + 1.0f, 0.0f);
            glBegin(GL_QUADS);
            glColor3ub(corps.couleurs[j].rouge, corps.couleurs[j].vert, corps.couleurs[j].bleu);
            int i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(corps.sommets[faces[j][i]].x, corps.sommets[faces[j][i]].y, corps.sommets[faces[j][i]].z);
            }
            glEnd();

            // Désactivation de la lumière plastique
            generer_lumiere();
        }
        glPopMatrix();
    }
}

GLvoid creer_corps(GLfloat taille)
{
    struct coordonnees coo1 = {.x = -taille, .y = -taille * 1.5, .z = taille / 3};
    struct coordonnees coo2 = {.x = taille, .y = -taille * 1.5, .z = taille / 3};
    struct coordonnees coo3 = {.x = taille, .y = taille * 1.5, .z = taille / 3};
    struct coordonnees coo4 = {.x = -taille, .y = taille * 1.5, .z = taille / 3};
    struct coordonnees coo5 = {.x = taille, .y = -taille * 1.5, .z = -taille / 3};
    struct coordonnees coo6 = {.x = -taille, .y = -taille * 1.5, .z = -taille / 3};
    struct coordonnees coo7 = {.x = -taille, .y = taille * 1.5, .z = -taille / 3};
    struct coordonnees coo8 = {.x = taille, .y = taille * 1.5, .z = -taille / 3};

    struct couleur coul1 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul2 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul3 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul4 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul5 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul6 = {.rouge = 0, .vert = 0, .bleu = 255};

    struct normale *norm1 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm2 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm3 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm4 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm5 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm6 = (struct normale *)malloc(sizeof(float) * 3);

    struct corps corps;

    corps.taille = taille;

    corps.sommets[0] = coo1;
    corps.sommets[1] = coo2;
    corps.sommets[2] = coo3;
    corps.sommets[3] = coo4;
    corps.sommets[4] = coo5;
    corps.sommets[5] = coo6;
    corps.sommets[6] = coo7;
    corps.sommets[7] = coo8;

    corps.couleurs[0] = coul1;
    corps.couleurs[1] = coul2;
    corps.couleurs[2] = coul3;
    corps.couleurs[3] = coul4;
    corps.couleurs[4] = coul5;
    corps.couleurs[5] = coul6;

    calcul_normale(coo1.x, coo1.y, coo1.z, coo2.x, coo2.y, coo2.z, coo3.x, coo3.y, coo3.z, norm1);
    calcul_normale(coo5.x, coo5.y, coo5.z, coo6.x, coo6.y, coo6.z, coo7.x, coo7.y, coo7.z, norm2);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo5.x, coo5.y, coo5.z, coo8.x, coo8.y, coo8.z, norm3);
    calcul_normale(coo1.x, coo1.y, coo1.z, coo4.x, coo4.y, coo4.z, coo7.x, coo7.y, coo7.z, norm4);
    calcul_normale(coo3.x, coo3.y, coo3.z, coo8.x, coo8.y, coo8.z, coo7.x, coo7.y, coo7.z, norm5);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo1.x, coo1.y, coo1.z, coo6.x, coo6.y, coo6.z, norm6);

    corps.normales[0] = *norm1;
    corps.normales[1] = *norm2;
    corps.normales[2] = *norm3;
    corps.normales[3] = *norm4;
    corps.normales[4] = *norm5;
    corps.normales[5] = *norm6;

    afficher_corps(corps);
}

//---------------------------------------------------------------------------------------

GLvoid afficher_bras(struct bras bras)
{
    int j = 0;
    for (j = 0; j <= 5; j++)
    {
        glPushMatrix();
        {
            glTranslatef(-bras.taille * 1.2, bras.taille * 2.5 + 0.66, 0.0f);
            glRotatef(play_member_rotate_x, -1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(bras.couleurs[j].rouge, bras.couleurs[j].vert, bras.couleurs[j].bleu);
            int i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(bras.sommets[faces[j][i]].x, bras.sommets[faces[j][i]].y, bras.sommets[faces[j][i]].z);
            }
            glEnd();

            // 2eme bras

            glTranslatef(bras.taille * 1.2 * 2.25, 0.0f, 0.0f);
            glRotatef(play_member_rotate_x * 2, 1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(bras.couleurs[j].rouge, bras.couleurs[j].vert, bras.couleurs[j].bleu);
            i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(bras.sommets[faces[j][i]].x, bras.sommets[faces[j][i]].y, bras.sommets[faces[j][i]].z);
            }
            glEnd();
        }
        glPopMatrix();
    }
}

GLvoid creer_bras(GLfloat taille)
{

    struct coordonnees coo1 = {.x = -taille / 3, .y = -taille / 1.2, .z = taille / 3};
    struct coordonnees coo2 = {.x = taille / 3, .y = -taille / 1.2, .z = taille / 3};
    struct coordonnees coo3 = {.x = taille / 3, .y = taille / 1.2, .z = taille / 3};
    struct coordonnees coo4 = {.x = -taille / 3, .y = taille / 1.2, .z = taille / 3};
    struct coordonnees coo5 = {.x = taille / 3, .y = -taille / 1.2, .z = -taille / 3};
    struct coordonnees coo6 = {.x = -taille / 3, .y = -taille / 1.2, .z = -taille / 3};
    struct coordonnees coo7 = {.x = -taille / 3, .y = taille / 1.2, .z = -taille / 3};
    struct coordonnees coo8 = {.x = taille / 3, .y = taille / 1.2, .z = -taille / 3};

    struct couleur coul1 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul2 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul3 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul4 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul5 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul6 = {.rouge = 0, .vert = 0, .bleu = 255};

    struct normale *norm1 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm2 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm3 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm4 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm5 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm6 = (struct normale *)malloc(sizeof(float) * 3);

    struct bras bras;

    bras.taille = taille;

    bras.sommets[0] = coo1;
    bras.sommets[1] = coo2;
    bras.sommets[2] = coo3;
    bras.sommets[3] = coo4;
    bras.sommets[4] = coo5;
    bras.sommets[5] = coo6;
    bras.sommets[6] = coo7;
    bras.sommets[7] = coo8;

    bras.couleurs[0] = coul1;
    bras.couleurs[1] = coul2;
    bras.couleurs[2] = coul3;
    bras.couleurs[3] = coul4;
    bras.couleurs[4] = coul5;
    bras.couleurs[5] = coul6;

    calcul_normale(coo1.x, coo1.y, coo1.z, coo2.x, coo2.y, coo2.z, coo3.x, coo3.y, coo3.z, norm1);
    calcul_normale(coo5.x, coo5.y, coo5.z, coo6.x, coo6.y, coo6.z, coo7.x, coo7.y, coo7.z, norm2);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo5.x, coo5.y, coo5.z, coo8.x, coo8.y, coo8.z, norm3);
    calcul_normale(coo1.x, coo1.y, coo1.z, coo4.x, coo4.y, coo4.z, coo7.x, coo7.y, coo7.z, norm4);
    calcul_normale(coo3.x, coo3.y, coo3.z, coo8.x, coo8.y, coo8.z, coo7.x, coo7.y, coo7.z, norm5);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo1.x, coo1.y, coo1.z, coo6.x, coo6.y, coo6.z, norm6);

    bras.normales[0] = *norm1;
    bras.normales[1] = *norm2;
    bras.normales[2] = *norm3;
    bras.normales[3] = *norm4;
    bras.normales[4] = *norm5;
    bras.normales[5] = *norm6;

    afficher_bras(bras);
}

//---------------------------------------------------------------------------------------

GLvoid creer_tete(GLfloat taille)
{
    glPushMatrix();
    {
        glTranslatef(taille / 6, taille * 4 + 0.5, 0.0f);
        glColor3f(250, 230, 180);
        glutSolidSphere(3 * taille / 4, 200, 10);
    }
    glPopMatrix();
}

GLvoid playmobil(GLfloat taille)
{
    glPushMatrix();
    {
        glRotatef(play_rotation, 0.0, 1.0, 0.0);
        glTranslatef(play_x, play_y, play_z);
        creer_jambes(taille);
        creer_corps(taille);
        creer_bras(taille);
        creer_tete(taille);
    }
    glPopMatrix();
}

// REPLIQUE AUTONOME

GLvoid afficher_jambes_auto(struct jambe jambes)
{
    int j = 0;
    for (j = 0; j <= 5; j++)
    {
        glPushMatrix();
        {
            glTranslatef(-jambes.taille / 3, 0.0f, 0.0f);
            glRotatef(play_member_rotate_x_auto, 1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(jambes.couleurs[j].rouge, jambes.couleurs[j].vert, jambes.couleurs[j].bleu);
            int i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(jambes.sommets[faces[j][i]].x, jambes.sommets[faces[j][i]].y, jambes.sommets[faces[j][i]].z);
            }
            glEnd();

            // 2eme jambe

            glTranslatef(jambes.taille, 0.0f, 0.0f);
            glRotatef(play_member_rotate_x_auto * 2, -1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(jambes.couleurs[j].rouge, jambes.couleurs[j].vert, jambes.couleurs[j].bleu);
            i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(jambes.sommets[faces[j][i]].x, jambes.sommets[faces[j][i]].y, jambes.sommets[faces[j][i]].z);
            }
            glEnd();
        }
        glPopMatrix();
    }
}

GLvoid creer_jambes_auto(GLfloat taille)
{

    struct coordonnees coo1 = {.x = -taille / 3, .y = -taille, .z = taille / 3};
    struct coordonnees coo2 = {.x = taille / 3, .y = -taille, .z = taille / 3};
    struct coordonnees coo3 = {.x = taille / 3, .y = taille, .z = taille / 3};
    struct coordonnees coo4 = {.x = -taille / 3, .y = taille, .z = taille / 3};
    struct coordonnees coo5 = {.x = taille / 3, .y = -taille, .z = -taille / 3};
    struct coordonnees coo6 = {.x = -taille / 3, .y = -taille, .z = -taille / 3};
    struct coordonnees coo7 = {.x = -taille / 3, .y = taille, .z = -taille / 3};
    struct coordonnees coo8 = {.x = taille / 3, .y = taille, .z = -taille / 3};

    struct couleur coul1 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul2 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul3 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul4 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul5 = {.rouge = 0, .vert = 125, .bleu = 255};
    struct couleur coul6 = {.rouge = 0, .vert = 125, .bleu = 255};

    struct normale *norm1 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm2 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm3 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm4 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm5 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm6 = (struct normale *)malloc(sizeof(float) * 3);

    struct jambe jambe;

    jambe.taille = taille;

    jambe.sommets[0] = coo1;
    jambe.sommets[1] = coo2;
    jambe.sommets[2] = coo3;
    jambe.sommets[3] = coo4;
    jambe.sommets[4] = coo5;
    jambe.sommets[5] = coo6;
    jambe.sommets[6] = coo7;
    jambe.sommets[7] = coo8;

    jambe.couleurs[0] = coul1;
    jambe.couleurs[1] = coul2;
    jambe.couleurs[2] = coul3;
    jambe.couleurs[3] = coul4;
    jambe.couleurs[4] = coul5;
    jambe.couleurs[5] = coul6;

    calcul_normale(coo1.x, coo1.y, coo1.z, coo2.x, coo2.y, coo2.z, coo3.x, coo3.y, coo3.z, norm1);
    calcul_normale(coo5.x, coo5.y, coo5.z, coo6.x, coo6.y, coo6.z, coo7.x, coo7.y, coo7.z, norm2);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo5.x, coo5.y, coo5.z, coo8.x, coo8.y, coo8.z, norm3);
    calcul_normale(coo1.x, coo1.y, coo1.z, coo4.x, coo4.y, coo4.z, coo7.x, coo7.y, coo7.z, norm4);
    calcul_normale(coo3.x, coo3.y, coo3.z, coo8.x, coo8.y, coo8.z, coo7.x, coo7.y, coo7.z, norm5);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo1.x, coo1.y, coo1.z, coo6.x, coo6.y, coo6.z, norm6);

    jambe.normales[0] = *norm1;
    jambe.normales[1] = *norm2;
    jambe.normales[2] = *norm3;
    jambe.normales[3] = *norm4;
    jambe.normales[4] = *norm5;
    jambe.normales[5] = *norm6;

    afficher_jambes_auto(jambe);
}

//---------------------------------------------------------------------------------------

GLvoid afficher_bras_auto(struct bras bras)
{
    int j = 0;
    for (j = 0; j <= 5; j++)
    {
        glPushMatrix();
        {
            glTranslatef(-bras.taille * 1.2, bras.taille * 2.5 + 0.66, 0.0f);
            glRotatef(play_member_rotate_x_auto, -1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(bras.couleurs[j].rouge, bras.couleurs[j].vert, bras.couleurs[j].bleu);
            int i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(bras.sommets[faces[j][i]].x, bras.sommets[faces[j][i]].y, bras.sommets[faces[j][i]].z);
            }
            glEnd();

            // 2eme bras

            glTranslatef(bras.taille * 1.2 * 2.25, 0.0f, 0.0f);
            glRotatef(play_member_rotate_x_auto * 2, 1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(bras.couleurs[j].rouge, bras.couleurs[j].vert, bras.couleurs[j].bleu);
            i = 0;
            for (i = 0; i <= 3; i++)
            {
                glVertex3f(bras.sommets[faces[j][i]].x, bras.sommets[faces[j][i]].y, bras.sommets[faces[j][i]].z);
            }
            glEnd();
        }
        glPopMatrix();
    }
}

GLvoid creer_bras_auto(GLfloat taille)
{

    struct coordonnees coo1 = {.x = -taille / 3, .y = -taille / 1.2, .z = taille / 3};
    struct coordonnees coo2 = {.x = taille / 3, .y = -taille / 1.2, .z = taille / 3};
    struct coordonnees coo3 = {.x = taille / 3, .y = taille / 1.2, .z = taille / 3};
    struct coordonnees coo4 = {.x = -taille / 3, .y = taille / 1.2, .z = taille / 3};
    struct coordonnees coo5 = {.x = taille / 3, .y = -taille / 1.2, .z = -taille / 3};
    struct coordonnees coo6 = {.x = -taille / 3, .y = -taille / 1.2, .z = -taille / 3};
    struct coordonnees coo7 = {.x = -taille / 3, .y = taille / 1.2, .z = -taille / 3};
    struct coordonnees coo8 = {.x = taille / 3, .y = taille / 1.2, .z = -taille / 3};

    struct couleur coul1 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul2 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul3 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul4 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul5 = {.rouge = 0, .vert = 0, .bleu = 255};
    struct couleur coul6 = {.rouge = 0, .vert = 0, .bleu = 255};

    struct normale *norm1 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm2 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm3 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm4 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm5 = (struct normale *)malloc(sizeof(float) * 3);
    struct normale *norm6 = (struct normale *)malloc(sizeof(float) * 3);

    struct bras bras;

    bras.taille = taille;

    bras.sommets[0] = coo1;
    bras.sommets[1] = coo2;
    bras.sommets[2] = coo3;
    bras.sommets[3] = coo4;
    bras.sommets[4] = coo5;
    bras.sommets[5] = coo6;
    bras.sommets[6] = coo7;
    bras.sommets[7] = coo8;

    bras.couleurs[0] = coul1;
    bras.couleurs[1] = coul2;
    bras.couleurs[2] = coul3;
    bras.couleurs[3] = coul4;
    bras.couleurs[4] = coul5;
    bras.couleurs[5] = coul6;

    calcul_normale(coo1.x, coo1.y, coo1.z, coo2.x, coo2.y, coo2.z, coo3.x, coo3.y, coo3.z, norm1);
    calcul_normale(coo5.x, coo5.y, coo5.z, coo6.x, coo6.y, coo6.z, coo7.x, coo7.y, coo7.z, norm2);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo5.x, coo5.y, coo5.z, coo8.x, coo8.y, coo8.z, norm3);
    calcul_normale(coo1.x, coo1.y, coo1.z, coo4.x, coo4.y, coo4.z, coo7.x, coo7.y, coo7.z, norm4);
    calcul_normale(coo3.x, coo3.y, coo3.z, coo8.x, coo8.y, coo8.z, coo7.x, coo7.y, coo7.z, norm5);
    calcul_normale(coo2.x, coo2.y, coo2.z, coo1.x, coo1.y, coo1.z, coo6.x, coo6.y, coo6.z, norm6);

    bras.normales[0] = *norm1;
    bras.normales[1] = *norm2;
    bras.normales[2] = *norm3;
    bras.normales[3] = *norm4;
    bras.normales[4] = *norm5;
    bras.normales[5] = *norm6;

    afficher_bras_auto(bras);
}

GLvoid playmobil_auto(GLfloat taille)
{
    glPushMatrix();
    {
        glTranslatef(play_x_auto, play_y_auto, play_z_auto);
        creer_jambes_auto(taille);
        creer_corps(taille);
        creer_bras_auto(taille);
        creer_tete(taille);
    }
    glPopMatrix();
}

GLvoid playmobil_rotate(GLfloat taille)
{
    glPushMatrix();
    {
        glTranslatef(play_positionX_rotate_auto, play_positionY_rotate_auto, play_positionZ_rotate_auto);
        glRotatef(play_rotation_auto, 0.0f, 1.0f, 0.0f);
        creer_jambes(taille);
        creer_corps(taille);
        creer_bras(taille);
        creer_tete(taille);
    }
    glPopMatrix();
}