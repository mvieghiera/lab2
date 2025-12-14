#include "fifteen_puzzle.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>

FifteenPuzzle::FifteenPuzzle() {
    initializeBoard();
    shuffleBoard();
}

FifteenPuzzle::FifteenPuzzle(const FifteenPuzzle& other) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = other.board[i][j];
        }
    }
    emptyRow = other.emptyRow;
    emptyCol = other.emptyCol;
}

void FifteenPuzzle::initializeBoard() {
    int value = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = value++;
        }
    }
    board[SIZE-1][SIZE-1] = 0;
    emptyRow = SIZE-1;
    emptyCol = SIZE-1;
}

void FifteenPuzzle::shuffleBoard() {
    std::vector<int> numbers;
    for (int i = 0; i < SIZE*SIZE; i++) {
        numbers.push_back(i);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[index++];
            if (board[i][j] == 0) {
                emptyRow = i;
                emptyCol = j;
            }
        }
    }
}

bool FifteenPuzzle::isValidMove(int row, int col) const {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }

    return (abs(row - emptyRow) == 1 && col == emptyCol) ||
           (abs(col - emptyCol) == 1 && row == emptyRow);
}

bool FifteenPuzzle::move(int row, int col) {
    if (!isValidMove(row, col)) {
        return false;
    }

    std::swap(board[row][col], board[emptyRow][emptyCol]);
    emptyRow = row;
    emptyCol = col;
    return true;
}

bool FifteenPuzzle::isSolved() const {
    int expected = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == SIZE-1 && j == SIZE-1) {
                if (board[i][j] != 0) return false;
            } else {
                if (board[i][j] != expected++) return false;
            }
        }
    }
    return true;
}

void FifteenPuzzle::reset() {
    initializeBoard();
}

void FifteenPuzzle::printBoard() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                std::cout << "   ";
            } else {
                std::printf("%2d ", board[i][j]);
            }
        }
        std::cout << std::endl;
    }
}

FifteenPuzzle& FifteenPuzzle::operator=(const FifteenPuzzle& other) {
    if (this != &other) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = other.board[i][j];
            }
        }
        emptyRow = other.emptyRow;
        emptyCol = other.emptyCol;
    }
    return *this;
}

bool FifteenPuzzle::operator==(const FifteenPuzzle& other) const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != other.board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool FifteenPuzzle::operator!=(const FifteenPuzzle& other) const {
    return !(*this == other);
}

int& FifteenPuzzle::operator[](std::pair<int, int> position) {
    if (position.first < 0 || position.first >= SIZE ||
        position.second < 0 || position.second >= SIZE) {
        throw std::out_of_range("Index out of bounds");
    }
    return board[position.first][position.second];
}

const int& FifteenPuzzle::operator[](std::pair<int, int> position) const {
    if (position.first < 0 || position.first >= SIZE ||
        position.second < 0 || position.second >= SIZE) {
        throw std::out_of_range("Index out of bounds");
    }
    return board[position.first][position.second];
}

std::ostream& operator<<(std::ostream& os, const FifteenPuzzle& puzzle) {
    for (int i = 0; i < FifteenPuzzle::SIZE; i++) {
        for (int j = 0; j < FifteenPuzzle::SIZE; j++) {
            os << puzzle.board[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, FifteenPuzzle& puzzle) {
    for (int i = 0; i < FifteenPuzzle::SIZE; i++) {
        for (int j = 0; j < FifteenPuzzle::SIZE; j++) {
            is >> puzzle.board[i][j];
            if (puzzle.board[i][j] == 0) {
                puzzle.emptyRow = i;
                puzzle.emptyCol = j;
            }
        }
    }
    return is;
}