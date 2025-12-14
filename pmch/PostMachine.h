/**
* @file PostMachine.h
 * @brief Заголовочный файл для реализации машины Поста
 *
 * Содержит объявление классов для реализации машины Поста -
 * абстрактной вычислительной машины, предложенной Эмилем Постом.
 */

#ifndef POSTMACHINE_H
#define POSTMACHINE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

/**
 * @enum CommandType
 * @brief Типы команд машины Поста
 *
 * Определяет все возможные типы команд, которые может выполнять машина Поста.
 */
enum class CommandType {
    SET_MARK,     ///< Поставить метку в текущей ячейке
    ERASE_MARK,   ///< Стереть метку из текущей ячейки
    MOVE_LEFT,    ///< Сдвинуть головку влево на одну ячейку
    MOVE_RIGHT,   ///< Сдвинуть головку вправо на одну ячейку
    CONDITIONAL,  ///< Условный переход в зависимости от наличия метки
    STOP          ///< Остановка выполнения программы
};

/**
 * @struct Command
 * @brief Структура, представляющая команду машины Поста
 *
 * Каждая команда содержит тип команды, параметры перехода и необязательную метку.
 * Для условных команд используется два параметра перехода.
 */
struct Command {
    CommandType type; ///< Тип команды
    int jump1;     ///< Первый параметр перехода (для всех команд кроме STOP)
    int jump2;     ///< Второй параметр перехода (только для CONDITIONAL)
    std::string label; ///< Метка команды для отладки (необязательно)

    /**
     * @brief Конструктор команды
     * @param t Тип команды
     * @param j1 Первый параметр перехода (по умолчанию 0)
     * @param j2 Второй параметр перехода (по умолчанию 0, используется только для CONDITIONAL)
     * @param lbl Метка команды (по умолчанию пустая строка)
     */

    Command(CommandType t = CommandType::STOP, int j1 = 0, int j2 = 0,
            const std::string& lbl = "");

    /**
    * @brief Оператор сравнения равенства
    * @param other Другая команда для сравнения
    * @return true если команды идентичны
    */
    bool operator==(const Command& other) const;
    /**
     * @brief Оператор сравнения неравенства
     * @param other Другая команда для сравнения
     * @return true если команды различаются
     */
    bool operator!=(const Command& other) const;
};

/**
 * @class Tape
 * @brief Класс, представляющий ленту машины Поста
 *
 * Лента бесконечна в обе стороны. Каждая ячейка может содержать метку (true) или быть пустой (false).
 */
class Tape {
private:
    std::map<int, bool> cells;  ///< Хранилище ячеек ленты (позиция → наличие метки)
    int headPosition;           ///< Текущая позиция головки на ленте

public:
    /**
     * @brief Конструктор по умолчанию
     *
     * Создает пустую ленту с головкой в позиции 0.
     */
    Tape();
    /**
     * @brief Конструктор копирования
     * @param other Лента для копирования
     */
    Tape(const Tape& other);

    /**
     * @brief Оператор присваивания
     * @param other Лента для копирования
     * @return Ссылка на текущий объект
     */
    Tape& operator=(const Tape& other);

    /**
     * @brief Оператор сравнения равенства
     * @param other Другая лента для сравнения
     * @return true если ленты идентичны
     */
    bool operator==(const Tape& other) const;
    /**
     * @brief Оператор сравнения неравенства
     * @param other Другая лента для сравнения
     * @return true если ленты различаются
     */
    bool operator!=(const Tape& other) const;

    /**
     * @brief Установить метку в указанной ячейке
     * @param position Позиция ячейки
     */
    void setMark(int position);

    /**
     * @brief Стереть метку из указанной ячейки
     * @param position Позиция ячейки
     */
    void eraseMark(int position);
    /**
    * @brief Проверить наличие метки в ячейке
    * @param position Позиция ячейки
    * @return true если в ячейке есть метка
    */
    bool hasMark(int position) const;
    /**
     * @brief Сдвинуть головку влево на одну ячейку
     */

    void moveLeft();
    /**
     * @brief Сдвинуть головку вправо на одну ячейку
     */
    void moveRight();
    /**
    * @brief Получить текущую позицию головки
    * @return Позиция головки
    */


    int getHeadPosition() const;
    /**
     * @brief Получить копию всех ячеек ленты
     * @return Карта позиция → наличие метки
     */
    std::map<int, bool> getCells() const;
    /**
    * @brief Оператор вывода ленты
    * @param os Выходной поток
    * @param tape Лента для вывода
    * @return Ссылка на выходной поток
    */


    friend std::ostream& operator<<(std::ostream& os, const Tape& tape);
    /**
     * @brief Оператор ввода ленты
     * @param is Входной поток
     * @param tape Лента для ввода
     * @return Ссылка на входной поток
     */
    friend std::istream& operator>>(std::istream& is, Tape& tape);
};

/**
 * @class PostMachine
 * @brief Основной класс, реализующий машину Поста
 *
 * Содержит программу, ленту и управляет выполнением команд.
 * Поддерживает все шесть типов команд машины Поста.
 */
class PostMachine {
private:
    std::vector<Command> program; ///< Программа для выполнения
    Tape tape;///< Лента машины
    int programCounter; ///< Счетчик команд (указывает на следующую команду)
    bool isRunning; ///< Флаг выполнения программы
    std::string lastError; ///< Последнее сообщение об ошибке

public:
    /**
     * @brief Конструктор по умолчанию
     *
     * Создает машину с пустой программой и лентой.
     */
    PostMachine();
    /**
     * @brief Конструктор с программой
     * @param prog Начальная программа
     */
    PostMachine(const std::vector<Command>& prog);
    /**
    * @brief Конструктор копирования
    * @param other Машина для копирования
    */
    PostMachine(const PostMachine& other);
    /**
     * @brief Оператор присваивания
     * @param other Машина для копирования
     * @return Ссылка на текущий объект
     */


    PostMachine& operator=(const PostMachine& other);
    /**
         * @brief Оператор сравнения равенства
         * @param other Другая машина для сравнения
         * @return true если машины идентичны
         */

    bool operator==(const PostMachine& other) const;
    /**
     * @brief Оператор сравнения неравенства
     * @param other Другая машина для сравнения
     * @return true если машины различаются
     */
    bool operator!=(const PostMachine& other) const;
    /**
     * @brief Загрузить программу
     * @param prog Программа для загрузки
     *
     * Сбрасывает состояние машины и загружает новую программу.
     */


    void loadProgram(const std::vector<Command>& prog);
    /**
     * @brief Сбросить состояние машины
     *
     * Сбрасывает счетчик команд, очищает ленту и сообщения об ошибках.
     */
    void reset();
    /**
    * @brief Выполнить один шаг программы
    * @return true если выполнение продолжается, false если программа завершена или произошла ошибка
    */
    bool executeStep();
    /**
     * @brief Выполнить всю программу до завершения
     *
     * Выполняет программу пока executeStep() возвращает true.
     */
    void executeAll();
    /**
    * @brief Получить текущее состояние ленты
    * @return Копия ленты
    */


    Tape getTape() const;
    /**
     * @brief Получить значение счетчика команд
     * @return Текущий счетчик команд
     */
    int getProgramCounter() const;
    /**
    * @brief Получить состояние выполнения
    * @return true если машина работает
    */
    bool getIsRunning() const;
    /**
     * @brief Получить последнее сообщение об ошибке
     * @return Сообщение об ошибке
     */
    std::string getLastError() const;

    /**
     * @brief Оператор вывода состояния машины
     * @param os Выходной поток
     * @param machine Машина для вывода
     * @return Ссылка на выходной поток
     */
    friend std::ostream& operator<<(std::ostream& os, const PostMachine& machine);

    /**
     * @brief Оператор ввода состояния машины
     * @param is Входной поток
     * @param machine Машина для ввода
     * @return Ссылка на входной поток
     */
    friend std::istream& operator>>(std::istream& is, PostMachine& machine);

    /**
     * @brief Создать команду "Поставить метку"
     * @param jumpTo Номер команды для перехода
     * @return Команда SET_MARK
     */
    static Command createSetMark(int jumpTo);
    /**
     * @brief Создать команду "Стереть метку"
     * @param jumpTo Номер команды для перехода
     * @return Команда ERASE_MARK
     */
    static Command createEraseMark(int jumpTo);
    /**
     * @brief Создать команду "Сдвинуться влево"
     * @param jumpTo Номер команды для перехода
     * @return Команда MOVE_LEFT
     */
    static Command createMoveLeft(int jumpTo);
    /**
     * @brief Создать команду "Сдвинуться вправо"
     * @param jumpTo Номер команды для перехода
     * @return Команда MOVE_RIGHT
     */
    static Command createMoveRight(int jumpTo);
    /**
     * @brief Создать команду "Условный переход"
     * @param jumpIfNoMark Номер команды для перехода если нет метки
     * @param jumpIfMark Номер команды для перехода если есть метка
     * @return Команда CONDITIONAL
     */
    static Command createConditional(int jumpIfNoMark, int jumpIfMark);
    /**
     * @brief Создать команду "Стоп"
     * @return Команда STOP
     */
    static Command createStop();
};

#endif // POSTMACHINE_H