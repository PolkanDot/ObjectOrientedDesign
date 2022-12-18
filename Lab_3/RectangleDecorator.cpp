#include "IShapeVisitor.h"

int CRectangleDecorator::GetArea() const
{
	return m_width * m_height;
}
int CRectangleDecorator::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}
std::string CRectangleDecorator::GetDescription()const
{
	return rectangle + perimeter + std::to_string(GetPerimeter()) + space + area + std::to_string(GetArea());
}