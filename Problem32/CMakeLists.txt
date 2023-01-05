add_executable(Problem32 main.cpp progressbar.h)
set_target_properties(Problem32 PROPERTIES LINK_FLAGS -Wl,-z,stack-size=1000000000)
target_link_libraries(Problem32)
