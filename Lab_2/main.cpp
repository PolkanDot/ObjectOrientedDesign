#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "CircleDecorator.h"
#include "RectangleDecorator.h"
#include "TriangleDecorator.h"
#include "CircleCreator.h"
#include "TriangleCreator.h"
#include "RectangleCreator.h"

using namespace std;

const std::string circleType = "CIRCLE";
const std::string rectangleType = "RECTANGLE";
const std::string triangleType = "TRIANGLE";
const unsigned int windowHeight = 800;
const unsigned int windowWidth = 1000;

int main()
{
	ifstream inputFile;
	inputFile.open("input.txt");

	if (!inputFile.is_open())
	{
		cout << "Failed to open input.txt for reading\n";
		return 1;
	}

	ofstream outputFile;
	outputFile.open("output.txt");

	if (!outputFile.is_open())
	{
		cout << "Failed to open output.txt for writing\n";
		return 1;
	}

	int zero = 0;
	string shapeType, params;
	sf::RenderWindow window(sf::VideoMode({ windowWidth, windowHeight }), "Lab_2");
	window.clear();

	while (getline(inputFile, params))
	{
		istringstream paramsStream(params);
		paramsStream >> shapeType;
		if (shapeType == circleType)
		{
			int x, y, r;
			paramsStream >> x >> y >> r;
			params.erase(0, 7);
			auto& circleCreator = CCircleCreator::GetInstance();
			auto circleShape = circleCreator.CreateFigure(params);
			window.draw(*circleShape);
			auto circleDec = make_unique<CCircleDecorator>(move(circleShape), r);
			outputFile << circleDec->GetDescription() << endl;
		}

		if (shapeType == rectangleType)
		{
			int x1, y1, x2, y2;
			paramsStream >> x1 >> y1 >> x2 >> y2;
			sf::Vector2f sizeVector(x2 - x1, y2 - y1);
			params.erase(0, 10);
			auto& rectangleCreator = CRectangleCreator::GetInstance();
			auto rectangleShape = rectangleCreator.CreateFigure(params);
			window.draw(*rectangleShape);
			auto rectangleDec = make_unique<CRectangleDecorator>(move(rectangleShape), sizeVector);
			outputFile << rectangleDec->GetDescription() << endl;
		}

		if (shapeType == triangleType)
		{
			params.erase(0, 9);
			auto& triangleCreator = CTriangleCreator::GetInstance();
			auto triangleShape = triangleCreator.CreateFigure(params);
			window.draw(*triangleShape);
			auto triangleDec = make_unique<CTriangleDecorator>(move(triangleShape));
			outputFile << triangleDec->GetDescription() << endl;
		}

	}
	window.display();
	sf::sleep(sf::seconds(4));
}