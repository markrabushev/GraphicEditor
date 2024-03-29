#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Graphic {
public:
	virtual void Draw(sf::RectangleShape& s) = 0;
	virtual void HandleMouse(sf::Event& event) = 0;
	virtual const sf::Vector2f GetImageSize() = 0;
};

