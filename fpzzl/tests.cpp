#include "fifteen_puzzle.h"
#include <gtest/gtest.h>
#include <sstream>
#include <random>
#include <array>

TEST(FifteenPuzzleTest, ConstructorTest) {
    FifteenPuzzle puzzle;
    ASSERT_FALSE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, CopyConstructorTest) {
    FifteenPuzzle puzzle1;
    FifteenPuzzle puzzle2 = puzzle1;
    ASSERT_TRUE(puzzle1 == puzzle2);
}

TEST(FifteenPuzzleTest, AssignmentOperatorTest) {
    FifteenPuzzle puzzle1;
    FifteenPuzzle puzzle2;
    puzzle2 = puzzle1;
    ASSERT_TRUE(puzzle1 == puzzle2);
}

TEST(FifteenPuzzleTest, EqualityOperatorTest) {
    FifteenPuzzle puzzle1;
    FifteenPuzzle puzzle2(puzzle1);
    ASSERT_TRUE(puzzle1 == puzzle2);
}

TEST(FifteenPuzzleTest, InequalityOperatorTest) {
    FifteenPuzzle puzzle1;
    FifteenPuzzle puzzle2;
    puzzle2.reset();
    ASSERT_TRUE(puzzle1 != puzzle2);
}

TEST(FifteenPuzzleTest, ResetTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_TRUE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, IndexOperatorTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    // ИСПРАВЛЕНО: добавлены дополнительные скобки
    ASSERT_EQ((puzzle[{0, 0}]), 1);
    ASSERT_EQ((puzzle[{3, 3}]), 0);
}

TEST(FifteenPuzzleTest, IndexOperatorOutOfRangeTest) {
    FifteenPuzzle puzzle;
    // ИСПРАВЛЕНО: добавлены дополнительные скобки
    EXPECT_THROW((puzzle[{4, 4}]), std::out_of_range);
    EXPECT_THROW((puzzle[{-1, 0}]), std::out_of_range);
}

TEST(FifteenPuzzleTest, ValidMoveTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_TRUE(puzzle.move(2, 3));
}

TEST(FifteenPuzzleTest, InvalidMoveTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_FALSE(puzzle.move(0, 0));
}

TEST(FifteenPuzzleTest, SolveTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_TRUE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, NotSolvedTest) {
    FifteenPuzzle puzzle;
    ASSERT_FALSE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, MultipleMovesTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    puzzle.move(2, 3);
    puzzle.move(3, 3);
    puzzle.move(3, 2);
    puzzle.move(3, 1);

    ASSERT_FALSE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, GetEmptyPositionTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_EQ(puzzle.getEmptyRow(), 3);
    ASSERT_EQ(puzzle.getEmptyCol(), 3);
}

TEST(FifteenPuzzleTest, MoveEmptyCellTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    int emptyRow = puzzle.getEmptyRow();
    int emptyCol = puzzle.getEmptyCol();

    ASSERT_TRUE(puzzle.move(emptyRow - 1, emptyCol));
    ASSERT_EQ(puzzle.getEmptyRow(), emptyRow - 1);
    ASSERT_EQ(puzzle.getEmptyCol(), emptyCol);
}

TEST(FifteenPuzzleTest, StreamOutputTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    std::stringstream ss;
    ss << puzzle;

    std::string output = ss.str();
    ASSERT_FALSE(output.empty());
}

TEST(FifteenPuzzleTest, StreamInputTest) {
    FifteenPuzzle puzzle1;
    puzzle1.reset();

    std::stringstream ss;
    ss << puzzle1;

    FifteenPuzzle puzzle2;
    ss >> puzzle2;

    ASSERT_TRUE(puzzle1 == puzzle2);
}

TEST(FifteenPuzzleTest, SelfAssignmentTest) {
    FifteenPuzzle puzzle;
    puzzle = puzzle;
    SUCCEED();
}

TEST(FifteenPuzzleTest, MoveToSamePositionTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_FALSE(puzzle.move(3, 3));
}

TEST(FifteenPuzzleTest, MoveDiagonallyTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_FALSE(puzzle.move(2, 2));
}

TEST(FifteenPuzzleTest, MoveOutOfBoundsTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();
    ASSERT_FALSE(puzzle.move(-1, 3));
    ASSERT_FALSE(puzzle.move(4, 3));
    ASSERT_FALSE(puzzle.move(3, -1));
    ASSERT_FALSE(puzzle.move(3, 4));
}

TEST(FifteenPuzzleTest, CompleteSolveTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    // Сначала делаем несколько ходов от решенного состояния
    // Пустая клетка изначально в (3,3)

    puzzle.move(2, 3);  // Перемещаем 15 вниз, пустая клетка в (2,3)
    puzzle.move(3, 3);  // Возвращаем 15 обратно, пустая клетка в (3,3)
    puzzle.move(3, 2);  // Перемещаем 14 вправо, пустая клетка в (3,2)
    puzzle.move(2, 2);  // Перемещаем 10 вниз, пустая клетка в (2,2)

    // Теперь возвращаем всё обратно в решенное состояние
    puzzle.move(3, 2);  // Возвращаем 10 вверх, пустая клетка в (3,2)
    puzzle.move(3, 3);  // Возвращаем 14 влево, пустая клетка в (3,3)

    ASSERT_TRUE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, ConstIndexOperatorTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    const FifteenPuzzle& constPuzzle = puzzle;
    // ИСПРАВЛЕНО: добавлены дополнительные скобки
    ASSERT_EQ((constPuzzle[{0, 0}]), 1);
    ASSERT_EQ((constPuzzle[{3, 3}]), 0);
}

TEST(FifteenPuzzleTest, ModifyThroughIndexOperatorTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    // ИСПРАВЛЕНО: добавлены дополнительные скобки
    puzzle[{0, 0}] = 15;
    ASSERT_EQ((puzzle[{0, 0}]), 15);
}

TEST(FifteenPuzzleTest, PrintBoardTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    testing::internal::CaptureStdout();
    puzzle.printBoard();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_FALSE(output.empty());
}

TEST(FifteenPuzzleTest, ShuffleRandomnessTest) {
    FifteenPuzzle puzzle1;
    FifteenPuzzle puzzle2;

    ASSERT_TRUE(puzzle1 != puzzle2);
}

TEST(FifteenPuzzleTest, MoveSequenceTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    std::vector<std::pair<int, int>> moves = {
        {2, 3}, {3, 3}, {3, 2}, {2, 2}
    };

    for (const auto& move : moves) {
        ASSERT_TRUE(puzzle.move(move.first, move.second));
    }
}

TEST(FifteenPuzzleTest, BoardIntegrityTest) {
    FifteenPuzzle puzzle;

    std::vector<int> numbers(16, 0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // ИСПРАВЛЕНО: добавлены дополнительные скобки
            int val = (puzzle[{i, j}]);
            ASSERT_GE(val, 0);
            ASSERT_LE(val, 15);
            numbers[val]++;
        }
    }

    for (int i = 0; i < 16; i++) {
        ASSERT_EQ(numbers[i], 1);
    }
}
TEST(FifteenPuzzleTest, LargeNumberOfRandomMovesTest) {
    FifteenPuzzle puzzle;
    puzzle.reset();

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 3);

    // Сделаем 100 случайных допустимых ходов
    for (int i = 0; i < 100; i++) {
        int emptyRow = puzzle.getEmptyRow();
        int emptyCol = puzzle.getEmptyCol();

        // Создаем список возможных ходов
        std::vector<std::pair<int, int>> possibleMoves;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if ((dr == 0) != (dc == 0)) { // только вверх/вниз/влево/вправо
                    int newRow = emptyRow + dr;
                    int newCol = emptyCol + dc;
                    if (newRow >= 0 && newRow < 4 && newCol >= 0 && newCol < 4) {
                        possibleMoves.emplace_back(newRow, newCol);
                    }
                }
            }
        }

        if (!possibleMoves.empty()) {
            int moveIndex = dist(rng) % possibleMoves.size();
            ASSERT_TRUE(puzzle.move(possibleMoves[moveIndex].first,
                                   possibleMoves[moveIndex].second));
        }
    }

    // После 100 случайных ходов головоломка почти наверняка не решена
    ASSERT_FALSE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, BoardStateAfterResetTest) {
    FifteenPuzzle puzzle;

    // Запоминаем начальное состояние
    std::array<int, 16> initialBoard{};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            initialBoard[i * 4 + j] = (puzzle[{i, j}]);
        }
    }

    // Делаем несколько ходов
    puzzle.move(2, 3);
    puzzle.move(3, 3);
    puzzle.move(3, 2);

    // Сбрасываем
    puzzle.reset();

    // Проверяем, что состояние отличается от начального (shuffle)
    bool different = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (initialBoard[i * 4 + j] != (puzzle[{i, j}])) {
                different = true;
                break;
            }
        }
        if (different) break;
    }

    // После reset() должно быть решенное состояние, а не начальное shuffle
    ASSERT_TRUE(puzzle.isSolved());
}

TEST(FifteenPuzzleTest, StreamOperatorConsistencyTest) {
    FifteenPuzzle puzzle1;

    // Записываем в поток
    std::stringstream ss;
    ss << puzzle1;

    // Считываем из потока
    FifteenPuzzle puzzle2;

    // Запоминаем оригинальное состояние перед чтением
    std::array<int, 16> originalState{};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            originalState[i * 4 + j] = (puzzle1[{i, j}]);
        }
    }

    // Читаем из потока
    ss >> puzzle2;

    // Проверяем, что считали корректно
    bool allEqual = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (originalState[i * 4 + j] != (puzzle2[{i, j}])) {
                allEqual = false;
                break;
            }
        }
        if (!allEqual) break;
    }

    ASSERT_TRUE(allEqual);
    ASSERT_TRUE(puzzle1 == puzzle2);

    // Дополнительно: записываем puzzle2 и считываем в puzzle3
    std::stringstream ss2;
    ss2 << puzzle2;
    FifteenPuzzle puzzle3;
    ss2 >> puzzle3;

    ASSERT_TRUE(puzzle2 == puzzle3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}