#pragma once
#include "Graphic.h"

class ImageReal : public Graphic {
public:
	ImageReal(const char* file)
	{
		if (!texture.loadFromFile(file)) {
			std::cerr << "Error loading image" << std::endl;
		}
		sprite.setTexture(texture);
	}
	virtual ~ImageReal() {};
	virtual void Draw(sf::RenderWindow& window) override
	{
		window.draw(sprite);
	}
	virtual void HandleMouse(sf::Event& event) {};
	virtual const Point& GetExtent()
	{
		Point p;
		p.x = texture.getSize().x;
		p.y = texture.getSize().y;
		return p;
	}
	virtual void Load(std::istream& from) {};
	virtual void Save(std::ostream& to) {};
private:
	sf::Texture texture;
	sf::Sprite sprite;
};