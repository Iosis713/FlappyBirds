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

set(SRC         Sprite.cpp)

add_library(commonLibrary STATIC  Sprite.cpp)

add_executable(TestRunner   testRunner.cpp)
target_link_libraries(TestRunner PRIVATE    ${GTEST_LIBRARIES}
                                            ${GMOCK_LIBRARIES}
                                            ${SFML_LIB}
                                            commonLibrary
                                            pthread)

add_executable(FlappyBirds  main.cpp)
target_link_libraries(FlappyBirds PRIVATE   ${SFML_LIB}
                                            commonLibrary)

target_compile_options(TestRunner PRIVATE ${FLAGS})
target_compile_options(FlappyBirds PRIVATE ${FLAGS})
target_compile_options(commonLibrary PRIVATE ${FLAGS})

set_target_properties(TestRunner    PROPERTIES
                                    CXX_STANDARD 20
                                    CXX_STANDARD_REQUIRED ON)

set_target_properties(FlappyBirds   PROPERTIES
                                    CXX_STANDARD 20
                                    CXX_STANDARD_REQUIRED ON)

set_target_properties(commonLibrary     PROPERTIES
                                        CXX_STANDARD 20
                                        CXX_STANDARD_REQUIRED ON)

