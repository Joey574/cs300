add_library(project3_credit_card_account STATIC
  creditCard.hpp
  creditCard.cpp
  transaction.hpp
  transaction.cpp
)

target_include_directories(
  project3_credit_card_account
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(project3_app main.cpp)
target_link_libraries(project3_app PRIVATE project3_credit_card_account)
