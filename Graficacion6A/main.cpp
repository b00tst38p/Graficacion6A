#include<iostream>
#include<GL/freeglut.h>

using namespace std;

void Update();

int main(int arg, char**argv) {
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Tutorial 1");
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	glutDisplayFunc(Update);

	glutMainLoop();
	return 0;
}

void Update() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0f);
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
		glVertex2f(0.1f, 0.5f);
	glEnd();

	glutSwapBuffers();
}