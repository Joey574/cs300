add_library(project2_shopping_cart STATIC
  arraybag.hpp
  arraybag.cpp
  product.hpp
  cart.hpp
)

target_include_directories(
  project2_shopping_cart
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(project2_app main.cpp)
target_link_libraries(project2_app PRIVATE project2_shopping_cart)
