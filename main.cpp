#include "XList.h"
#include "Shapes.h"
#include "FactoryShapes.h"
#include <memory>


int main()
{
	
	XList<Shape*> _shape;

	for (int i = 0; i < 20; ++i)
	{
		switch (rand() % 5)
		{
		case 0:
			_shape.Add_tail((new Factory)->Create_point());
			break;
		case 1:
			_shape.Add_tail((new Factory)->Create_circle());
			break;
		case 2:
			_shape.Add_tail((new Factory)->Create_rect());
			break;
		case 3:
			_shape.Add_tail((new Factory)->Create_polyline());
			break;
		case 4:
			_shape.Add_tail((new Factory)->Create_polygon());
			break;
		}
	}

	unsigned int count = 0;
	std::cout << "Total to the figures: " << Shape::Get_count() << std::endl;

	try
	{

		XList<Shape*>::XListIterator it;

		for (it = _shape.Head_XList(); it != _shape.End(); ++it)
		{
			if (dynamic_cast<Point*>(*it))
				++count;
		}

		std::cout << "Points in list: " << count << std::endl;

		count = 0;

		for (it = _shape.Head_XList(); it != _shape.End(); ++it)
		{
			if (dynamic_cast<Circle*>(*it))
				++count;
		}

		std::cout << "Circle in list: " << count << std::endl;

		count = 0;

		for (it = _shape.Head_XList(); it != _shape.End(); ++it)
		{
			if (dynamic_cast<Rect*>(*it))
				++count;
		}

		std::cout << "Rect in list: " << count << std::endl;

		count = 0;

		for (it = _shape.Head_XList(); it != _shape.End(); ++it)
		{
			if (dynamic_cast<Polyline*>(*it))
				++count;
		}
		
		std::cout << "Polyline in list: " << count << std::endl;

		count = 0;

		for (it = _shape.Head_XList(); it != _shape.End(); ++it)
		{
			if (dynamic_cast<Polygon*>(*it))
				++count;
		}

		std::cout << "Polygon in list: " << count << std::endl;

		for (it = _shape.Head_XList(); it != _shape.End(); ++it)
			delete *it;

		_shape.Clear();

		std::cout << "Total to the figures: " << Shape::Get_count() << std::endl;

		return 0;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
	return -1;
}