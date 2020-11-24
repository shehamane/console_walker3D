cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

project(ConsoleWalker3D)

set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB src/lib/Map.cpp src/lib/Screen.cpp src/lib/Square.cpp src/lib/Player.cpp src/lib/Frame.cpp)

add_library(MAIN STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})
add_executable(test_square src/tests/square.cpp)

target_link_libraries(main MAIN)
target_link_libraries(test_square MAIN)