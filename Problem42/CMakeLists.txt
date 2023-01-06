add_custom_target(copy-words-makefile ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/words.txt)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/words.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/words.txt
        ${CMAKE_CURRENT_BINARY_DIR}/words.txt
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/words.txt)

add_executable(Problem42 main.cpp)
add_dependencies(Problem42 copy-words-makefile)
target_link_libraries(Problem42)