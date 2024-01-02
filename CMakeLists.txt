cmake_minimum_required(VERSION 3.14)
project(FlappyBirds)
set(CXX_STANDARD_REQUIRED 20)
find_package(GTest REQUIRED)

set(FLAGS   -Wall -Wextra -Werror -Wpedantic)
set(GMOCK_LIBRARIES     /usr/lib/libgmock.a
                        /usr/lib/libgmock_main.a)

set(SFML_LIB    sfml-graphics
                sfml-window
                sfml-system)


add_executable(TestRunner   testRunner.cpp)
target_link_libraries(TestRunner    ${GTEST_LIBRARIES}
                                    ${GMOCK_LIBRARIES}
                                    ${SFML_LIB}
                                    pthread)




add_executable(FlappyBirds  main.cpp)
target_link_libraries(FlappyBirds   ${SFML_LIB})



