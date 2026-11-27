add_executable(mealplan main.c)
target_link_libraries(mealplan PUBLIC meal)

add_executable(web_cgi web.c)
target_link_libraries(web_cgi PUBLIC meal)

add_executable(stock_cgi stock.c)
target_link_libraries(stock_cgi PUBLIC meal)

set_target_properties(web_cgi PROPERTIES OUTPUT_NAME mealplan)
set_target_properties(stock_cgi PROPERTIES OUTPUT_NAME stock)
set_target_properties(web_cgi stock_cgi PROPERTIES
    SUFFIX ".cgi"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/cgi-bin)
