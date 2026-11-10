# Project 6: Message Sorter

Start here, then follow the assignment handout on Canvas.

## What is provided (do not change)

- `src/ListInterface.h`, `src/Node.h`, `src/Node.cpp`: the List ADT interface
  and the node class from class.
- `src/MessageIO.h`, `src/MessageIO.cpp`: `parseMessage()`, `formatMessage()`,
  and `printMessages()`.
- `data/messages_small.txt` and `data/expected_small_output.txt`: a small input
  file and the exact output your program should print for it.
- `data/messages_large.txt`: 5,000 messages for checking speed and larger lists.
- `tests/`: the provided tests and the CMake files that run them.
- `CMakeLists.txt` and `src/CMakeLists.txt`.

## What you write

- `src/Message.h` and `src/Message.cpp`: the `Message` class (placeholders now).
- `src/LinkedList.cpp`: replace the three merge sort stubs at the bottom of the
  file. The declarations and contracts are in `src/LinkedList.h`.
- `src/main.cpp`: the program (a skeleton now).

`Node.cpp` and `LinkedList.cpp` are included by their headers because they
hold templates. They are not listed in the CMake files; leave that as is.
