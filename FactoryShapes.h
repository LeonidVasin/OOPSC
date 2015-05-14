#pragma once

#include "Shapes.h"

class Factory
{
public:
	Point * Create_point() const;
	Circle * Create_circle() const;
	Rect * Create_rect() const;
	Polyline * Create_polyline() const;
	Polygon * Create_polygon() const;
};