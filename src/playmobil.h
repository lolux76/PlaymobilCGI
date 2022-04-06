#pragma once

/*
 * playmobil.h
 *
 * Auteur: Matéo Grimaud
 * Email: mateo.grimaud@etud.univ-angers.fr
 * Description:
 * 	Génère le playmobile contrôlé manuellement, ainsi que celui qui est autonome et celui qui tourne sur lui même
 */

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "normale.h"
#include "lumiere.h"

// Structures de données, la structure des bras, jambes et corps sont les mêmes, leurs déclarations tout de même répétées pour simplifier la lecture du code

struct couleur
{
  GLuint rouge, vert, bleu;
};

struct coordonnees
{
  GLfloat x, y, z;
};

struct jambe
{
  struct coordonnees sommets[8];
  struct couleur couleurs[6];
  struct normale normales[6];
  GLfloat taille;
};

struct corps
{
  struct coordonnees sommets[8];
  struct couleur couleurs[6];
  struct normale normales[6];
  GLfloat taille;
};

struct bras
{
  struct coordonnees sommets[8];
  struct couleur couleurs[6];
  struct normale normales[6];
  GLfloat taille;
};

GLvoid afficher_jambes(struct jambe jambes); // Affichage des jambes
GLvoid creer_jambes(GLfloat taille);         // Création des jambes
GLvoid afficher_corps(struct corps corps);   // Affichage du corps
GLvoid creer_corps(GLfloat taille);          // Création du corps
GLvoid afficher_bras(struct bras bras);      // Affichage des bras
GLvoid creer_bras(GLfloat taille);           // Création des bras
GLvoid creer_tete(GLfloat taille);           // Création et affichage de la tete

GLvoid afficher_jambes_auto(struct jambe jambes); // Affichage des jambes
GLvoid creer_jambes_auto(GLfloat taille);         // Création des jambes
GLvoid afficher_bras_auto(struct bras bras);      // Affichage des bras
GLvoid creer_bras_auto(GLfloat taille);           // Création des bras

GLvoid playmobil(GLfloat taille);        // Génération du playmobil "joueur"
GLvoid playmobil_auto(GLfloat taille);   // Génération du playmobil "auto"
GLvoid playmobil_rotate(GLfloat taille); // Génération du playmobil qui tourne seul sur lui même