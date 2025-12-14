
#include "PostMachine.h"
#include <sstream>
#include <stdexcept>


Command::Command(CommandType t, int j1, int j2, const std::string& lbl)
    : type(t), jump1(j1), jump2(j2), label(lbl) {}

// Операторы сравнения для Command
bool Command::operator==(const Command& other) const {
    return type == other.type &&
           jump1 == other.jump1 &&
           jump2 == other.jump2 &&
           label == other.label;
}

bool Command::operator!=(const Command& other) const {
    return !(*this == other);
}


Tape::Tape() : headPosition(0) {
    cells[0] = false;  // Начальная ячейка
}

Tape::Tape(const Tape& other)
    : cells(other.cells), headPosition(other.headPosition) {}

Tape& Tape::operator=(const Tape& other) {
    if (this != &other) {
        cells = other.cells;
        headPosition = other.headPosition;
    }
    return *this;
}

bool Tape::operator==(const Tape& other) const {
    return cells == other.cells && headPosition == other.headPosition;
}

bool Tape::operator!=(const Tape& other) const {
    return !(*this == other);
}

void Tape::setMark(int position) {
    cells[position] = true;
}

void Tape::eraseMark(int position) {
    cells[position] = false;
}

bool Tape::hasMark(int position) const {
    auto it = cells.find(position);
    if (it != cells.end()) {
        return it->second;
    }
    return false;
}

void Tape::moveLeft() {
    headPosition--;
    // Создаем новую ячейку если нужно
    if (cells.find(headPosition) == cells.end()) {
        cells[headPosition] = false;
    }
}

void Tape::moveRight() {
    headPosition++;
    if (cells.find(headPosition) == cells.end()) {
        cells[headPosition] = false;
    }
}

int Tape::getHeadPosition() const {
    return headPosition;
}

std::map<int, bool> Tape::getCells() const {
    return cells;
}

std::ostream& operator<<(std::ostream& os, const Tape& tape) {
    os << "Head at position: " << tape.headPosition << "\n";
    os << "Cells: ";
    for (const auto& cell : tape.cells) {
        os << "[" << cell.first << ": " << (cell.second ? "X" : " ") << "] ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Tape& tape) {
    tape.cells.clear();
    int position;
    bool hasMark;

    std::string line;
    while (std::getline(is, line)) {
        if (line.empty()) break;
        std::istringstream iss(line);
        if (iss >> position >> hasMark) {
            tape.cells[position] = hasMark;
        }
    }

    if (!tape.cells.empty()) {
        tape.headPosition = tape.cells.begin()->first;
    }

    return is;
}

// Реализация класса PostMachine
PostMachine::PostMachine()
    : programCounter(0), isRunning(false), lastError("") {}

PostMachine::PostMachine(const std::vector<Command>& prog)
    : program(prog), programCounter(0), isRunning(!prog.empty()), lastError("") {}

PostMachine::PostMachine(const PostMachine& other)
    : program(other.program), tape(other.tape),
      programCounter(other.programCounter),
      isRunning(other.isRunning), lastError(other.lastError) {}

PostMachine& PostMachine::operator=(const PostMachine& other) {
    if (this != &other) {
        program = other.program;
        tape = other.tape;
        programCounter = other.programCounter;
        isRunning = other.isRunning;
        lastError = other.lastError;
    }
    return *this;
}

bool PostMachine::operator==(const PostMachine& other) const {
    return program == other.program &&
           tape == other.tape &&
           programCounter == other.programCounter &&
           isRunning == other.isRunning;
}

bool PostMachine::operator!=(const PostMachine& other) const {
    return !(*this == other);
}

void PostMachine::loadProgram(const std::vector<Command>& prog) {
    program = prog;
    reset();
}

void PostMachine::reset() {
    programCounter = 0;
    isRunning = !program.empty();
    lastError = "";
    tape = Tape();  // Сбрасываем ленту
}

bool PostMachine::executeStep() {
    if (!isRunning || programCounter < 0 || programCounter >= static_cast<int>(program.size())) {
        lastError = "Program not running or invalid program counter";
        isRunning = false;
        return false;
    }

    const Command& cmd = program[programCounter];

    switch (cmd.type) {
        case CommandType::SET_MARK:
            tape.setMark(tape.getHeadPosition());
            programCounter = cmd.jump1;
            break;

        case CommandType::ERASE_MARK:
            tape.eraseMark(tape.getHeadPosition());
            programCounter = cmd.jump1;
            break;

        case CommandType::MOVE_LEFT:
            tape.moveLeft();
            programCounter = cmd.jump1;
            break;

        case CommandType::MOVE_RIGHT:
            tape.moveRight();
            programCounter = cmd.jump1;
            break;

        case CommandType::CONDITIONAL:
            if (tape.hasMark(tape.getHeadPosition())) {
                programCounter = cmd.jump2;
            } else {
                programCounter = cmd.jump1;
            }
            break;

        case CommandType::STOP:
            isRunning = false;
            return true;

        default:
            lastError = "Unknown command type";
            isRunning = false;
            return false;
    }

    // Проверка выхода за пределы программы
    if (programCounter < 0 || programCounter >= static_cast<int>(program.size())) {
        lastError = "Jump to invalid program line";
        isRunning = false;
        return false;
    }

    return true;
}

void PostMachine::executeAll() {
    while (isRunning) {
        if (!executeStep()) {
            break;
        }
    }
}

Tape PostMachine::getTape() const {
    return tape;
}

int PostMachine::getProgramCounter() const {
    return programCounter;
}

bool PostMachine::getIsRunning() const {
    return isRunning;
}

std::string PostMachine::getLastError() const {
    return lastError;
}

std::ostream& operator<<(std::ostream& os, const PostMachine& machine) {
    os << "Post Machine State:\n";
    os << "Program counter: " << machine.programCounter << "\n";
    os << "Is running: " << (machine.isRunning ? "true" : "false") << "\n";
    os << "Last error: " << (machine.lastError.empty() ? "none" : machine.lastError) << "\n";
    os << "Program (" << machine.program.size() << " commands):\n";

    for (size_t i = 0; i < machine.program.size(); ++i) {
        os << i << ": ";
        const Command& cmd = machine.program[i];
        switch (cmd.type) {
            case CommandType::SET_MARK:
                os << "SET_MARK -> " << cmd.jump1;
                break;
            case CommandType::ERASE_MARK:
                os << "ERASE_MARK -> " << cmd.jump1;
                break;
            case CommandType::MOVE_LEFT:
                os << "MOVE_LEFT -> " << cmd.jump1;
                break;
            case CommandType::MOVE_RIGHT:
                os << "MOVE_RIGHT -> " << cmd.jump1;
                break;
            case CommandType::CONDITIONAL:
                os << "CONDITIONAL -> " << cmd.jump1 << " (no mark) or " << cmd.jump2 << " (mark)";
                break;
            case CommandType::STOP:
                os << "STOP";
                break;
        }
        if (!cmd.label.empty()) {
            os << " [" << cmd.label << "]";
        }
        os << "\n";
    }

    os << "Tape state:\n" << machine.tape;
    return os;
}

std::istream& operator>>(std::istream& is, PostMachine& machine) {
    machine.program.clear();

    int cmdType;
    int jump1, jump2;
    std::string label;

    while (is >> cmdType) {
        Command cmd;
        cmd.type = static_cast<CommandType>(cmdType);

        switch (cmd.type) {
            case CommandType::SET_MARK:
            case CommandType::ERASE_MARK:
            case CommandType::MOVE_LEFT:
            case CommandType::MOVE_RIGHT:
                is >> jump1;
                cmd.jump1 = jump1;
                break;
            case CommandType::CONDITIONAL:
                is >> jump1 >> jump2;
                cmd.jump1 = jump1;
                cmd.jump2 = jump2;
                break;
            case CommandType::STOP:
                break;
        }

        std::getline(is >> std::ws, label);
        cmd.label = label;

        machine.program.push_back(cmd);

        if (cmd.type == CommandType::STOP) {
            break;
        }
    }

    machine.reset();
    return is;
}

// Статические методы создания команд
Command PostMachine::createSetMark(int jumpTo) {
    return Command(CommandType::SET_MARK, jumpTo, 0, "Set mark");
}

Command PostMachine::createEraseMark(int jumpTo) {
    return Command(CommandType::ERASE_MARK, jumpTo, 0, "Erase mark");
}

Command PostMachine::createMoveLeft(int jumpTo) {
    return Command(CommandType::MOVE_LEFT, jumpTo, 0, "Move left");
}

Command PostMachine::createMoveRight(int jumpTo) {
    return Command(CommandType::MOVE_RIGHT, jumpTo, 0, "Move right");
}

Command PostMachine::createConditional(int jumpIfNoMark, int jumpIfMark) {
    return Command(CommandType::CONDITIONAL, jumpIfNoMark, jumpIfMark, "Conditional");
}

Command PostMachine::createStop() {
    return Command(CommandType::STOP, 0, 0, "Stop");
}