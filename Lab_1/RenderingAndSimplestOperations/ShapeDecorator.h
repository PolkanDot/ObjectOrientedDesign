#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>

typedef std::unique_ptr<sf::Shape> ShapePtr;

const std::string circle = "Circle ";
const std::string rectangle = "Rectangle ";
const std::string triangle = "Triangle ";
const std::string perimeter = "Perimeter: ";
const std::string area = "Area: ";
const std::string space = " ";

class CShapeDecorator
{
public:
	ShapePtr m_shape;
	virtual std::string GetDescription()const = 0;
protected:
	CShapeDecorator(ShapePtr&& shape)
		: m_shape(move(shape))
	{
	}
};

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(ShapePtr&& circle, int radiusValue)
		: CShapeDecorator(move(circle))
	{
		m_radius = radiusValue;
	}
	std::string GetDescription()const override
	{
		return circle + perimeter + std::to_string(GetPerimeter()) + space + area + std::to_string(GetArea());
	}
private:
	int m_radius = 0;
	
	int GetArea() const
	{
		return 3.14 * m_radius * m_radius;
	}
	int GetPerimeter() const
	{
		return 2 * 3.14 * m_radius;
	}
};

class CRectangleDecorator : public CShapeDecorator
{
public:
	CRectangleDecorator(std::unique_ptr<sf::Shape>&& rectangle, sf::Vector2f size)
		: CShapeDecorator(std::move(rectangle))
	{
		m_width = int(size.x);
		m_height = int(size.y);
	}
	std::string GetDescription()const override
	{
		return rectangle + perimeter + std::to_string(GetPerimeter()) + space + area + std::to_string(GetArea());
	}
private:
	int m_width = 0;
	int m_height = 0;

	int GetArea() const
	{
		return m_width * m_height;
	}
	int GetPerimeter() const
	{
		return 2 * (m_width + m_height);
	}
};

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
	std::string GetDescription()const override
	{
		return triangle + perimeter + std::to_string(GetPerimeter()) + space + area + std::to_string(GetArea());
	}
private:
	sf::Vector2f point1{ 0, 0 };
	sf::Vector2f point2{ 0, 0 };
	sf::Vector2f point3{ 0, 0 };
	double length1 = 0;
	double length2 = 0;
	double length3 = 0;
	double CalculateSideLength(sf::Vector2f point1, sf::Vector2f point2)
	{
		return (double(sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y))));
	}
	int GetPerimeter() const
	{
		return int(length1 + length2 + length3);
	}
	int GetArea() const
	{
		return int(0.5 * abs(((point2.x - point1.x) * (point3.y - point1.y)) - ((point3.x - point1.x) * (point2.y - point1.y))));
	}
};


