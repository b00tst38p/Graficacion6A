#include "Transform.h"

Transform::Transform()
{
}

void Transform::Traslation(Point2D & p, float tx, float ty) {
	p.x = p.x + tx;
	p.y = p.y + ty;
}