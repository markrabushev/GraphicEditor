#pragma once
#include "Graphic.h"

class ImageReal : public Graphic {
public:
	ImageReal(const char* file)
	{
		if (!texture.loadFromFile(file)) {
			std::cerr << "Error loading image" << std::endl;
		}
	}
	virtual ~ImageReal() {};
	virtual void Draw(sf::RectangleShape& s) override
	{
		s.setTexture(&texture);
	}
	virtual void HandleMouse(sf::Event& event) {};
	virtual const sf::Vector2f GetImageSize() override
	{
		return (sf::Vector2f)texture.getSize();
	}

private:
	sf::Texture texture;
};