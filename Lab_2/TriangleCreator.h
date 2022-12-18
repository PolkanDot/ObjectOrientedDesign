#pragma once
#include "Creator.h"

class CTriangleCreator : public CShapeCreator
{
protected:
	unique_ptr<sf::Shape> Create(string& params) const override;
};