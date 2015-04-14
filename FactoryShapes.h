#pragma once
#include "Shapes.h"

class Factory
{
public:
	~Factory() {}
	Point * Create_point();
	Circle * Create_circle();
	Rect * Create_rect();
	Polyline * Create_polyline();
	Polygon * Create_polygon();
};