#include "Creator.h"

unique_ptr<sf::Shape> CShapeCreator::CreateFigure(string& parameters)
{
	auto figure = Create(parameters);
	return figure;
};