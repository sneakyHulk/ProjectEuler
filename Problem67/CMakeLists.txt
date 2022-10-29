add_custom_target(copy-triangle-makefile ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/triangle.txt)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/triangle.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/triangle.txt
        ${CMAKE_CURRENT_BINARY_DIR}/triangle.txt
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/triangle.txt)

add_executable(Problem67 main.cpp)
add_dependencies(Problem67 copy-triangle-makefile)
target_link_libraries(Problem67)