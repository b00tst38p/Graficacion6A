#include "Line.h"

Line::Line()
{
}

void Line::setPoint(float x1, float y1, float x2, float y2) {
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
}

void Line::drawLine() {
	float m = (p2.y - p1.y) / (p2.x - p1.x);
	float b = p2.y - (m * p2.x);

	glPointSize(10);
	glColor3f(1, 1, 1);

	if (p1.x == p2.x) { //Vertical
		if (p1.y > p2.y) {
			float aux = p1.y; p1.y = p2.y; p2.y = aux;
		}
		glBegin(GL_POINTS);
		for (float y = p1.y; y < p2.y; y += 0.1)
		{
			glVertex2f(p1.x, y);
		}
		glEnd();
	}
	else if (p1.y == p2.y) {//Horizontal
		if (p1.x > p2.x) {
			float aux = p1.x; p1.x = p2.x; p2.x = aux;
		}
		glBegin(GL_POINTS);
		for (float x = p1.x; x < p2.x; x += 0.01)
		{
			glVertex2f(x, p1.y);
		}
		glEnd();
	}
	else {
		//se recomienda usar la funcion abs de la libreria cstdlib
		if (abs(p1.x - p2.x) > abs(p1.y - p2.y)) { //Si es  mayor la distancia entre las Xs que entre las Ys
			if (p1.x > p2.x) {
				float aux;
				aux = p1.x; p1.x = p2.x; p2.x = aux;
				aux = p1.y; p1.y = p2.y; p2.y = aux;
			}
			glPointSize(5);
			glBegin(GL_POINTS);
			for (float x = p1.x; x < p2.x; x += 0.01)
			{
				float y;
				y = (m*x) + b;
				glVertex2f(x, y);
			}
			glEnd();
		}
		else {//Si es  mayor la distancia entre las Ys que entre las Xs
			if (p1.y > p2.y) {
				float aux;
				aux = p1.x; p1.x = p2.x; p2.x = aux;
				aux = p1.y; p1.y = p2.y; p2.y = aux;
			}
			glPointSize(5);
			glBegin(GL_POINTS);
			for (float y = p1.y; y < p2.y; y += 0.01)
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
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
}