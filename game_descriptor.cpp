#include "chess.h"

namespace CHESS{
    Game_Descriptor::Game_Descriptor(std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board, COLOR turn, STATUS status, VERDICT verdict){

    }

    Game_Descriptor::Game_Descriptor(){
        font.loadFromFile("../Textures/arial.ttf");

        status = GameIsOn;

        //WHITE
        std::pair<int, int> pR1 = {0, 0};
        Rook Rook1 = Rook(white, board, pR1);
        board[0][0] = std::make_unique<Rook>(Rook1);

        std::pair<int, int> pN1 = {1, 0};
        Knight Knight1 = Knight(white, board, pN1);
        board[1][0] = std::make_unique<Knight>(Knight1);

        std::pair<int, int> pB1 = {2, 0};
        Bishop Bishop1 = Bishop(white, board, pB1);
        board[2][0] = std::make_unique<Bishop>(Bishop1);

        std::pair<int, int> pQ = {3, 0};
        Queen Queen1 = Queen(white, board, pQ);
        board[3][0] = std::make_unique<Queen>(Queen1);

        std::pair<int, int> pK = {4, 0};
        King King1 = King(white, board, pK);
        board[4][0] = std::make_unique<King>(King1);

        std::pair<int, int> pB2 = {5, 0};
        Bishop Bishop2 = Bishop(white, board, pB2);
        board[5][0] = std::make_unique<Bishop>(Bishop2);

        std::pair<int, int> pN2 = {6, 0};
        Knight Knight2 = Knight(white, board, pN2);
        board[6][0] = std::make_unique<Knight>(Knight2);

        std::pair<int, int> pR2 = {7, 0};
        Rook Rook2 = Rook(white, board, pR2);
        board[7][0] = std::make_unique<Rook>(Rook2);

        std::pair<int, int> pP1 = {0, 1};
        Pawn Pawn1 = Pawn(white, board, pP1);
        board[0][1] = std::make_unique<Pawn>(Pawn1);

        std::pair<int, int> pP2 = {1, 1};
        Pawn Pawn2 = Pawn(white, board, pP2);
        board[1][1] = std::make_unique<Pawn>(Pawn2);

        std::pair<int, int> pP3 = {2, 1};
        Pawn Pawn3 = Pawn(white, board, pP3);
        board[2][1] = std::make_unique<Pawn>(Pawn3);

        std::pair<int, int> pP4 = {3, 1};
        Pawn Pawn4 = Pawn(white, board, pP4);
        board[3][1] = std::make_unique<Pawn>(Pawn4);

        std::pair<int, int> pP5 = {4, 1};
        Pawn Pawn5 = Pawn(white, board, pP5);
        board[4][1] = std::make_unique<Pawn>(Pawn5);

        std::pair<int, int> pP6 = {5, 1};
        Pawn Pawn6 = Pawn(white, board, pP6);
        board[5][1] = std::make_unique<Pawn>(Pawn6);

        std::pair<int, int> pP7 = {6, 1};
        Pawn Pawn7 = Pawn(white, board, pP7);
        board[6][1] = std::make_unique<Pawn>(Pawn7);

        std::pair<int, int> pP8 = {7, 1};
        Pawn Pawn8 = Pawn(white, board, pP8);
        board[7][1] = std::make_unique<Pawn>(Pawn8);

        //BLACK

        std::pair<int, int> pr1 = {0, 7};
        Rook rook1 = Rook(black, board, pr1);
        board[0][7] = std::make_unique<Rook>(rook1);

        std::pair<int, int> pn1 = {1, 7};
        Knight knight1 = Knight(black, board, pn1);
        board[1][7] = std::make_unique<Knight>(knight1);

        std::pair<int, int> pb1 = {2, 7};
        Bishop bishop1 = Bishop(black, board, pb1);
        board[2][7] = std::make_unique<Bishop>(bishop1);

        std::pair<int, int> pq = {3, 7};
        Queen queen1 = Queen(black, board, pq);
        board[3][7] = std::make_unique<Queen>(queen1);

        std::pair<int, int> pk = {4, 7};
        King king1 = King(black, board, pk);
        board[4][7] = std::make_unique<King>(king1);

        std::pair<int, int> pb2 = {5, 7};
        Bishop bishop2 = Bishop(black, board, pb2);
        board[5][7] = std::make_unique<Bishop>(bishop2);

        std::pair<int, int> pn2 = {6, 7};
        Knight knight2 = Knight(black, board, pn2);
        board[6][7] = std::make_unique<Knight>(knight2);

        std::pair<int, int> pr2 = {7, 7};
        Rook rook2 = Rook(black, board, pr2);
        board[7][7] = std::make_unique<Rook>(rook2);

        std::pair<int, int> pp1 = {0, 6};
        Pawn pawn1 = Pawn(black, board, pp1);
        board[0][6] = std::make_unique<Pawn>(pawn1);

        std::pair<int, int> pp2 = {1, 6};
        Pawn pawn2 = Pawn(black, board, pp2);
        board[1][6] = std::make_unique<Pawn>(pawn2);

        std::pair<int, int> pp3 = {2, 6};
        Pawn pawn3 = Pawn(black, board, pp3);
        board[2][6] = std::make_unique<Pawn>(pawn3);

        std::pair<int, int> pp4 = {3, 6};
        Pawn pawn4 = Pawn(black, board, pp4);
        board[3][6] = std::make_unique<Pawn>(pawn4);

        std::pair<int, int> pp5 = {4, 6};
        Pawn pawn5 = Pawn(black, board, pp5);
        board[4][6] = std::make_unique<Pawn>(pawn5);

        std::pair<int, int> pp6 = {5, 6};
        Pawn pawn6 = Pawn(black, board, pp6);
        board[5][6] = std::make_unique<Pawn>(pawn6);

        std::pair<int, int> pp7 = {6, 6};
        Pawn pawn7 = Pawn(black, board, pp7);
        board[6][6] = std::make_unique<Pawn>(pawn7);

        std::pair<int, int> pp8 = {7, 6};
        Pawn pawn8 = Pawn(black, board, pp8);
        board[7][6] = std::make_unique<Pawn>(pawn8);
    }

    void Game_Descriptor::makeMove(std::pair<int, int> square0, std::pair<int, int> square){
        if(board[square0.first][square0.second] == nullptr){
            throw std::invalid_argument("Empty square");
        }
        else if(!board[square0.first][square0.second]->checkMove(square)){
            throw std::invalid_argument("Not available moves");
        }
        else{
            board[square.first][square.second] = std::move(board[square0.first][square0.second]);
        }
    }

    void Game_Descriptor::addPiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece){
        if(board[square.first][square.second] != nullptr){
            throw std::invalid_argument("Busy square");
        }
        else{
            board[square.first][square.second] = std::move(piece);
        }
    }

    void Game_Descriptor::deletePiece(std::pair<int, int> square){
        if(board[square.first][square.second] == nullptr){
            throw std::invalid_argument("Empty square");
        }
        else{
            board[square.first][square.second] = nullptr;
        }
    }

    void Game_Descriptor::changePiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece){
        this->deletePiece(square);
        this->addPiece(square, piece);
    }

    void Game_Descriptor::draw(sf::RenderTarget& target, sf::RenderStates states) const{
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
                if(board[i][j] != nullptr)
                    name = board[i][j]->getShortName();
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
                piecesprite.setPosition((7 - i) * SQUARE_SIZE + 100.f, (7 - j) * SQUARE_SIZE + 100.f);

                target.draw(piecesprite);

            }
        }
    }
}
