#include "RectangleCreator.h"

unique_ptr<sf::Shape> CRectangleCreator::Create(string& params) const
{
	istringstream paramsStream(params);
	int x1, y1, x2, y2;
	paramsStream >> x1 >> y1 >> x2 >> y2;
	sf::Vector2f sizeVector(x2 - x1, y2 - y1);
	sf::Vector2f positionVector((x1 + x2) / 2, (y1 + y2) / 2);
	auto rectangleShape = make_unique<sf::RectangleShape>();
	rectangleShape->setSize(sizeVector);
	rectangleShape->setPosition(positionVector);
	rectangleShape->setFillColor(sf::Color(colorZero, colorF, colorZero));
	return rectangleShape;
};