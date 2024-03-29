#pragma once
#include "ImageReal.h"

class ImageProxy : public Graphic {
public:
	ImageProxy(const char* imageFile)
	{
		fileName = _strdup(imageFile);
		extent = Point::Zero; 
		image = 0;
	}
	virtual ~ImageProxy()
	{
		if (image != nullptr) {
			delete image;
		}
	}
	virtual void Draw(sf::RenderWindow& window)
	{
		GetImage()->Draw(window);
	}
	virtual void HandleMouse(sf::Event& event)
	{
		GetImage()->HandleMouse(event);
	}
	virtual const Point& GetExtent()
	{
		if (extent == Point::Zero) {
			extent = GetImage()->GetExtent();
		}
		return extent;
	}
	virtual void Load(std::istream& from) {};
	virtual void Save(std::ostream& to) {};
protected:
	ImageReal* GetImage()
	{
		if (image == 0) {
			image = new ImageReal(fileName);
		}
		return image;
	}
private:
	ImageReal* image;
	Point extent;
	char* fileName;
};
