#pragma once
#include "Graphic.h"

class ImageReal : public Graphic {
public:
	ImageReal(const char* file)
	{
		if (!texture.loadFromFile(file)) {
			std::cerr << "Error loading image" << std::endl;
		}
		rectangle.setSize((sf::Vector2f)texture.getSize());
		rectangle.setPosition(500, 300);
		rectangle.setOutlineThickness(1.f);
		rectangle.setOutlineColor(sf::Color::Black);
	}
	virtual ~ImageReal() {};
	virtual void Draw() override
	{
		rectangle.setTexture(&texture);
	}
	virtual void Move(float x, float y)
	{
		rectangle.setPosition(x, y);
	}
	virtual const sf::Vector2f GetImageSize() override
	{
		return (sf::Vector2f)texture.getSize();
	}
	virtual const sf::RectangleShape GetRectangle()
	{
		return rectangle;
	}

private:
	sf::Texture texture;
	sf::RectangleShape rectangle;
};