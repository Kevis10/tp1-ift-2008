add_executable(test_labyrinthe test_labyrinthe.cpp)
add_test(test_labyrinthe test_labyrinthe)
target_link_libraries(test_labyrinthe ${GTEST_LIBRARIES} ${SOURCE_FILES})

add_executable(test_piece test_piece.cpp)
add_test(test_piece test_piece)
target_link_libraries(test_piece ${GTEST_LIBRARIES} ${SOURCE_FILES})

add_executable(test_porte test_porte.cpp)
add_test(test_porte test_porte)
target_link_libraries(test_porte ${GTEST_LIBRARIES} ${SOURCE_FILES})
