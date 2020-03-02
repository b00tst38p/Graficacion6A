#include<GL/freeglut.h>
#include<iostream>
#include"Line.h"
#include<vector>
#include"Transform.h"

using namespace std;

void Update();
void Linea();
void Mouse(GLint, GLint, GLint, GLint);
float X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
float W = 640, H = 480;
float maxX = 1, maxY = 1;
Line l;
Transform t;
vector <Line> lineas;

int main(int arg, char** argv) {
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(W, H);
	glutCreateWindow("Mouse");
	glClearColor(0.5, 0.5, 0.5, 0);
	glutDisplayFunc(Update);
	glutMouseFunc(Mouse);

	glutMainLoop();
	return 0;
}

void Mouse(GLint button, GLint action, GLint x, GLint y) {
	x = x - (W / 2);
	y = y - (H / 2);

	//puntos del plano donde se generó el evento
	float X = x * maxX / (W / 2);
	float Y = y * maxY / (H / 2) * (-1);

	cout << button << " " << action << " " << X << " " << Y << endl;

	if (button == GLUT_LEFT_BUTTON) {		//GLUT_MIDDLE_BUTTON  GLUT_RIGHT_BUTTON
		if (action == GLUT_DOWN) {
			cout << "presionar" << endl;
			//establezco el primer punto de la figura
			X1 = X;
			Y1 = Y;
		}
		else if (action == GLUT_UP) {
			cout << "soltar" << endl;
			//establezco el segundo punto de la figura
			X2 = X;
			Y2 = Y;
			l.setPoint(X1, Y1, X2, Y2);
			lineas.push_back(l);
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		if (action == GLUT_DOWN) {
			cout << "traslacion" << endl;
			t.Traslation(lineas.at(lineas.size() - 1).p1, .05, 0);
			t.Traslation(lineas.at(lineas.size() - 1).p2, .05, 0);
		}
	}

}

void Update() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//l.drawLine();
	for (int i = 0; i < lineas.size(); i++) {
		lineas.at(i).drawLine();
	}

	glutSwapBuffers();
}

void Linea() {
	
}