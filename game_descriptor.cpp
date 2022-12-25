#include "chess.h"

namespace CHESS{
    Game_Descriptor::Game_Descriptor(Game_Descriptor& game): turn(game.turn), verdict(game.verdict), status(game.status),
                                                             history(game.history){
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if(game.board[i][j] != nullptr){
                    char name = game.board[i][j]->getShortName();
                    switch (name)
                    {
                        case 'K': {
                            std::pair<int, int> pK = {i, j};
                            board[i][j] = std::make_unique<King>(King(white, *this, pK));
                            break;
                        }
                        case 'Q': {
                            std::pair<int, int> pQ = {i, j};
                            board[i][j] = std::make_unique<Queen>(Queen(white, *this, pQ));
                            break;
                        }
                        case 'R': {
                            std::pair<int, int> pR1 = {i, j};
                            board[i][j] = std::make_unique<Rook>(Rook(white, *this, pR1));
                            break;
                        }
                        case 'B': {
                            std::pair<int, int> pB1 = {i, j};
                            board[i][j] = std::make_unique<Bishop>(Bishop(white, *this, pB1));
                            break;
                        }
                        case 'N': {
                            std::pair<int, int> pN1 = {i, j};
                            board[i][j] = std::make_unique<Knight>(Knight(white, *this, pN1));
                            break;
                        }
                        case 'P': {
                            std::pair<int, int> pP1 = {i, j};
                            board[i][j] = std::make_unique<Pawn>(Pawn(white, *this, pP1));
                            break;
                        }
                        case 'k': {
                            std::pair<int, int> pk = {i, j};
                            board[i][j] = std::make_unique<King>(King(black, *this, pk));
                            break;
                        }
                        case 'q': {
                            std::pair<int, int> pq = {i, j};
                            board[i][j] = std::make_unique<Queen>(Queen(black, *this, pq));
                            break;
                        }
                        case 'r': {
                            std::pair<int, int> pr1 = {i, j};
                            board[i][j] = std::make_unique<Rook>(Rook(black, *this, pr1));
                            break;
                        }
                        case 'b': {
                            std::pair<int, int> pb1 = {i, j};
                            board[i][j] = std::make_unique<Bishop>(Bishop(black, *this, pb1));
                            break;
                        }
                        case 'n': {
                            std::pair<int, int> pn1 = {i, j};
                            board[i][j] = std::make_unique<Knight>(Knight(black, *this, pn1));
                            break;
                        }
                        case 'p': {
                            std::pair<int, int> pp1 = {i, j};
                            board[i][j] = std::make_unique<Pawn>(Pawn(black, *this, pp1));
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        }
    }

    Game_Descriptor::Game_Descriptor(){
        status = GameIsOn;

        //WHITE
        std::pair<int, int> pR1 = {0, 0};
        board[0][0] = std::make_unique<Rook>(Rook(white, *this, pR1));

        std::pair<int, int> pN1 = {1, 0};
        board[1][0] = std::make_unique<Knight>(Knight(white, *this, pN1));

        std::pair<int, int> pB1 = {2, 0};
        board[2][0] = std::make_unique<Bishop>(Bishop(white, *this, pB1));

        std::pair<int, int> pQ = {3, 0};
        board[3][0] = std::make_unique<Queen>(Queen(white, *this, pQ));

        std::pair<int, int> pK = {4, 0};
        board[4][0] = std::make_unique<King>(King(white, *this, pK));

        std::pair<int, int> pB2 = {5, 0};
        board[5][0] = std::make_unique<Bishop>(Bishop(white, *this, pB2));

        std::pair<int, int> pN2 = {6, 0};
        board[6][0] = std::make_unique<Knight>(Knight(white, *this, pN2));

        std::pair<int, int> pR2 = {7, 0};
        board[7][0] = std::make_unique<Rook>(Rook(white, *this, pR2));

        std::pair<int, int> pP1 = {0, 1};
        board[0][1] = std::make_unique<Pawn>(Pawn(white, *this, pP1));

        std::pair<int, int> pP2 = {1, 1};
        board[1][1] = std::make_unique<Pawn>(Pawn(white, *this, pP2));

        std::pair<int, int> pP3 = {2, 1};
        board[2][1] = std::make_unique<Pawn>(Pawn(white, *this, pP3));

        std::pair<int, int> pP4 = {3, 1};
        board[3][1] = std::make_unique<Pawn>(Pawn(white, *this, pP4));

        std::pair<int, int> pP5 = {4, 1};
        board[4][1] = std::make_unique<Pawn>(Pawn(white, *this, pP5));

        std::pair<int, int> pP6 = {5, 1};
        board[5][1] = std::make_unique<Pawn>(Pawn(white, *this, pP6));

        std::pair<int, int> pP7 = {6, 1};
        board[6][1] = std::make_unique<Pawn>(Pawn(white, *this, pP7));

        std::pair<int, int> pP8 = {7, 1};
        board[7][1] = std::make_unique<Pawn>(Pawn(white, *this, pP8));

        //BLACK

        std::pair<int, int> pr1 = {0, 7};
        board[0][7] = std::make_unique<Rook>(Rook(black, *this, pr1));

        std::pair<int, int> pn1 = {1, 7};
        board[1][7] = std::make_unique<Knight>(Knight(black, *this, pn1));

        std::pair<int, int> pb1 = {2, 7};
        board[2][7] = std::make_unique<Bishop>(Bishop(black, *this, pb1));

        std::pair<int, int> pq = {3, 7};
        board[3][7] = std::make_unique<Queen>(Queen(black, *this, pq));

        std::pair<int, int> pk = {4, 7};
        board[4][7] = std::make_unique<King>(King(black, *this, pk));

        std::pair<int, int> pb2 = {5, 7};
        board[5][7] = std::make_unique<Bishop>(Bishop(black, *this, pb2));

        std::pair<int, int> pn2 = {6, 7};
        board[6][7] = std::make_unique<Knight>(Knight(black, *this, pn2));

        std::pair<int, int> pr2 = {7, 7};
        board[7][7] = std::make_unique<Rook>(Rook(black, *this, pr2));

        std::pair<int, int> pp1 = {0, 6};
        board[0][6] = std::make_unique<Pawn>(Pawn(black, *this, pp1));

        std::pair<int, int> pp2 = {1, 6};
        board[1][6] = std::make_unique<Pawn>(Pawn(black, *this, pp2));

        std::pair<int, int> pp3 = {2, 6};
        board[2][6] = std::make_unique<Pawn>(Pawn(black, *this, pp3));

        std::pair<int, int> pp4 = {3, 6};
        board[3][6] = std::make_unique<Pawn>(Pawn(black, *this, pp4));

        std::pair<int, int> pp5 = {4, 6};
        board[4][6] = std::make_unique<Pawn>(Pawn(black, *this, pp5));

        std::pair<int, int> pp6 = {5, 6};
        board[5][6] = std::make_unique<Pawn>(Pawn(black, *this, pp6));

        std::pair<int, int> pp7 = {6, 6};
        board[6][6] = std::make_unique<Pawn>(Pawn(black, *this, pp7));

        std::pair<int, int> pp8 = {7, 6};
        board[7][6] = std::make_unique<Pawn>(Pawn(black, *this, pp8));
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
            board[square.first][square.second]->setPosition(square);
            inverse(turn);
            history.addMove(board[square.first][square.second]->toNotation(square));
            if(this->CheckCheckmate(turn)){
                verdict = Checkmate;
                if(turn == white)
                    status = BlackWin;
                else
                    status = WhiteWin;
            }
            else if(this->CheckCheck(turn)){
                verdict = Check;
            }
            else if(this->CheckStalemate(turn)){
                verdict = Stalemate;
                status = Draw;
            }
            else{
                verdict = Nothing;
                status = GameIsOn;
            }
            if(board[square.first][square.second]->getShortName() == 'p' && square.second == 0){
                changePiece(square, 'q');
            }
            else if(board[square.first][square.second]->getShortName() == 'P' && square.second == 7){
                changePiece(square, 'Q');
            }
        }
    }

    void Game_Descriptor::addPiece(std::pair<int, int> square, char shortname){
        if(board[square.first][square.second] != nullptr){
            throw std::invalid_argument("Busy square");
        }
        else{
            switch (shortname)
            {
                case 'K': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<King>(King(white, *this, pK));
                    break;
                }
                case 'Q': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Queen>(Queen(white, *this, pK));
                    break;
                }
                case 'R': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Rook>(Rook(white, *this, pK));
                    break;
                }
                case 'B': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Bishop>(Bishop(white, *this, pK));
                    break;
                }
                case 'N': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Knight>(Knight(white, *this, pK));
                    break;
                }
                case 'P': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Pawn>(Pawn(white, *this, pK));
                    break;
                }
                case 'k': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<King>(King(black, *this, pK));
                    break;
                }
                case 'q': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Queen>(Queen(black, *this, pK));
                    break;
                }
                case 'r': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Rook>(Rook(black, *this, pK));
                    break;
                }
                case 'b': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Bishop>(Bishop(black, *this, pK));
                    break;
                }
                case 'n': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Knight>(Knight(black, *this, pK));
                    break;
                }
                case 'p': {
                    std::pair<int, int> pK = {square.first, square.first};
                    board[square.first][square.second] = std::make_unique<Pawn>(Pawn(black, *this, pK));
                    break;
                }
                default:
                    break;
            }
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

    void Game_Descriptor::changePiece(std::pair<int, int> square, char shortname){
        this->deletePiece(square);
        this->addPiece(square, shortname);
    }

    bool Game_Descriptor::CheckCheck(COLOR color){
        if(color == white){
            std::pair<int, int> pos;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if(board[i][j] != nullptr){
                        if(board[i][j]->getShortName() == 'K'){
                            pos = {i, j};
                        }
                    }
                }
            }

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if(board[i][j] != nullptr){
                        if(board[i][j]->get_color() == black){
                            std::vector<std::pair<int, int>> moves = board[i][j]->getAvailableMovesWithoutCheck();
                            if(std::find(moves.begin(), moves.end(), pos) != moves.end()) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else{
            std::pair<int, int> pos;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if(board[i][j] != nullptr){
                        if(board[i][j]->getShortName() == 'k'){
                            pos = {i, j};
                        }
                    }
                }
            }

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if(board[i][j] != nullptr){
                        if(board[i][j]->get_color() == white){
                            std::vector<std::pair<int, int>> moves = board[i][j]->getAvailableMovesWithoutCheck();
                            if(std::find(moves.begin(), moves.end(), pos) != moves.end()) {
                                return true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
    bool Game_Descriptor::CheckCheckmate(COLOR color){
        if(this->CheckCheck(color)){
            Game_Descriptor test(*this);
            if(color == white){
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if(test.board[i][j] != nullptr){
                            if(test.board[i][j]->get_color() == white){
                                std::vector<std::pair<int, int>> moves = test.board[i][j]->getAvailableMoves();
                                for(std::pair<int, int>& move: moves){
                                    test.board[move.first][move.second] = std::move(test.board[i][j]);
                                    if(!test.CheckCheck(color))
                                        return false;
                                    else
                                        test.board[i][j] = std::move(test.board[move.first][move.second]);
                                }
                            }
                        }
                    }
                }
            }
            else{
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if(test.board[i][j] != nullptr){
                            if(test.board[i][j]->get_color() == black){
                                std::vector<std::pair<int, int>> moves = test.board[i][j]->getAvailableMoves();
                                for(std::pair<int, int>& move: moves){
                                    test.board[move.first][move.second] = std::move(test.board[i][j]);
                                    if(!test.CheckCheck(color))
                                        return false;
                                    else
                                        test.board[i][j] = std::move(test.board[move.first][move.second]);
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }

    bool Game_Descriptor::CheckStalemate(COLOR color){
        if(color == white){
            std::pair<int, int> pos;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if(board[i][j] != nullptr){
                        if(board[i][j]->get_color() == white){
                            std::vector<std::pair<int, int>> moves = board[i][j]->getAvailableMovesWithoutCheck();
                            if(!moves.empty())
                                return false;
                        }
                    }
                }
            }
        }
        else{
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if(board[i][j] != nullptr){
                        if(board[i][j]->get_color() == black){
                            std::vector<std::pair<int, int>> moves = board[i][j]->getAvailableMovesWithoutCheck();
                            if(!moves.empty())
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    std::string to_string(STATUS status){
        if(status == GameIsOn)
            return "Game Is On";
        else if(status == NoGame)
            return "No Game";
        else if(status == WhiteWin)
            return "White Win";
        else if(status == BlackWin)
            return "Black Win";
        else if(status == Draw)
            return "Draw";
        else
            return "None";
    }

    std::string to_string(VERDICT verdict){
        if(verdict == Checkmate)
            return "Checkmate";
        else if(verdict == Check)
            return "Check";
        else if(verdict == Stalemate)
            return "Stalemate";
        else
            return "Nothing";
    }

    COLOR& inverse(COLOR& color){
        if(color == white)
            color = black;
        else
            color = white;
        return color;
    }
}
