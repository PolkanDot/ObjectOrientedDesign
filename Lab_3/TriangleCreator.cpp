#include "TriangleCreator.h"

unique_ptr<sf::Shape> CTriangleCreator::Create(string& params) const
{
	istringstream paramsStream(params);
	sf::Vector2f vector1, vector2, vector3;
	paramsStream >> vector1.x >> vector1.y >> vector2.x >> vector2.y >> vector3.x >> vector3.y;
	auto triangleShape = make_unique<sf::ConvexShape>();
	triangleShape->setFillColor(sf::Color(colorF, colorEight, colorZero));
	triangleShape->setPosition(defoultPositionVector);
	triangleShape->setPointCount(3);
	triangleShape->setPoint(0, { vector1 });
	triangleShape->setPoint(1, { vector2 });
	triangleShape->setPoint(2, { vector3 });
	return triangleShape;
};