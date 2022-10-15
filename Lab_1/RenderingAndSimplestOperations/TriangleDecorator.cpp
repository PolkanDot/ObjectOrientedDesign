#include "TriangleDecorator.h"

double CTriangleDecorator::CalculateSideLength(sf::Vector2f point1, sf::Vector2f point2)
{
	return (double(sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y))));
}
int CTriangleDecorator::GetPerimeter() const
{
	return int(length1 + length2 + length3);
}
int CTriangleDecorator::GetArea() const
{
	return int(0.5 * abs(((point2.x - point1.x) * (point3.y - point1.y)) - ((point3.x - point1.x) * (point2.y - point1.y))));
}
std::string CTriangleDecorator::GetDescription()const
{
	return triangle + perimeter + std::to_string(GetPerimeter()) + space + area + std::to_string(GetArea());
}