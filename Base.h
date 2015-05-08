#pragma once

#include <iostream>
#include <string>

class Named
{
public:	
	Named(char const * _name) : name(_name) {}
	virtual ~Named() {}
protected:
	std::string name;
};

class Printable : public virtual Named
{
public:
	Printable() : Named("") {}
	virtual ~Printable() {}
	void Print() { std::cout << name << std::endl; };
};