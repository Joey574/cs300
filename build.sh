#!/bin/sh
cmake -S . -G Ninja -B build
cmake --build build -j
