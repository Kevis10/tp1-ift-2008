add_executable(test_porte test_porte.cpp)
add_test(test_porte test_porte)
target_link_libraries(test_porte porte piece ${GTEST_LIBRARIES})
