cmake_minimum_required(VERSION 3.5)
project(CodeTP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Labyrinthe.cpp
    Labyrinthe.h
    Piece.cpp
    Piece.h
    Porte.cpp
    Porte.h
    Principal.cpp)

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



add_executable(CodeTP ${SOURCE_FILES})