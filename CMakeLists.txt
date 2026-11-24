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

add_custom_target(run
    COMMAND mealplan
    DEPENDS mealplan
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    USES_TERMINAL)
