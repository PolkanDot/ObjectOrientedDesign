#pragma once
#include "Creator.h"

class CRectangleCreator : public CShapeCreator
{
protected:
	unique_ptr<sf::Shape> Create(string& params) const override;
};