#pragma once

#include "Base.h"
#include "XList.h"
#include <iostream>

class Shape : public virtual Named
{
public:
	Shape():Named("") {}
	static int Get_count(void) { return counter; }
	virtual ~Shape() = 0 {}
protected:
	static int counter;
};

class Point : public virtual Shape, public virtual Printable
{
public:
	Point() : x(0), y(0), Named("Point") { ++counter; }
	Point(int _x, int _y) : x(_x), y(_y), Named("Point") { ++counter; }
	virtual ~Point() { --counter; }
	friend std::ostream & operator<< (std::ostream & ioStream, const Point& _point);	
private:
	int x, y;
};

class Circle : public virtual Shape, public virtual Printable
{
public:
	Circle() : x(0), y(0), radius(0), Named("Circle") { ++counter; }
	Circle(int _x, int _y, int _r) : x(_x), y(_y), radius(_r), Named("Circle") { ++counter; }
	virtual ~Circle() { --counter; }
	friend std::ostream & operator<< (std::ostream & ioStream, const Circle& _circle);
private:
	int x, y;
	int radius;
};

class Rect : public virtual Shape, public virtual Printable
{
public:
	Rect() : x(0), y(0), length(0), width(0), Named("Rect") { ++counter; }
	Rect(int _x, int _y, int _length, int _width) : x(_x), y(_y), length(_length), width(_width), Named("Rect") { ++counter; }
	virtual ~Rect() { --counter; }
	friend std::ostream & operator<< (std::ostream & ioStream, const Rect& _rect);
private:
	int x, y, length, width;
};

class Polyline : public virtual Shape, public virtual Printable
{
public:
	Polyline() : Named("Polyline") { ++counter; }
	virtual ~Polyline() { --counter; list_Points.Clear(); }
	void Add_point(int _x, int _y) { list_Points.Add_tail(Point(_x,_y)); }
	void Add_point(Point const & _point) { list_Points.Add_tail(_point); }
	friend std::ostream & operator<< (std::ostream & ioStream, const Polyline& _polyline);
private:
	XList<Point> list_Points;
};

class Polygon : public virtual Shape, public virtual Printable
{
public:
	Polygon() : Named("Polygon") { ++counter; }
	virtual ~Polygon() { --counter; list_Points.Clear(); }
	void Add_point(int _x, int _y) { list_Points.Add_tail(Point(_x, _y)); }
	void Add_point(Point const & _point) { list_Points.Add_tail(_point); }
	friend std::ostream & operator<< (std::ostream & ioStream, const Polygon& _polygon);
private:
	XList<Point> list_Points;
};