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
#include "ShapeDecorator.h"


using namespace std;

const std::string circleType = "CIRCLE";
const std::string rectangleType = "RECTANGLE";
const std::string triangleType = "TRIANGLE";

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
	string shapeType;
	sf::RenderWindow window(sf::VideoMode({ 1000, 800 }), "Lab_1");
	window.clear();

    while (inputFile >> shapeType)
	{	
		if (shapeType == circleType)
		{
			int x, y, r;
			inputFile >> x >> y >> r;
			sf::Vector2f vector(x, y);
			auto circleShape = make_unique<sf::CircleShape>(r);
			circleShape->setPosition(vector);
			circleShape->setFillColor(sf::Color(0xFF, 0x0, 0x0));
			window.draw(*circleShape);
			auto circleDec = make_unique<CCircleDecorator>(move(circleShape), r);
			outputFile << circleDec->GetDescription() << endl;
		}

		if (shapeType == rectangleType)
		{
			int x1, y1, x2, y2;
			inputFile >> x1 >> y1 >> x2 >> y2;
			sf::Vector2f sizeVector(x2 - x1, y2 - y1);
			sf::Vector2f positionVector((x1 + x2) / 2, (y1 + y2) / 2);
			auto rectangleShape = make_unique<sf::RectangleShape>();
			rectangleShape->setSize(sizeVector);
			rectangleShape->setPosition(positionVector);
			rectangleShape->setFillColor(sf::Color(0x0, 0xFF, 0x0));
			window.draw(*rectangleShape);
			auto rectangleDec = make_unique<CRectangleDecorator>(move(rectangleShape), sizeVector);
			outputFile << rectangleDec->GetDescription() << endl;
		}

		if (shapeType == triangleType)
		{
			sf::Vector2f vector1, vector2, vector3;
			inputFile >> vector1.x >> vector1.y >> vector2.x >> vector2.y >> vector3.x >> vector3.y;
			auto triangleShape = make_unique<sf::ConvexShape>();
			triangleShape->setFillColor(sf::Color(0xFF, 0x80, 0));
			triangleShape->setPosition({ 100, 100 });
			triangleShape->setPointCount(3);
			triangleShape->setPoint(0, { vector1 });
			triangleShape->setPoint(1, { vector2 });
			triangleShape->setPoint(2, { vector3 });
			window.draw(*triangleShape);
			auto triangleDec = make_unique<CTriangleDecorator>(move(triangleShape));
			outputFile << triangleDec->GetDescription() << endl;
		}

	}
	window.display();
	sf::sleep(sf::seconds(4));
}



