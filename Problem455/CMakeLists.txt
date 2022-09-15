add_executable(Problem455_long main_with_last_digits.cpp)
find_package(OpenMP REQUIRED)
target_link_libraries(Problem455_long PUBLIC OpenMP::OpenMP_CXX)

add_executable(Problem455 main.cpp)
find_package(OpenMP REQUIRED)
target_link_libraries(Problem455 PUBLIC OpenMP::OpenMP_CXX)
