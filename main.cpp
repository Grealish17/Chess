#include <iostream>
#include "chess.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Chess");
    //window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("../Textures/arial.ttf");

    CHESS::Game_Descriptor game;
    game.setPosition(50.f, 50.f);

    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    sf::Event event;

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if((0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512)){
                        unsigned int buttonPos{(event.mouseButton.x/64) + ((event.mouseButton.y/64) * (8 * (512/window.getSize().y)))};

                        if(!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    }
                    else if((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)){
                        chess.restart();
                    }
                }
            }
        }

        window.clear(sf::Color(205, 133, 63));
        window.draw(game);
        window.display();
    }
    return 0;
}
