#pragma once

#include "ShapeDecorator.h"

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(ShapePtr&& circle, int radiusValue)
		: CShapeDecorator(move(circle))
	{
		m_radius = radiusValue;
	}
	std::string GetDescription()const override;
private:
	int m_radius = 0;

	int GetArea() const;

	int GetPerimeter() const;
};