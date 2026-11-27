add_library(meal STATIC catalog.c recipes.c price.c terminal.c)
target_include_directories(meal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
