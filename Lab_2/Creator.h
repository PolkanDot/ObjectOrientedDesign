#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>

using namespace std;

const int colorF = 0xFF;
const int colorZero = 0x0;
const int colorEight = 0x80;
const sf::Vector2f defoultPositionVector(100, 100);

class CShapeCreator
{
public:
	unique_ptr<sf::Shape> CreateFigure(string& parameters);
protected:
	virtual unique_ptr<sf::Shape> Create(string& paraams) const = 0;
};