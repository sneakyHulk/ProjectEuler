add_custom_target(copy-input-makefile ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/input.txt)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/input.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        ${CMAKE_CURRENT_BINARY_DIR}/input.txt
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)

add_executable(Problem18 main.cpp)
add_dependencies(Problem18 copy-input-makefile)
target_link_libraries(Problem18)