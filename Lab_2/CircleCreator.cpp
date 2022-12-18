#include "CircleCreator.h"

unique_ptr<sf::Shape> CCircleCreator::Create(string& params) const
{
	istringstream paramsStream(params);
	int x, y, r;
	paramsStream >> x >> y >> r;
	sf::Vector2f vector(x, y);
	auto circleShape = make_unique<sf::CircleShape>(r);
	circleShape->setPosition(vector);
	circleShape->setFillColor(sf::Color(colorF, colorZero, colorZero));
	return circleShape;
};