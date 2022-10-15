#include "CircleDecorator.h"

int CCircleDecorator::GetArea() const
{
	return PI * m_radius * m_radius;
}
int CCircleDecorator::GetPerimeter() const
{
	return 2 * PI * m_radius;
}
std::string CCircleDecorator::GetDescription()const
{
	return circle + perimeter + std::to_string(GetPerimeter()) + space + area + std::to_string(GetArea());
}