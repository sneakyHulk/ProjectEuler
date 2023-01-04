add_executable(Problem32 main.cpp)
#set_target_properties(Problem32 PROPERTIES LINK_FLAGS -Wl,-z,stack-size=100000000)
target_link_libraries(Problem32)
