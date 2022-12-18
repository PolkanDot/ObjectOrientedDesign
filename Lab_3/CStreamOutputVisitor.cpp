#include "CStreamOutputVisitor.h"

void CStreamOutputVisitor::Visit(CCircleDecorator const& circleDecorator)
{
	m_out << circleDecorator.GetDescription() << std::endl;
}

void CStreamOutputVisitor::Visit(CTriangleDecorator const& triangleDecorator)
{
	m_out << triangleDecorator.GetDescription() << std::endl;
}

void CStreamOutputVisitor::Visit(CRectangleDecorator const& rectangleDecorator)
{
	m_out << rectangleDecorator.GetDescription() << std::endl;
}