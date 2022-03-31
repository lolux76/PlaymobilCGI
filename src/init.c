#include "init.h"

extern int window;
extern void touche;
extern void touche_speciale;

GLvoid Redimensionne(GLsizei Width, GLsizei Height)
{
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)Width / (GLfloat)Height, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

int notre_init(int argc, char **argv, void (*Modelisation)())
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1400, 1000);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Playmobil");
	glutDisplayFunc(Modelisation);
	glutIdleFunc(Modelisation);
	glutReshapeFunc(&Redimensionne);
	glutKeyboardFunc(&touche);
	glutSpecialFunc(&touche_speciale);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutMainLoop();

	return 1;
}