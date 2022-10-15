#pragma once

#include "ShapeDecorator.h"

class CTriangleDecorator : public CShapeDecorator
{
public:
	CTriangleDecorator(std::unique_ptr<sf::Shape>&& triangle)
		: CShapeDecorator(std::move(triangle))
	{
		point1 = m_shape->getPoint(0);
		point2 = m_shape->getPoint(1);
		point3 = m_shape->getPoint(2);
		length1 = CalculateSideLength(point1, point2);
		length2 = CalculateSideLength(point1, point3);
		length3 = CalculateSideLength(point3, point2);
	}
	std::string GetDescription()const override;
private:
	sf::Vector2f point1{ 0, 0 };
	sf::Vector2f point2{ 0, 0 };
	sf::Vector2f point3{ 0, 0 };
	double length1 = 0;
	double length2 = 0;
	double length3 = 0;
	double CalculateSideLength(sf::Vector2f point1, sf::Vector2f point2);
	int GetPerimeter() const;
	int GetArea() const;
};
