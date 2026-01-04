# CMakeLists.txt

cmake_minimum_required(VERSION 3.14)
project(AutoRepairShop VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# === Подключаем Google Test через FetchContent ===
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)

# Предотвращаем конфликт с CRT на Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Загружаем
FetchContent_MakeAvailable(googletest)

# === 🔥 КЛЮЧЕВОЙ ШАГ: добавляем CMake-модули Google Test в путь ===
list(APPEND CMAKE_MODULE_PATH "${googletest_SOURCE_DIR}/cmake")

# === Добавляем include директории ===
include_directories(${CMAKE_SOURCE_DIR})

# === Основное приложение ===
file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/*.cpp
)
list(FILTER MAIN_SOURCES EXCLUDE REGEX "tests/.*")

add_executable(AutoRepairShop ${MAIN_SOURCES})

# === Включаем тесты ===
enable_testing()
add_subdirectory(tests)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")