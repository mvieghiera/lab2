cmake_minimum_required(VERSION 3.10)
project(PostMachineProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Для MinGW отключаем pthread и проблемные флаги
if(MINGW)
    add_definitions(-DGTEST_HAS_PTHREAD=0)
    add_definitions(-D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING)
    add_definitions(-D_WIN32_WINNT=0x0A00)
endif()

# 1. Настраиваем Google Test БЕЗ GMock
option(BUILD_GMOCK "Build GMock" OFF)
option(INSTALL_GTEST "Install GTest" OFF)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# 2. Подключаем только googletest (не googlemock)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/googletest/CMakeLists.txt")
    # Используем только googletest поддиректорию
    add_subdirectory(googletest)
    message(STATUS "Google Test подключен (без GMock)")
else()
    message(FATAL_ERROR "Google Test не найден! Скачайте: git clone https://github.com/google/googletest.git")
endif()

# 3. Основная библиотека проекта
add_library(PostMachineLib STATIC src/PostMachine.cpp)
target_include_directories(PostMachineLib PUBLIC include)

# 4. Тесты (только с gtest, без gmock)
add_executable(PostMachineTests tests/PostMachineTests.cpp)
target_include_directories(PostMachineTests PRIVATE include)

# Важно: линкуем только с gtest и gtest_main
target_link_libraries(PostMachineTests
        PostMachineLib
        gtest
        gtest_main
)

# 5. Активируем тестирование
enable_testing()
add_test(NAME PostMachineTests COMMAND PostMachineTests)

# 6. Устанавливаем свойства для правильной компиляции
set_target_properties(PostMachineTests PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")




