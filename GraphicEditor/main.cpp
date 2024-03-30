#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ImageProxy.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1300, 900), L"����������� ��������", Style::Default);

    window.setVerticalSyncEnabled(true);

    Graphic* image = new ImageProxy("image.jpg");

    sf::Clock clock;
    sf::Time doubleClickDelay = sf::milliseconds(500);

    bool isDoubleClick = false;
    sf::Time lastClickTime;

    bool isMove = false;
    float dX = 0;
    float dY = 0;
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
                if (image->GetRectangle().getGlobalBounds().contains(pos.x, pos.y))
                {
                    dX = pos.x - image->GetRectangle().getPosition().x;
                    dY = pos.y - image->GetRectangle().getPosition().y;
                    isMove = true;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
            {
                if (clock.getElapsedTime() - lastClickTime < doubleClickDelay)
                {
                    isDoubleClick = true;
                }
                else
                {
                    isDoubleClick = false;
                }

                lastClickTime = clock.getElapsedTime();
                
            }
            else if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (isMove)
        {
            image->Move(pos.x - dX, pos.y - dY);
        }
        if (isDoubleClick)
        {
            image->Draw();
        }

        window.clear(Color::White);
        window.draw(image->GetRectangle());
        window.display();
    }
    delete image;
    return 0;
}