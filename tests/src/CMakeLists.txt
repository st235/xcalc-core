set(TESTS_EXECUTABLE ${PROJECT_NAME}_tests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${TEST_SOURCES})

add_executable(${TESTS_EXECUTABLE} ${TEST_SOURCES} binary_operators_check.cpp)
target_link_libraries(${TESTS_EXECUTABLE} ${PROJECT_NAME} libgtest)
add_test(NAME ${TESTS_EXECUTABLE} COMMAND ${TESTS_EXECUTABLE})
