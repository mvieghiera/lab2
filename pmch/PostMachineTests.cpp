#include <gtest/gtest.h>
#include "PostMachine.h"

// Тесты для класса Tape
TEST(TapeTest, DefaultConstructor) {
    Tape tape;
    EXPECT_EQ(tape.getHeadPosition(), 0);
    EXPECT_FALSE(tape.hasMark(0));
}

TEST(TapeTest, CopyConstructor) {
    Tape tape1;
    tape1.setMark(0);  // исправлено: убрано "position:"
    tape1.moveRight();

    Tape tape2(tape1);
    EXPECT_EQ(tape2.getHeadPosition(), 1);
    EXPECT_TRUE(tape2.hasMark(0));
    EXPECT_FALSE(tape2.hasMark(1));
}

TEST(TapeTest, AssignmentOperator) {
    Tape tape1;
    tape1.setMark(5);
    tape1.moveRight();

    Tape tape2;
    tape2 = tape1;

    EXPECT_EQ(tape2.getHeadPosition(), 1);
    EXPECT_TRUE(tape2.hasMark(5));
}

TEST(TapeTest, EqualityOperators) {
    Tape tape1;
    Tape tape2;
    EXPECT_TRUE(tape1 == tape2);
    EXPECT_FALSE(tape1 != tape2);

    tape1.setMark(0);
    EXPECT_FALSE(tape1 == tape2);
    EXPECT_TRUE(tape1 != tape2);
}

TEST(TapeTest, SetAndEraseMark) {
    Tape tape;

    tape.setMark(0);
    EXPECT_TRUE(tape.hasMark(0));

    tape.eraseMark(0);
    EXPECT_FALSE(tape.hasMark(0));
}

TEST(TapeTest, MoveOperations) {
    Tape tape;

    tape.moveRight();
    EXPECT_EQ(tape.getHeadPosition(), 1);

    tape.moveLeft();
    EXPECT_EQ(tape.getHeadPosition(), 0);

    tape.moveLeft();
    EXPECT_EQ(tape.getHeadPosition(), -1);
    EXPECT_FALSE(tape.hasMark(-1));
}

TEST(TapeTest, GetCells) {
    Tape tape;
    tape.setMark(0);
    tape.setMark(2);

    auto cells = tape.getCells();
    EXPECT_TRUE(cells[0]);
    EXPECT_TRUE(cells[2]);
}

// Тесты для класса PostMachine
TEST(PostMachineTest, DefaultConstructor) {
    PostMachine machine;
    EXPECT_FALSE(machine.getIsRunning());
    EXPECT_EQ(machine.getProgramCounter(), 0);
    EXPECT_TRUE(machine.getLastError().empty());
}

TEST(PostMachineTest, ConstructorWithProgram) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),
        PostMachine::createStop()
    };

    PostMachine machine(program);
    EXPECT_TRUE(machine.getIsRunning());
    EXPECT_EQ(machine.getProgramCounter(), 0);
}

TEST(PostMachineTest, CopyConstructorStoppedMachine) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),
        PostMachine::createStop()
    };

    PostMachine machine1(program);
    machine1.executeAll();  // Выполняем всю программу до остановки

    // Машина1 полностью выполнена и остановлена
    EXPECT_FALSE(machine1.getIsRunning());
    EXPECT_EQ(machine1.getProgramCounter(), 1);
    EXPECT_TRUE(machine1.getTape().hasMark(0));

    // Создаем копию остановленной машины
    PostMachine machine2(machine1);

    // Копия должна быть также остановлена
    EXPECT_FALSE(machine2.getIsRunning());
    EXPECT_EQ(machine2.getProgramCounter(), 1);
    EXPECT_TRUE(machine2.getTape().hasMark(0));
}

TEST(PostMachineTest, AssignmentOperatorStoppedMachine) {
    std::vector<Command> program = {
        PostMachine::createMoveRight(1),
        PostMachine::createStop()
    };

    PostMachine machine1(program);
    machine1.executeAll();  // Выполняем всю программу

    // Машина1 остановлена
    EXPECT_FALSE(machine1.getIsRunning());
    EXPECT_EQ(machine1.getProgramCounter(), 1);
    EXPECT_EQ(machine1.getTape().getHeadPosition(), 1);

    // Присваиваем остановленную машину
    PostMachine machine2;
    machine2 = machine1;

    // Проверяем, что состояние скопировано
    EXPECT_FALSE(machine2.getIsRunning());
    EXPECT_EQ(machine2.getProgramCounter(), 1);
    EXPECT_EQ(machine2.getTape().getHeadPosition(), 1);
}

TEST(PostMachineTest, EqualityOperators) {
    std::vector<Command> program = {PostMachine::createStop()};

    PostMachine machine1(program);
    PostMachine machine2(program);

    EXPECT_TRUE(machine1 == machine2);

    machine1.executeStep();
    EXPECT_FALSE(machine1 == machine2);
    EXPECT_TRUE(machine1 != machine2);
}

TEST(PostMachineTest, SetMarkCommand) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),
        PostMachine::createStop()
    };

    PostMachine machine(program);
    EXPECT_TRUE(machine.executeStep());
    EXPECT_TRUE(machine.getTape().hasMark(0));
    EXPECT_EQ(machine.getProgramCounter(), 1);
}

TEST(PostMachineTest, EraseMarkCommand) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),   // 0: Установить метку, перейти к строке 1
        PostMachine::createEraseMark(2), // 1: Стереть метку, перейти к строке 2
        PostMachine::createStop()        // 2: Останов
    };

    PostMachine machine(program);

    // Выполняем первый шаг (SET_MARK)
    EXPECT_TRUE(machine.executeStep());  // Успешно выполнили SET_MARK
    EXPECT_TRUE(machine.getTape().hasMark(0));  // Метка должна быть установлена
    EXPECT_EQ(machine.getProgramCounter(), 1);  // Указатель на ERASE_MARK
    EXPECT_TRUE(machine.getIsRunning());  // Машина еще работает

    // Выполняем второй шаг (ERASE_MARK)
    EXPECT_TRUE(machine.executeStep());  // Успешно выполнили ERASE_MARK
    EXPECT_FALSE(machine.getTape().hasMark(0));  // Метка должна быть стерта
    EXPECT_EQ(machine.getProgramCounter(), 2);  // Указатель на STOP
    EXPECT_TRUE(machine.getIsRunning());  // Машина еще работает (STOP не выполнен)

    // Выполняем третий шаг (STOP)
    EXPECT_TRUE(machine.executeStep());  // Успешно выполнили STOP
    EXPECT_FALSE(machine.getIsRunning());  // Теперь машина остановлена

    // ИЛИ альтернативно можно проверить с помощью executeAll():
    // machine.executeAll();
    // EXPECT_FALSE(machine.getTape().hasMark(0));  // Метка стерта
    // EXPECT_FALSE(machine.getIsRunning());  // Машина остановлена
}

TEST(PostMachineTest, MoveLeftCommand) {
    std::vector<Command> program = {
        PostMachine::createMoveLeft(1),
        PostMachine::createStop()
    };

    PostMachine machine(program);
    machine.executeStep();

    EXPECT_EQ(machine.getTape().getHeadPosition(), -1);
    EXPECT_EQ(machine.getProgramCounter(), 1);
}

TEST(PostMachineTest, MoveRightCommand) {
    std::vector<Command> program = {
        PostMachine::createMoveRight(1),
        PostMachine::createStop()
    };

    PostMachine machine(program);
    machine.executeStep();

    EXPECT_EQ(machine.getTape().getHeadPosition(), 1);
    EXPECT_EQ(machine.getProgramCounter(), 1);
}

TEST(PostMachineTest, ConditionalCommandNoMark) {
    std::vector<Command> program = {
        PostMachine::createConditional(1, 2),
        PostMachine::createSetMark(3),
        PostMachine::createEraseMark(3),
        PostMachine::createStop()
    };

    PostMachine machine(program);
    machine.executeStep();

    EXPECT_EQ(machine.getProgramCounter(), 1);
    EXPECT_TRUE(machine.getIsRunning());
}

TEST(PostMachineTest, ConditionalCommandWithMark) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),         // 0: ставим метку, идем к 1
        PostMachine::createConditional(2, 3),  // 1: если метка есть -> к 3, нет -> к 2
        PostMachine::createSetMark(4),         // 2: ставим метку (не выполнится)
        PostMachine::createEraseMark(4),       // 3: стираем метку (выполнится)
        PostMachine::createStop()              // 4: останов
    };

    PostMachine machine(program);

    // Выполняем всю программу
    machine.executeAll();

    // Проверяем результаты:
    // 1. Должны были выполнить ветку с меткой (ERASE_MARK)
    EXPECT_FALSE(machine.getTape().hasMark(0));  // Метка стерта

    // 2. Машина должна быть остановлена
    EXPECT_FALSE(machine.getIsRunning());

    // 3. Счетчик команд должен быть на STOP
    EXPECT_EQ(machine.getProgramCounter(), 4);

    // 4. Проверяем, что не выполнили ветку без метки
    // (Если бы выполнили SET_MARK, метка осталась бы)
}

TEST(PostMachineTest, StopCommand) {
    std::vector<Command> program = {
        PostMachine::createStop()
    };

    PostMachine machine(program);
    EXPECT_TRUE(machine.getIsRunning());
    EXPECT_TRUE(machine.executeStep());
    EXPECT_FALSE(machine.getIsRunning());
}

TEST(PostMachineTest, ExecuteAllSimple) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),
        PostMachine::createMoveRight(2),
        PostMachine::createStop()
    };

    PostMachine machine(program);
    machine.executeAll();

    EXPECT_FALSE(machine.getIsRunning());
    EXPECT_TRUE(machine.getTape().hasMark(0));
    EXPECT_EQ(machine.getTape().getHeadPosition(), 1);
}

TEST(PostMachineTest, InvalidJumpNegative) {
    std::vector<Command> program = {
        PostMachine::createSetMark(-1)
    };

    PostMachine machine(program);
    EXPECT_FALSE(machine.executeStep());
    EXPECT_FALSE(machine.getIsRunning());
    EXPECT_FALSE(machine.getLastError().empty());
}

TEST(PostMachineTest, InvalidJumpTooLarge) {
    std::vector<Command> program = {
        PostMachine::createSetMark(10)
    };

    PostMachine machine(program);
    EXPECT_FALSE(machine.executeStep());
    EXPECT_FALSE(machine.getIsRunning());
}



TEST(PostMachineTest, LoadProgram) {
    PostMachine machine;

    std::vector<Command> program = {
        PostMachine::createMoveRight(1),
        PostMachine::createStop()
    };

    machine.loadProgram(program);
    EXPECT_TRUE(machine.getIsRunning());
    machine.executeAll();
    EXPECT_EQ(machine.getTape().getHeadPosition(), 1);
    EXPECT_FALSE(machine.getIsRunning());
}


TEST(PostMachineTest, StreamOutputTape) {
    Tape tape;
    tape.setMark(0);
    tape.moveRight();
    tape.setMark(2);

    std::stringstream ss;
    ss << tape;

    std::string output = ss.str();
    EXPECT_TRUE(output.find("Head at position: 1") != std::string::npos);
    EXPECT_TRUE(output.find("X") != std::string::npos);
}

TEST(PostMachineTest, StreamInputTape) {
    std::stringstream ss;
    ss << "0 1\n1 0\n2 1\n";

    Tape tape;
    ss >> tape;

    EXPECT_TRUE(tape.hasMark(0));
    EXPECT_FALSE(tape.hasMark(1));
    EXPECT_TRUE(tape.hasMark(2));
}

TEST(PostMachineTest, StreamOutputMachine) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),
        PostMachine::createStop()
    };

    PostMachine machine(program);

    std::stringstream ss;
    ss << machine;

    std::string output = ss.str();
    EXPECT_TRUE(output.find("Post Machine State") != std::string::npos);
    EXPECT_TRUE(output.find("SET_MARK") != std::string::npos);
    EXPECT_TRUE(output.find("STOP") != std::string::npos);
}

TEST(PostMachineTest, EmptyProgramExecution) {
    PostMachine machine;
    EXPECT_FALSE(machine.executeStep());
    EXPECT_FALSE(machine.getLastError().empty());
}

TEST(PostMachineTest, MultipleResetsAndExecutions) {
    std::vector<Command> program = {
        PostMachine::createSetMark(1),
        PostMachine::createStop()
    };

    PostMachine machine(program);

    for (int i = 0; i < 3; i++) {
        machine.executeAll();
        EXPECT_FALSE(machine.getIsRunning());
        EXPECT_TRUE(machine.getTape().hasMark(0));

        machine.reset();
        EXPECT_TRUE(machine.getIsRunning());
        EXPECT_FALSE(machine.getTape().hasMark(0));
    }
}

TEST(PostMachineTest, DeepCopyTape) {
    Tape tape1;
    tape1.setMark(5);
    tape1.moveRight();

    Tape tape2 = tape1;
    tape2.eraseMark(5);

    EXPECT_TRUE(tape1.hasMark(5));
    EXPECT_FALSE(tape2.hasMark(5));
}

TEST(PostMachineTest, CommandFactoryMethods) {
    EXPECT_EQ(PostMachine::createSetMark(5).type, CommandType::SET_MARK);
    EXPECT_EQ(PostMachine::createSetMark(5).jump1, 5);

    EXPECT_EQ(PostMachine::createEraseMark(3).type, CommandType::ERASE_MARK);
    EXPECT_EQ(PostMachine::createEraseMark(3).jump1, 3);

    EXPECT_EQ(PostMachine::createMoveLeft(2).type, CommandType::MOVE_LEFT);
    EXPECT_EQ(PostMachine::createMoveLeft(2).jump1, 2);

    EXPECT_EQ(PostMachine::createMoveRight(4).type, CommandType::MOVE_RIGHT);
    EXPECT_EQ(PostMachine::createMoveRight(4).jump1, 4);

    EXPECT_EQ(PostMachine::createConditional(1, 2).type, CommandType::CONDITIONAL);
    EXPECT_EQ(PostMachine::createConditional(1, 2).jump1, 1);
    EXPECT_EQ(PostMachine::createConditional(1, 2).jump2, 2);

    EXPECT_EQ(PostMachine::createStop().type, CommandType::STOP);
}

TEST(PostMachineTest, ProgramWithCustomLabels) {
    std::vector<Command> program = {
        Command(CommandType::SET_MARK, 1, 0, "Start"),
        Command(CommandType::MOVE_RIGHT, 2, 0, "Move"),
        Command(CommandType::STOP, 0, 0, "End")
    };

    PostMachine machine(program);

    std::stringstream ss;
    ss << machine;
    std::string output = ss.str();

    EXPECT_TRUE(output.find("Start") != std::string::npos);
    EXPECT_TRUE(output.find("Move") != std::string::npos);
    EXPECT_TRUE(output.find("End") != std::string::npos);
}

TEST(PostMachineTest, GetStateMethods) {
    // Тест проверяет методы получения состояния машины

    std::vector<Command> program = {
        PostMachine::createSetMark(1),  // Установить метку и перейти к строке 1
        PostMachine::createStop()       // Останов
    };

    PostMachine machine(program);

    // 1. Проверяем начальное состояние
    EXPECT_EQ(machine.getProgramCounter(), 0);  // Начинаем с первой команды
    EXPECT_TRUE(machine.getIsRunning());        // Машина должна быть запущена
    EXPECT_TRUE(machine.getLastError().empty()); // Ошибок быть не должно

    // 2. Проверяем начальное состояние ленты
    Tape initialTape = machine.getTape();
    EXPECT_FALSE(initialTape.hasMark(0));  // На ленте не должно быть метки

    // 3. Выполняем один шаг (команду SET_MARK)
    bool stepExecuted = machine.executeStep();

    // Команда SET_MARK должна выполниться успешно
    EXPECT_TRUE(stepExecuted);

    // После выполнения SET_MARK:
    // - Счетчик команд должен указывать на следующую команду (STOP)
    EXPECT_EQ(machine.getProgramCounter(), 1);

    // - Машина все еще должна работать (STOP еще не выполнен)
    EXPECT_TRUE(machine.getIsRunning());

    // - Ошибок быть не должно
    EXPECT_TRUE(machine.getLastError().empty());

    // - На ленте должна появиться метка
    Tape tapeAfterFirstStep = machine.getTape();
    EXPECT_TRUE(tapeAfterFirstStep.hasMark(0));

    // 4. Выполняем второй шаг (команду STOP)
    stepExecuted = machine.executeStep();

    // Команда STOP должна выполниться успешно
    EXPECT_TRUE(stepExecuted);

    // После выполнения STOP:
    // - Машина должна остановиться
    EXPECT_FALSE(machine.getIsRunning());

    // - Ошибок быть не должно
    EXPECT_TRUE(machine.getLastError().empty());

    // - Метка на ленте должна остаться
    Tape finalTape = machine.getTape();
    EXPECT_TRUE(finalTape.hasMark(0));
}

TEST(PostMachineTest, EdgeCaseEmptyConditional) {
    std::vector<Command> program = {
        PostMachine::createConditional(1, 1),
        PostMachine::createStop()
    };

    PostMachine machine(program);
    EXPECT_TRUE(machine.executeStep());
    EXPECT_EQ(machine.getProgramCounter(), 1);
}

TEST(PostMachineTest, CommandEquality) {
    Command cmd1(CommandType::SET_MARK, 1, 0, "test");
    Command cmd2(CommandType::SET_MARK, 1, 0, "test");
    Command cmd3(CommandType::ERASE_MARK, 1, 0, "test");

    EXPECT_TRUE(cmd1 == cmd2);
    EXPECT_FALSE(cmd1 == cmd3);
    EXPECT_TRUE(cmd1 != cmd3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}