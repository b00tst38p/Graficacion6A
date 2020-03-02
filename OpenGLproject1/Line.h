#pragma once
#include"Point2D.h"
#include<GL/freeglut.h>
#include<cstdlib>
class Line
{
public:
	Line();
	void setPoint(float, float, float, float);
	void drawLine();
	Point2D p1, p2;
};

