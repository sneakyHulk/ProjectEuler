find_package(root REQUIRED)

include_directories()
add_executable(Problem810 main.cpp)
target_link_libraries(Problem810 ROOT::Core ROOT::Graf ROOT::Gpad)