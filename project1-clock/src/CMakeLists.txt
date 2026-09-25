add_library(project1_clock STATIC
    clock.cpp
    clock.hpp
)

target_include_directories(project1_clock PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(project1_app main.cpp)
target_link_libraries(project1_app PRIVATE project1_clock)
