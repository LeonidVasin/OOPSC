#include "FactoryShapes.h"

Point * Factory::Create_point() const
{
	int x = rand()%100, y = rand()%100;
	if (rand() % 2)
		x = -x;
	if (!(rand() % 2))
		y = -y;
	
	return new Point(x, y);
}

Circle * Factory::Create_circle() const
{
	int x = rand()%100, y = rand()%100, radius = rand()%50;
	if (rand() % 2)
		x = -x;
	if (!(rand() % 2))
		y = -y;

	return new Circle(x, y, radius);
}

Rect * Factory::Create_rect() const
{
	int x = rand() % 100, y = rand() % 100, length = rand() % 100, width = rand() % 100;
	if (rand() % 2)
		x = -x;
	if ( rand() % 2 )
		y = -y;

	return  new Rect(x, y, length, width);
}

Polyline * Factory::Create_polyline() const
{
	int counter = rand() % 15;
	Polyline * _polyline = new Polyline;
	if (counter < 3)
		counter = 5;
	for (int i = 0; i < counter; ++i)
	{
		_polyline->Add_point(*(Create_point()));
	}
	return _polyline; 
}

Polygon * Factory::Create_polygon() const
{
	int counter = rand() % 10;
	Polygon * _polygon = new Polygon;
	if (counter < 3)
		counter = 3;
	for (int i = 0; i < counter; ++i)
	{
		_polygon->Add_point(*(Create_point()));
	}
	return _polygon;
}