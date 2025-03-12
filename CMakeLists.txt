cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES *.cpp)

# Создаём тестовый исполняемый файл
add_executable(testproj main.cpp candle.cpp candle.h tests.cpp)

# Линкуем Google Test
target_link_libraries(testproj PRIVATE gtest gtest_main)

# Включаем тестирование
enable_testing()
include(GoogleTest)
gtest_discover_tests(testproj)