# tests/CMakeLists.txt

# Обязательно загружаем модуль GoogleTest
include(GoogleTest)

# Собираем тестовые файлы
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS *.cpp)

# Создаём исполняемый файл
add_executable(runTests ${TEST_SOURCES})

# Линкуем с gtest
target_link_libraries(runTests gtest gtest_main)

# Добавляем заголовки основного проекта
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR})

# Добавляем реализации классов
file(GLOB_RECURSE PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/models/*.cpp
        ${CMAKE_SOURCE_DIR}/exceptions/*.cpp
        ${CMAKE_SOURCE_DIR}/managers/*.cpp
        ${CMAKE_SOURCE_DIR}/services/*.cpp
)
target_sources(runTests PRIVATE ${PROJECT_SOURCES})

# Теперь эта команда доступна!
gtest_discover_tests(runTests)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")