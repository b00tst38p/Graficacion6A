#include<GL/freeglut.h>
#include<iostream>

using namespace std;

void Update();
void Linea();
void Mouse(GLint, GLint, GLint, GLint);
float X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
float W = 640, H = 480;
float maxX = 1, maxY = 1;

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
		}
	}

}

void Update() {
	//glClear(GL_COLOR_BUFFER_BIT);

	Linea();


	glutSwapBuffers();
}

void Linea() {
	float m = (Y2 - Y1) / (X2 - X1);
	float b = Y2 - (m * X2);

	glPointSize(10);
	glColor3f(1, 1, 1);

	if (X1 == X2) { //Vertical
		if (Y1 > Y2) {
			float aux = Y1; Y1 = Y2; Y2 = aux;
		}
		glBegin(GL_POINTS);
		for (float y = Y1; y < Y2; y += 0.1)
		{
			glVertex2f(X1, y);
		}
		glEnd();
	}
	else if (Y1 == Y2) {//Horizontal
		if (X1 > X2) {
			float aux = X1; X1 = X2; X2 = aux;
		}
		glBegin(GL_POINTS);
		for (float x = X1; x < X2; x += 0.01)
		{
			glVertex2f(x, Y1);
		}
		glEnd();
	}
	else {
		if (abs(X1 - X2) > abs(Y1 - Y2)) { //Si es  mayor la distancia entre las Xs que entre las Ys
			if (X1 > X2) {
				float aux;
				aux = X1; X1 = X2; X2 = aux;
				aux = Y1; Y1 = Y2; Y2 = aux;
			}
			glPointSize(5);
			glBegin(GL_POINTS);
			for (float x = X1; x < X2; x += 0.01)
			{
				float y;
				y = (m*x) + b;
				glVertex2f(x, y);
			}
			glEnd();
		}
		else {//Si es  mayor la distancia entre las Ys que entre las Xs
			if (Y1 > Y2) {
				float aux;
				aux = X1; X1 = X2; X2 = aux;
				aux = Y1; Y1 = Y2; Y2 = aux;
			}
			glPointSize(5);
			glBegin(GL_POINTS);
			for (float y = Y1; y < Y2; y += 0.01)
			{
				float x;
				x = (y - b) / m;
				glVertex2f(x, y);
			}
			glEnd();
		}
	}

	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(X1, Y1);
	glVertex2f(X2, Y2);
	glEnd();
}