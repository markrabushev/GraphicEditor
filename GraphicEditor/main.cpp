#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ImageProxy.h"

using namespace sf;

int main()
{

    RenderWindow window(VideoMode(1200, 800), L"Графический редактор", Style::Default);

    window.setVerticalSyncEnabled(true);

    Graphic* rect = new ImageProxy("image.jpg");
    
    /*Texture p;
    if (!p.loadFromFile("image.jpg")) {
        std::cerr << "Error loading image" << std::endl;
    }*/
    /*Point size = p.GetExtent();
    Vector2f s;
    s.x = size.x;
    s.y = size.y;*/
    RectangleShape rectangle;
    rectangle.setSize(rect->GetImageSize());
    rectangle.setPosition(500, 300);
    rectangle.setOutlineThickness(1.f);
    rectangle.setOutlineColor(Color::Black);
    

    bool isDraw = false;
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
                /*if (!isDraw) {
                    startPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    isDraw = true;
                }
                else {
                    endPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    box.setPosition(startPos);
                    box.setOutlineThickness(1.f);
                    box.setSize(endPos - startPos);
                    window.draw(box);
                    isDraw = false;
                }*/
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
                isDraw = true;
                //p.Draw(window);
                //rectangle.setTexture(&p);
                rect->Draw(rectangle);
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
        //if(isDraw) p.Draw(window);
        window.display();
    }
    delete rect;
    return 0;
}