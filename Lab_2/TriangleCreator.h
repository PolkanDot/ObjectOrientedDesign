#pragma once
#include "Creator.h"

class CTriangleCreator : public CShapeCreator
{
public:
	static CTriangleCreator& GetInstance()
	{
		static CTriangleCreator instance;
		return instance;
	}
	CTriangleCreator(const CTriangleCreator&) = delete;
	CTriangleCreator& operator=(const CTriangleCreator&) = delete;
private:
	CTriangleCreator()
	{
	}


protected:
	unique_ptr<sf::Shape> Create(string& params) const override;
};