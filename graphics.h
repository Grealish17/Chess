#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>
#include <SFML/Graphics.hpp>

const int FIELD_SIZE = 800;
const int SQUARE_SIZE = 100;

class Game_Board : public sf::Drawable, public sf::Transformable{
private:
    CHESS::Game_Descriptor& game;
    sf::Font font;
public:
    explicit Game_Board(CHESS::Game_Descriptor& game);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class PieceTextures{
public:
    static sf::Texture blackKing;
    static sf::Texture blackQueen;
    static sf::Texture blackRook;
    static sf::Texture blackKnight;
    static sf::Texture blackBishop;
    static sf::Texture blackPawn;

    static sf::Texture whiteKing;
    static sf::Texture whiteQueen;
    static sf::Texture whiteRook;
    static sf::Texture whiteKnight;
    static sf::Texture whiteBishop;
    static sf::Texture whitePawn;

    static sf::Texture loadTexture(const std::string& str);
};