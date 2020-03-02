#include<GL/freeglut.h>
#include<iostream>

using namespace std;

void Update();
void Linea();
float X1=0.5, Y1=0.5, X2=-0.5, Y2=0.5;

int main(int arg, char** argv) {
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Linea");
	glClearColor(0.1, 0.1, 0.1, 0);
	glutDisplayFunc(Update);
	/*
	cout << "X1:";
	cin >> X1;
	cout << "Y1:";
	cin >> Y1;
	cout << "X2:";
	cin >> X2;
	cout << "Y2:";
	cin >> Y2;
	*/
	glutMainLoop();
	return 0;
}

void Update() {
	glClear(GL_COLOR_BUFFER_BIT);

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
		abs(4.6);
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