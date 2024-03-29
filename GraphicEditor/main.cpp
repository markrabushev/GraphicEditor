#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ImageProxy.h"

using namespace sf;

int main()
{

    RenderWindow window(VideoMode(1200, 800), L"Графический редактор", Style::Default);

    window.setVerticalSyncEnabled(true);

    Graphic* image = new ImageProxy("image.jpg");

    RectangleShape rectangle;
    rectangle.setSize(image->GetImageSize());
    rectangle.setPosition(500, 300);
    rectangle.setOutlineThickness(1.f);
    rectangle.setOutlineColor(Color::Black);

    bool isMove = false;
    float dX = 0;
    float dY = 0;
    sf::Vector2i mouse_position;
    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left )
            {
                isMove = false;
            }
            else if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                if (rectangle.getGlobalBounds().contains(pos.x, pos.y))
                {
                    dX = pos.x - rectangle.getPosition().x;
                    dY = pos.y - rectangle.getPosition().y;
                    isMove = true;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
            {
                image->Draw(rectangle);
            }
            else if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (isMove)
        {
            rectangle.setPosition(pos.x - dX, pos.y - dY);
        }


        window.clear(Color::White);
        window.draw(rectangle);
        window.display();
    }
    delete image;
    return 0;
}