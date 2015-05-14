#pragma once

#include "Base.h"
#include "XList.h"
#include <iostream>

class Shape : public virtual Named
{
public:
	Shape() :Named("") { ++counter; }
	static unsigned int Get_count(void) { return counter; }
	virtual ~Shape() = 0 { --counter; }
private:
	static unsigned int counter;
};

class Point : public Shape, public Printable
{
public:
	Point() : Named("Point"){}
	Point(int _x, int _y) : x(_x), y(_y), Named("Point") {}
	virtual ~Point() {}
	void Print(std::ostream & _stream) const;
	
private:
	int x, y;
};

class Circle : public Shape, public Printable
{
public:
	Circle() : Named("Circle") {}
	Circle(int _x, int _y, int _r) : x(_x), y(_y), radius(_r), Named("Circle") {}
	virtual ~Circle() {}
	void Print(std::ostream & _stream) const;
	
private:
	int x, y;
	int radius;
};

class Rect : public Shape, public Printable
{
public:
	Rect() : Named("Rect") {}
	Rect(int _x, int _y, unsigned int _length, unsigned int _width) : x(_x), y(_y), length(_length), width(_width), Named("Rect") {}
	virtual ~Rect() {}
	void Print(std::ostream & _stream) const;
	
private:
	int x, y;
	unsigned int length, width;
};

class Polyline : public Shape, public Printable
{
public:
	Polyline() : Named("Polyline") {}
	virtual ~Polyline() { list_Points.Clear(); }
	virtual void Add_point(int _x, int _y) { list_Points.Add_tail(Point(_x,_y)); }
	virtual void Add_point(Point const & _point) { list_Points.Add_tail(_point); }
	void Print(std::ostream & _stream) const;

private:
	XList<Point> list_Points;
};

class Polygon : public Shape, public Printable
{
public:
	Polygon() : Named("Polygon") {}
	virtual ~Polygon() {}
	void Add_point(int _x, int _y) { list_Points.Add_tail(Point(_x, _y)); }
	void Add_point(Point const & _point) { list_Points.Add_tail(_point); }
	void Print(std::ostream & _stream) const;	
private:
	XList<Point> list_Points;
};