#pragma once

#include <iostream>
#include <string>

class Named
{
public:	
	Named(std::string const _name) : name(_name) {}
protected:
	std::string name;
};

class Printable : public virtual Named
{
public:
	Printable() : Named("") {}
	virtual void Print(std::ostream & _stream) const { _stream << name << " "; };
	friend std::ostream & operator<< (std::ostream & ioStream, Printable const & _printable);
};