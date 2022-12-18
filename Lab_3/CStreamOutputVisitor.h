#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include "IShapeVisitor.h"

class CStreamOutputVisitor : public IShapeVisitor
{
public:
	CStreamOutputVisitor(std::ostream& out) :m_out(out) {}

	void Visit(CCircleDecorator const& circleDecorator) override;
	void Visit(CTriangleDecorator const& triangleDecorator) override;
	void Visit(CRectangleDecorator const& rectangleDecorator) override;
private:
	std::ostream& m_out;
};

