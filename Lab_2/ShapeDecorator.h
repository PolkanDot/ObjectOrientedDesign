#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

typedef std::unique_ptr<sf::Shape> ShapePtr;
const double PI = acos(-1.0);

const std::string circle = "Circle ";
const std::string rectangle = "Rectangle ";
const std::string triangle = "Triangle ";
const std::string perimeter = "Perimeter: ";
const std::string area = "Area: ";
const std::string space = " ";

class CShapeDecorator
{
public:
	virtual std::string GetDescription()const = 0;
protected:
	CShapeDecorator(ShapePtr&& shape)
		: m_shape(move(shape))
	{
	}
	ShapePtr m_shape;	
};


