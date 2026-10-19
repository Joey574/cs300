include(GoogleTest)

add_executable(project4_unit_tests oneToN_tests.cpp)
target_link_libraries(
  project4_unit_tests
  PRIVATE
  project4_summation_timer
  GTest::gtest_main
)

# Automatically discovers each TEST(...) case and registers it with CTest
# (and therefore with VS Code's Test Explorer) individually.
gtest_discover_tests(project4_unit_tests)
