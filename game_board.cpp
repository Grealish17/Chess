#include "chess.h"
#include "graphics.h"
#include <SFML/Graphics.hpp>

    Game_Board::Game_Board(CHESS::Game_Descriptor& game): game(game), selected(false){
    font.loadFromFile("../Textures/arial.ttf");
}

void Game_Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    sf::Color color = sf::Color(139, 69, 19);

    sf::Texture boardtexture;
    boardtexture.loadFromFile("../Textures/chessboard.png");

    sf::Sprite boardsprite;
    boardsprite.setTexture(boardtexture);
    boardsprite.setPosition(50, 50);
    target.draw(boardsprite, states);

    sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
    shape.setOutlineThickness(50.f);
    shape.setPosition(50.f, 50.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    target.draw(shape, states);

    sf::Text text("", font, 50);
    text.setFillColor(sf::Color::White);

    text.setString(CHESS::to_string(game.verdict));
    text.setPosition(-50.f, -60.f);
    target.draw(text, states);

    text.setString(CHESS::to_string(game.status));
    text.setPosition(300.f, -60.f);
    target.draw(text, states);

    std::string letter(" ");
    for (int i = 0; i < 8; i++) {
        letter[0] = 'a' + i;
        text.setString(letter);
        text.setPosition(90.f + SQUARE_SIZE * i, 840.f);
        target.draw(text, states);
    }
    for (int i = 0; i < 8; i++) {
        letter[0] = 'a' + i;
        text.setString(letter);
        text.setPosition(90.f + SQUARE_SIZE * i, -10.f);
        target.draw(text, states);
    }
    for (int i = 1; i < 9; i++) {
        letter[0] = '0' + i;
        text.setString(letter);
        text.setPosition(860.f, 70.f + SQUARE_SIZE * (8-i));
        target.draw(text, states);
    }
    for (int i = 1; i < 9; i++) {
        letter[0] = '0' + i;
        text.setString(letter);
        text.setPosition(10.f, 70.f + SQUARE_SIZE * (8-i));
        target.draw(text, states);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char name;
            if(game.board[i][j] != nullptr)
                name = game.board[i][j]->getShortName();
            else
                name = ' ';
            sf::Texture piecetexture;
            switch (name)
            {
                case 'K':
                    piecetexture = PieceTextures::whiteKing;
                    break;
                case 'Q':
                    piecetexture = PieceTextures::whiteQueen;
                    break;
                case 'R':
                    piecetexture = PieceTextures::whiteRook;
                    break;
                case 'B':
                    piecetexture = PieceTextures::whiteBishop;
                    break;
                case 'N':
                    piecetexture = PieceTextures::whiteKnight;
                    break;
                case 'P':
                    piecetexture = PieceTextures::whitePawn;
                    break;
                case 'k':
                    piecetexture = PieceTextures::blackKing;
                    break;
                case 'q':
                    piecetexture = PieceTextures::blackQueen;
                    break;
                case 'r':
                    piecetexture = PieceTextures::blackRook;
                    break;
                case 'b':
                    piecetexture = PieceTextures::blackBishop;
                    break;
                case 'n':
                    piecetexture = PieceTextures::blackKnight;
                    break;
                case 'p':
                    piecetexture = PieceTextures::blackPawn;
                    break;
                default:
                    break;
            }

            sf::Sprite piecesprite;
            piecesprite.setTexture(piecetexture);
            if(selectedPiece.first == i && selectedPiece.second == j)
                piecesprite.setColor(sf::Color(255, 255, 255, 128));
            piecesprite.setPosition(i * SQUARE_SIZE + 100.f, (7 - j) * SQUARE_SIZE + 100.f);

            target.draw(piecesprite);

        }
    }
}

bool Game_Board::getSelected() const{
    return selected;
}

void Game_Board::resetSelect(){
    selected = false;
    selectedPiece = {-1, -1};
}

bool Game_Board::selectPiece(int pos_x, int pos_y){
    if(game.board[pos_x][pos_y] != nullptr){
        if(game.board[pos_x][pos_y]->get_color() == game.turn){
            selectedPiece = {pos_x, pos_y};
            selected = true;
        }
    }
    return selected;
}

bool Game_Board::moveSelected(int pos_x, int pos_y){
    try{
        game.makeMove(selectedPiece, {pos_x, pos_y});
        selected = false;
    }
    catch(std::invalid_argument& exception){
        return false;
    }
    return true;
}