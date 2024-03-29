#pragma once
#include "ImageReal.h"

class ImageProxy : public Graphic {
public:
	ImageProxy(const char* imageFile)
	{
		fileName = _strdup(imageFile);
		image = nullptr;
	}
	virtual ~ImageProxy()
	{
		if (image != nullptr) {
			delete image;
		}
	}
	virtual void Draw()
	{
		GetImage()->Draw();
	}
	virtual void Move(float x, float y)
	{
		GetImage()->Move(x, y);
	}
	virtual const sf::Vector2f GetImageSize() override
	{
		return GetImage()->GetImageSize();
	}
	virtual const sf::RectangleShape GetRectangle()
	{
		return GetImage()->GetRectangle();
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
	char* fileName;
};
