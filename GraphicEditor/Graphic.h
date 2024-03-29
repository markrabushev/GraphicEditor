#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Graphic {
public:
	virtual void Draw() = 0;
	virtual void Move(float x, float y) = 0;
	virtual const sf::Vector2f GetImageSize() = 0;
	virtual const sf::RectangleShape GetRectangle() = 0;
};

