cmake_minimum_required(VERSION 3.5)
project(FINAL-problem3 CXX)

# require a C++11 compiler
# use it for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# configure Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# create the executable
add_executable(LEDController main.cpp main_window.hpp main_window.cpp color_palette.hpp 
                color_palette.cpp pattern_list.hpp pattern_list.cpp canvas_widget.hpp canvas_widget.cpp 
                audio.hpp audio.cpp)
target_link_libraries(LEDController Qt5::Widgets)
