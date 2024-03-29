#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct Point {
	double x, y;
	static Point Zero;
	bool operator == (const Point& right) const
	{
		return x == right.x && y == right.y;
	}
};
Point Point::Zero = { 0., 0. };

class Graphic {
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void HandleMouse(sf::Event& event) = 0;
	virtual const Point& GetExtent() = 0;
	virtual void Load(std::istream& from) = 0;
	virtual void Save(std::ostream& to) = 0;

};

