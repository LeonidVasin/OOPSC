#include "Shapes.h"

int Shape::counter;

std::ostream & operator<< (std::ostream & ioStream, const Point& _point)
{
	ioStream << "Spape: " << _point.name << " x: " << _point.x << " y: " << _point.y;
	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Circle& _circle)
{
	ioStream << "Shape: " << _circle.name << " x: " << _circle.x << " y: " << _circle.y << " radius:" << _circle.radius;
	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Rect& _rect)
{
	ioStream << "Shape: " << _rect.name << " x: " << _rect.x << " y: " << _rect.y << " length: " << _rect.length 
		<< " width: " << _rect.width;
	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Polyline& _polyline)
{
	ioStream << "Shape: " << _polyline.name << ": " << std::endl;
	for (XList<Point>::XListIterator it = _polyline.list_Points.Head_XList(); it != _polyline.list_Points.End(); ++it)
	{
		ioStream << *it << std::endl;
	}
	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Polygon& _polygon)
{
	ioStream << "Shape: " << _polygon.name << ": " << std::endl;
	for (XList<Point>::XListIterator it = _polygon.list_Points.Head_XList(); it != _polygon.list_Points.End(); ++it)
	{
		ioStream << *it << std::endl;
	}
	return ioStream;
}