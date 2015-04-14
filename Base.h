#pragma once

#include <iostream>
#include <string>

class Named
{
public:
	Named() {}
	Named(char const * _name) : name(_name) {}
	~Named() {}
protected:
	std::string name;
};

class Printable : public virtual Named
{
public:
	Printable() {}
	Printable(char const * _name) : Named(_name) {}
	~Printable() {}
	void Print() { std::cout << name << std::endl; };
};