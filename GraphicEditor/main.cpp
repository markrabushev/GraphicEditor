#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;

int main()
{

    RenderWindow window(VideoMode(1200, 800), L"����������� ��������", Style::Default);

    window.setVerticalSyncEnabled(true);

    RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    //shape.setPosition(100, 100);
    rectangle.setOutlineThickness(1.f);
    rectangle.setOutlineColor(Color::Black);
    
    bool isDraw = false;
    bool isMove = false;
    float dX = 0;
    float dY = 0;

    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                //CircleShape shape(100.f, 3);
                //rectangle.setPosition(event.mouseButton.x, event.mouseButton.y);
                isDraw = true;
                isMove = false;
                //shape.setFillColor(Color::Cyan);
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
    return 0;
}