#pragma once
#include "Creator.h"

class CCircleCreator : public CShapeCreator
{
public:
	static CCircleCreator& GetInstance()
	{
		static CCircleCreator instance;
		return instance;
	}
	CCircleCreator(const CCircleCreator&) = delete;
	CCircleCreator& operator=(const CCircleCreator&) = delete;
private:
	CCircleCreator()
	{
	}


protected:
	unique_ptr<sf::Shape> Create(string& params) const override;
};