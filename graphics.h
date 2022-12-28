//#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>
#include <SFML/Graphics.hpp>

const int FIELD_SIZE = 800;
const int SQUARE_SIZE = 100;

/**
 * @brief Шахматная доска
 */
class Game_Board : public sf::Drawable, public sf::Transformable{
private:
    //! Ссылка на описатель партии
    CHESS::Game_Descriptor& game;
    //! Шрифт
    sf::Font font;
    //! Выбрана ли сейчас какая-то фигура
    bool selected = false;

public:
    //! @brief Координаты выбранной фигуры
    std::pair<int, int> selectedPiece = {-1, -1};
    //! @brief Наведён ли курсор на кнопку "сохранить партию"
    bool saveButton = false;
    /**
     * @brief Конструктор класса
     * @param game Описатель партии, на основе которого содаётся доска
     */
    explicit Game_Board(CHESS::Game_Descriptor& game);
    /**
     * @brief Выбрана ли сейчас какая-то фигура
     * @return Значение поля selected
     */
    bool getSelected() const;
    /**
     * @brief Рисование доски
     * @param target Базовый класс для всех целей рендеринга
     * @param states Специальный экземпляр, содержащий состояния рендеринга по умолчанию
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    /**
     * @brief Выбирает фигуру по координатам поля
     * @param pos_x Координата по X
     * @param pos_y Координата по Y
     * @return Удалось ли выбрать фигуру
     */
    bool selectPiece(int pos_x, int pos_y);
    /**
     * @brief Сброс выбранной фигуры
     */
    void resetSelect();
    /**
    * @brief Выбирает новое поле для выбранной фигуру
    * @param pos_x Координата по X
    * @param pos_y Координата по Y
    * @return Удалось ли выбрать клетку
    */
    bool moveSelected(int pos_x, int pos_y);
};

/**
 * @brief Картинки фигур
 */
class PieceTextures{
public:
    //! Картинка чёрного короля
    static sf::Texture blackKing;
    //! Картинка чёрного ферзя
    static sf::Texture blackQueen;
    //! Картинка чёрной ладьи
    static sf::Texture blackRook;
    //! Картинка чёрного коня
    static sf::Texture blackKnight;
    //! Картинка чёрного слона
    static sf::Texture blackBishop;
    //! Картинка чёрной пешки
    static sf::Texture blackPawn;

    //! Картинка белого короля
    static sf::Texture whiteKing;
    //! Картинка белого ферзя
    static sf::Texture whiteQueen;
    //! Картинка белой ладьи
    static sf::Texture whiteRook;
    //! Картинка белого коня
    static sf::Texture whiteKnight;
    //! Картинка белого слона
    static sf::Texture whiteBishop;
    //! Картинка белой пешки
    static sf::Texture whitePawn;

    /**
     * @brief Функция загрузки картинки
     * @param str Путь до файла с картинкой
     * @return Картинка фигуры
     */
    static sf::Texture loadTexture(const std::string& str);
};