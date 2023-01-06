find_package(Boost REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})
message("boost lib: ${Boost_LIBRARIES}")
message("boost inc:${Boost_INCLUDE_DIR}")

add_executable(Problem33 main.cpp)
target_link_libraries(Problem33 ${Boost_LIBRARIES})