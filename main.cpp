#include <iostream>
#include "chess.h"
#include "graphics.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Chess");
    //window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("../Textures/arial.ttf");

    CHESS::Game_Descriptor game;
    Game_Board board = Game_Board(game);
    board.setPosition(50.f, 50.f);

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if((603 <= event.mouseMove.x) && (event.mouseMove.x <= 933) && (3 <= event.mouseMove.y) && (event.mouseMove.y <= 43)){
                board.saveButton = true;
            }
            else{
                board.saveButton = false;
            }

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if((100 <= event.mouseButton.x) && (event.mouseButton.x <= 900) && (100 <= event.mouseButton.y) && (event.mouseButton.y <= 900)){
                        int ButtonPosX = event.mouseButton.x/100;
                        int ButtonPosY = event.mouseButton.y/100;

                        --ButtonPosX;
                        --ButtonPosY;

                        ButtonPosY = (7 - ButtonPosY);

                        if(!board.getSelected()){
                            board.selectPiece(ButtonPosX, ButtonPosY);
                        }
                        else{
                            if(ButtonPosX == board.selectedPiece.first && ButtonPosY == board.selectedPiece.second)
                                board.resetSelect();
                            else
                                board.moveSelected(ButtonPosX, ButtonPosY);
                        }
                    }
                    else if((603 <= event.mouseButton.x) && (event.mouseButton.x <= 933) && (3 <= event.mouseButton.y) && (event.mouseButton.y <= 43)){
                        game.history.saveToFile("../history.txt");
                    }
                }
            }
        }

        window.clear(sf::Color(205, 133, 63));
        window.draw(board);
        window.display();
    }
    return 0;
}
