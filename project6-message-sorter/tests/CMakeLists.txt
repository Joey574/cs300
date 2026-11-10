add_executable(project6_tests project6_tests.cpp)
target_link_libraries(project6_tests PRIVATE project6_lib GTest::gtest_main)
target_compile_definitions(project6_tests PRIVATE
  PROJECT6_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/../data")
add_test(NAME project6_unit_tests COMMAND project6_tests)

# Runs the program on the small file and compares its output with
# data/expected_small_output.txt.
add_test(NAME project6_app_small_file
  COMMAND ${CMAKE_COMMAND}
    -DAPP=$<TARGET_FILE:project6_app>
    -DINPUT=${CMAKE_CURRENT_SOURCE_DIR}/../data/messages_small.txt
    -DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/../data/expected_small_output.txt
    -P ${CMAKE_CURRENT_SOURCE_DIR}/compare_output.cmake)

# The program must exit with a non-zero status when it cannot do its job.
add_test(NAME project6_app_no_argument COMMAND project6_app)
set_tests_properties(project6_app_no_argument PROPERTIES WILL_FAIL TRUE)

add_test(NAME project6_app_missing_file
  COMMAND project6_app ${CMAKE_CURRENT_SOURCE_DIR}/../data/no_such_file.txt)
set_tests_properties(project6_app_missing_file PROPERTIES WILL_FAIL TRUE)
