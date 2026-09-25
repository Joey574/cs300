include(GoogleTest)

add_executable(project1_unit_tests clock_test.cpp)
target_link_libraries(project1_unit_tests PRIVATE project1_clock GTest::gtest_main)

# Automatically discovers each TEST(...) case and registers it with CTest
# (and therefore with VS Code's Test Explorer) individually.
gtest_discover_tests(project1_unit_tests)
