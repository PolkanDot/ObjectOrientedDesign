#pragma once

#include "ShapeDecorator.h"

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
private:
	int m_width = 0;
	int m_height = 0;

	int GetArea() const;

	int GetPerimeter() const;
};