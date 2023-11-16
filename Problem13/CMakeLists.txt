find_package(Boost REQUIRED)
#find_package(GMP REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})
message("boost lib: ${Boost_LIBRARIES}")
message("boost inc:${Boost_INCLUDE_DIR}")

add_executable(Problem13 main.cpp)
target_link_libraries(Problem13 PRIVATE Boost::headers gmp) # needs sudo apt install libboost-all-dev libgmp3-dev