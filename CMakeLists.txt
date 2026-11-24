cmake_minimum_required(VERSION 3.10)
project(mealplan C)

set(CMAKE_C_STANDARD 11)

add_executable(mealplan
    backend/c/main.c
    backend/c/catalog.c
    backend/c/recipes.c
    backend/c/price.c
    backend/c/terminal.c)

if(MSVC)
    target_compile_options(mealplan PRIVATE /W4)
else()
    target_compile_options(mealplan PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

if(WIN32)
    string(REPLACE "/" "\\" SOURCE_DIR_WIN "${CMAKE_SOURCE_DIR}")
    string(REPLACE "/" "\\" RUN_BAT_WIN "${CMAKE_BINARY_DIR}/run_$<CONFIG>.bat")
    file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/run_$<CONFIG>.bat"
        CONTENT "@echo off\r\nchcp 65001 >nul\r\ncd /d \"${SOURCE_DIR_WIN}\"\r\n\"$<TARGET_FILE:mealplan>\"\r\npause\r\n")
    add_custom_target(run
        COMMAND cmd /c start "" /wait "${RUN_BAT_WIN}"
        DEPENDS mealplan
        VERBATIM)
else()
    add_custom_target(run
        COMMAND mealplan
        DEPENDS mealplan
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        USES_TERMINAL)
endif()
