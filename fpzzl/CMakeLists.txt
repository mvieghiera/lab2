cmake_minimum_required(VERSION 3.10)
project(FifteenPuzzleTests)

set(CMAKE_CXX_STANDARD 17)

# 1. ЗАГРУЗКА GOOGLE TEST (ПРОСТОЙ СПОСОБ)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(googletest)

# 2. ВАШИ ИСХОДНЫЕ ФАЙЛЫ
add_executable(FifteenPuzzleTests
        fifteen_puzzle.cpp
        tests.cpp
)

# 3. ПОДКЛЮЧЕНИЕ GTEST
target_link_libraries(FifteenPuzzleTests
        PRIVATE
        gtest
        gtest_main
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")