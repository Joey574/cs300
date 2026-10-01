include(GoogleTest)

add_executable(project2_unit_tests arraybag_tests.cpp)
target_link_libraries(
  project2_unit_tests
  PRIVATE
  project2_shopping_cart
  GTest::gtest_main
)

# Automatically discovers each TEST(...) case and registers it with CTest
# (and therefore with VS Code's Test Explorer) individually.
gtest_discover_tests(project2_unit_tests)
