add_custom_target(copy-names-makefile ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/names.txt)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/names.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/names.txt
        ${CMAKE_CURRENT_BINARY_DIR}/names.txt
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/names.txt)

add_executable(Problem22 main.cpp)
add_dependencies(Problem22 copy-names-makefile)
target_link_libraries(Problem22)