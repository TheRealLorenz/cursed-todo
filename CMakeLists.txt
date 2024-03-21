cmake_minimum_required(VERSION 3.10)
project(cursed-todo)


set(CMAKE_CXX_STANDARD 11)

set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cursed-todo main.cpp
              App.h App.cpp
              Todo.h Todo.cpp
)
target_link_libraries(cursed-todo ${CURSES_LIBRARIES})
