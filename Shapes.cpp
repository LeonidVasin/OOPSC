#include "Shapes.h"

unsigned int Shape::counter = 0;

void Point::Print(std::ostream & _stream) const
{
	_stream << "Spape: " << name << " x: " << x << " y: " << y;
}

void Circle::Print(std::ostream & _stream)const
{
	_stream << "Shape: " << name << " x: " << x << " y: " << y << " radius:" << radius;
}

void Rect::Print(std::ostream & _stream)const
{
	_stream << "Shape: " << name << " x: " << x << " y: " << y << " length: " << length << " width: " << width;
}

void Polyline::Print(std::ostream & _stream) const
{
	_stream << "Shape: " << name << ": " << std::endl;
	for (XList<Point>::XListIterator it = list_Points.Head_XList(); it != list_Points.End(); ++it)
	{
		_stream << *it << std::endl;
	}
}

void Polygon::Print(std::ostream & _stream) const
{
	_stream << "Shape: " << name << ": " << std::endl;
	for (XList<Point>::XListIterator it = list_Points.Head_XList(); it != list_Points.End(); ++it)
	{
		_stream << *it << std::endl;
	}
}

std::ostream & operator << (std::ostream & _stream, Printable const & _printable) {
	_printable.Print(_stream);
	return _stream;
}