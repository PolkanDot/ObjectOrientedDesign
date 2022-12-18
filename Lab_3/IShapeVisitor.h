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

class CCircleDecorator;
class CTriangleDecorator;
class CRectangleDecorator;

class IShapeVisitor
{
public:
	virtual void Visit(CCircleDecorator const& circleDecorator) = 0;
	virtual void Visit(CTriangleDecorator const& triangleDecorator) = 0;
	virtual void Visit(CRectangleDecorator const& rectangleDecorator) = 0;
	virtual ~IShapeVisitor() = default;
};

class CShapeDecorator
{
public:
	virtual std::string GetDescription()const = 0;
	virtual void Accept(IShapeVisitor& v)const = 0;
protected:
	CShapeDecorator(ShapePtr&& shape)
		: m_shape(move(shape))
	{
	}
	ShapePtr m_shape;
};

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(ShapePtr&& circle, int radiusValue)
		: CShapeDecorator(move(circle))
	{
		m_radius = radiusValue;
	}

	std::string GetDescription()const override;

	void Accept(IShapeVisitor& visitor)const override
	{
		visitor.Visit(*this);
	}

private:
	int m_radius = 0;

	int GetArea() const;

	int GetPerimeter() const;
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

	std::string GetDescription()const override;

	void Accept(IShapeVisitor& visitor)const override
	{
		visitor.Visit(*this);
	}

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

class CRectangleDecorator : public CShapeDecorator
{
public:
	CRectangleDecorator(std::unique_ptr<sf::Shape>&& rectangle, sf::Vector2f size)
		: CShapeDecorator(std::move(rectangle))
	{
		m_width = int(size.x);
		m_height = int(size.y);
	}

	std::string GetDescription()const override;

	void Accept(IShapeVisitor& visitor)const override
	{
		visitor.Visit(*this);
	}

private:
	int m_width = 0;
	int m_height = 0;

	int GetArea() const;

	int GetPerimeter() const;
};