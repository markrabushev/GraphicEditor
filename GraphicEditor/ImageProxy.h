#pragma once
#include "ImageReal.h"

class ImageProxy : public Graphic {
public:
	ImageProxy(const char* imageFile)
	{
		fileName = _strdup(imageFile);
		/*rectangle.setPosition(500, 300);
		rectangle.setOutlineThickness(1.f);
		rectangle.setOutlineColor(sf::Color::Black);*/
		image = nullptr;
	}
	virtual ~ImageProxy()
	{
		if (image != nullptr) {
			delete image;
		}
	}
	virtual void Draw(sf::RectangleShape& s)
	{
		GetImage()->Draw(s);
	}
	virtual void Move(float x, float y)
	{
		GetImage()->Move(x, y);
	}
	virtual const sf::Vector2f GetImageSize() override
	{
		/*if (rectangle.getSize() == sf::Vector2f(0, 0))
			GetImage()->GetImageSize();
		else
			return rectangle.getSize();*/
		return GetImage()->GetImageSize();
	}

protected:
	ImageReal* GetImage()
	{
		if (image == nullptr) {
			image = new ImageReal(fileName);
		}
		return image;
	}
private:
	ImageReal* image;
	//sf::RectangleShape rectangle;
	char* fileName;
};
