include(GoogleTest)

add_executable(project3_unit_tests creditCard_tests.cpp)
target_link_libraries(
  project3_unit_tests
  PRIVATE
  project3_credit_card_account
  GTest::gtest_main
)

# Automatically discovers each TEST(...) case and registers it with CTest
# (and therefore with VS Code's Test Explorer) individually.
gtest_discover_tests(project3_unit_tests)
