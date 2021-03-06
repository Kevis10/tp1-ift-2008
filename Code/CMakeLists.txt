cmake_minimum_required(VERSION 3.5)
project(CodeTP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


option(BUILD_TESTING "build unit tests" ON)

if(BUILD_TESTING)
  include(ExternalProject)

  ExternalProject_add(gtest-target
    GIT_REPOSITORY "https://github.com/google/googletest"
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/extern"
    UPDATE_COMMAND ""
  )

  include_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/include)
  link_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/lib)
  set(GTEST_LIBRARIES gtest gmock gtest_main gmock_main pthread)

  enable_testing()

  add_subdirectory(test)
endif()

add_library(porte STATIC Porte.cpp)
target_include_directories(porte PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(piece STATIC Piece.cpp)
target_include_directories(piece PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(labyrinthe STATIC Labyrinthe.cpp)
target_link_libraries(labyrinthe piece porte)
target_include_directories(labyrinthe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

