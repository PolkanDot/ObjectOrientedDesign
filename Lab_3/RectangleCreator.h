#pragma once
#include "Creator.h"

class CRectangleCreator : public CShapeCreator
{
public:
	static CRectangleCreator& GetInstance()
	{
		static CRectangleCreator instance;
		return instance;
	}
	CRectangleCreator(const CRectangleCreator&) = delete;
	CRectangleCreator& operator=(const CRectangleCreator&) = delete;
private:
	CRectangleCreator()
	{
	}


protected:
	unique_ptr<sf::Shape> Create(string& params) const override;
};