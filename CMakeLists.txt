cmake_minimum_required(VERSION 3.10)
project(mealplan C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib)
add_subdirectory(bin)

add_custom_target(run
    COMMAND mealplan
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    USES_TERMINAL)

find_package(Python3 3.0...<3.15 COMPONENTS Interpreter)

add_custom_target(web
    COMMAND ${Python3_EXECUTABLE} -m http.server --cgi 8000
    DEPENDS web_cgi stock_cgi
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    USES_TERMINAL)
