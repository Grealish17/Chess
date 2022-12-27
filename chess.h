//#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>

namespace CHESS{

    /**
     * @brief Цвет (белый или чёрный)
     */
    enum COLOR{
        black,
        white
    };

    /**
     * @brief Смена цвета
     * @param color Старый цвет
     * @return Новый цвет
     */
    COLOR& inverse(COLOR& color);

    /**
     * @brief Статус игры  (игра идёт, игры нет,  победа белых, победа чёрных, ничья)
     */
    enum STATUS{
        GameIsOn,
        NoGame,
        WhiteWin,
        BlackWin,
        Draw
    };

    /**
     * @brief Преобразование статуса игры в строковый тип
     * @param status Статус
     * @return Строка со значаением статуса
     */
    std::string to_string(STATUS status);

    /**
     * @brief Вердикт  (шах, мат, пат, ничего)
     */
    enum VERDICT{
        Checkmate,
        Check,
        Stalemate,
        Nothing
    };

    /**
     * @brief Преобразование вердикта игры в строковый тип
     * @param verdict Вердикт
     * @return Строка со значаением вердикта
     */
    std::string to_string(VERDICT verdict);


    /**
     * @brief Перевод из целочисленного номера поля в стандартное название
     * @param square Позиция фигуры
     * @return Стандартное название поля
     */
    std::string to_string(std::pair<int, int> square);

    class Game_Descriptor;
    /**
     * @brief Абстрактная фигура
     */
    class Piece{
    protected:
        //! Позиция фигуры
        std::pair<int, int> position;
        //! Ссылка на описатель партии
        Game_Descriptor& game;
    private:
        //! Цвет фигуры
        COLOR color;
    public:
        /**
         * @brief Конструктор класса
         * @param color Цвет фигуры
         * @param game Описатель партии
         * @param square0 Позиция фигуры
         */
        explicit Piece(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        /**
         * @brief Проверка возможности хода на данную клетку
         * @param square Позиция фигуры
         * @return Можно ли сходить на данную клетку
         */
        bool checkMove(std::pair<int, int> square);
        /**
         * @brief Функция установки позиции фигуры
         * @param square Новая озиция
         */
        void setPosition(std::pair<int, int> square);
        /**
         * @brief Возвращает короткое имя фигуры
         * @return Короткое имя фигуры
         */
        virtual char getShortName() = 0;
        /**
         * @brief Получение всех возможных полей для хода фигуры
         * @return Вектор клеток
         */
        virtual std::vector<std::pair<int, int>> getAvailableMoves() = 0;
        /**
         * @brief Получение всех возможных полей для хода фигуры без учёта шаха
         * @return Вектор клеток
         */
        virtual std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() = 0;
        /**
         * @brief Возвращает имя фигуры
         * @return Полное имя фигуры
         */
        virtual std::string getName() = 0;
        /**
         * @brief Возвращает запись хода в соответствии с общепринятой нотацией
         * @return Запись хода
         */
        virtual std::string toNotation(std::pair<int, int> square);
        /**
         * @brief Возвращает цвет фигуры
         * @return Цвет фигуры
         */
        COLOR get_color();
    };
    /**
     * @brief История шахматной партии
     */
    class Game_History{
    public:
        //! Список ходов партии
        std::list<std::string> moves;
    public:
        /**
         * @brief Добавление записи хода
         * @param move Запись хода в соответствии с общепринятой нотацией
         */
        void addMove(const std::string& move);
        /**
         * @brief Сохранение истории партии в файл
         * @param file_name Файл, куда сохранится история партии
         * @return Сохранилась ли партия
         */
        bool saveToFile(const std::string& file_name);
    };

    /**
     * @brief Описатель шахматной партии
     */
    class Game_Descriptor{
    public:
        //! Доска
        std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board;
        //! История партии
        Game_History history;
        //! Очередь хода
        COLOR turn = white;
        //! Текущий статус игры
        STATUS status = NoGame;
        //! Текущий вердикт
        VERDICT verdict = Nothing;
        //! Возможность сделать рокировку белым
        bool castlingWhiteIsAvailable = true;
        //! Возможность сделать рокировку чёрным
        bool castlingBlackIsAvailable = true;
        /**
         * @brief Добавление фигуры
         * @param square Поле новой фигуры
         * @param shortname Короткое имя фигуры
         */
        void addPiece(std::pair<int, int> square, char shortname);
        /**
         * @brief Удаление фигуры
         * @param square Поле новой фигуры
         */
        void deletePiece(std::pair<int, int> square);
    public:
        /**
         * @brief Конструктор класса
         */
        explicit Game_Descriptor();
        /**
         * @brief Копирующий конструктор класса
         * @param game Игра, с которой берём копию
         */
        Game_Descriptor(Game_Descriptor& game);
        /**
         * @brief Выполнение хода
         * @param square0 Старое поле фигуры
         * @param square Новое поле фигуры
         */
        void makeMove(std::pair<int, int> square0, std::pair<int, int> square);
        /**
         * @brief Замена фигуры
         * @param square Поле новой фигуры
         * @param shortname Короткое имя новой фигуры
         */
        void changePiece(std::pair<int, int> square, char shortname);
        /**
         * @brief Проверка на мат
         * @param color Цвет короля, проверяемого на мат
         * @return Есть ли мат
         */
        bool CheckCheckmate(COLOR color);
        /**
         * @brief Проверка на шах
         * @param color Цвет короля, проверяемого на шах
         * @return Есть ли шах
         */
        bool CheckCheck(COLOR color);
        /**
         * @brief Проверка на пат
         * @param color Цвет короля, проверяемого на пат
         * @return Есть ли пат
         */
        bool CheckStalemate(COLOR color);
    };

    /**
     * @brief Король
     */
    class King: public Piece{
    public:
        /**
         * @brief Конструктор класса
         * @param color Цвет фигуры
         * @param game Описатель партии
         * @param square0 Позиция фигуры
         */
        explicit King(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        /**
         * @brief Возвращает короткое имя фигуры
         * @return Короткое имя фигуры
         */
        char getShortName() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры без учёта шаха
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        /**
         * @brief Возвращает имя фигуры
         * @return Полное имя фигуры
         */
        std::string getName() override;
    };
    /**
     * @brief Ферзь(Королева)
     */
    class Queen: public Piece{
    public:
        /**
         * @brief Конструктор класса
         * @param color Цвет фигуры
         * @param game Описатель партии
         * @param square0 Позиция фигуры
         */
        explicit Queen(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        /**
         * @brief Возвращает короткое имя фигуры
         * @return Короткое имя фигуры
         */
        char getShortName() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры без учёта шаха
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        /**
         * @brief Возвращает имя фигуры
         * @return Полное имя фигуры
         */
        std::string getName() override;
    };

    /**
     * @brief Ладья
     */
    class Rook: public Piece{
    public:
        /**
         * @brief Конструктор класса
         * @param color Цвет фигуры
         * @param game Описатель партии
         * @param square0 Позиция фигуры
         */
        explicit Rook(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        /**
         * @brief Возвращает короткое имя фигуры
         * @return Короткое имя фигуры
         */
        char getShortName() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры без учёта шаха
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        /**
         * @brief Возвращает имя фигуры
         * @return Полное имя фигуры
         */
        std::string getName() override;
    };

    /**
     * @brief Слон
     */
    class Bishop: public Piece{
    public:
        /**
         * @brief Конструктор класса
         * @param color Цвет фигуры
         * @param game Описатель партии
         * @param square0 Позиция фигуры
         */
        explicit Bishop(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        /**
         * @brief Возвращает короткое имя фигуры
         * @return Короткое имя фигуры
         */
        char getShortName() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры без учёта шаха
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        /**
         * @brief Возвращает имя фигуры
         * @return Полное имя фигуры
         */
        std::string getName() override;
    };

    /**
     * @brief Конь
     */
    class Knight: public Piece{
    public:
        /**
         * @brief Конструктор класса
         * @param color Цвет фигуры
         * @param game Описатель партии
         * @param square0 Позиция фигуры
         */
        explicit Knight(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        /**
         * @brief Возвращает короткое имя фигуры
         * @return Короткое имя фигуры
         */
        char getShortName() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры без учёта шаха
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        /**
         * @brief Возвращает имя фигуры
         * @return Полное имя фигуры
         */
        std::string getName() override;
    };

    /**
     * @brief Пешка
     */
    class Pawn: public Piece{
    public:
        /**
         * @brief Конструктор класса
         * @param color Цвет фигуры
         * @param game Описатель партии
         * @param square0 Позиция фигуры
         */
        explicit Pawn(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        /**
         * @brief Возвращает короткое имя фигуры
         * @return Короткое имя фигуры
         */
        char getShortName() override;
        /**
         * @brief Возвращает запись хода в соответствии с общепринятой нотацией
         * @return Запись хода
         */
        std::string toNotation(std::pair<int, int> square) override;
        /**
         * @brief Получение всех возможных полей для хода фигуры
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        /**
         * @brief Получение всех возможных полей для хода фигуры без учёта шаха
         * @return Вектор клеток
         */
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        /**
         * @brief Возвращает имя фигуры
         * @return Полное имя фигуры
         */
        std::string getName() override;
    };

}