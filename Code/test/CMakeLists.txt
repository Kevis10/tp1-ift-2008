add_executable(test_porte test_porte.cpp)
add_test(test_porte test_porte)
target_link_libraries(test_porte porte piece ${GTEST_LIBRARIES})

add_executable(test_piece test_piece.cpp)
add_test(test_piece test_piece)
target_link_libraries(test_piece porte piece ${GTEST_LIBRARIES})

add_executable(test_labyrinthe test_labyrinthe.cpp)
add_test(test_labyrinthe test_labyrinthe)
target_link_libraries(test_labyrinthe porte piece labyrinthe ${GTEST_LIBRARIES})
