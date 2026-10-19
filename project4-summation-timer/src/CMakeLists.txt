add_library(project4_summation_timer STATIC
  oneToN.hpp
  oneToN.cpp
)

target_include_directories(
  project4_summation_timer
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(project4_app main.cpp)
target_link_libraries(project4_app PRIVATE project4_summation_timer)
