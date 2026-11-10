# Node.cpp and LinkedList.cpp are not listed: they hold template code that
# Node.h and LinkedList.h include.
add_library(project6_lib STATIC
  Message.cpp
  MessageIO.cpp
)
target_include_directories(project6_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(project6_app main.cpp)
target_link_libraries(project6_app PRIVATE project6_lib)
