# Runs the program on an input file and checks that its output matches an
# expected-output file exactly (ignoring any '\r').
#
# Usage: cmake -DAPP=<program> -DINPUT=<input file> -DEXPECTED=<expected file>
#              -P compare_output.cmake
execute_process(
  COMMAND ${APP} ${INPUT}
  OUTPUT_VARIABLE actual
  ERROR_VARIABLE errors
  RESULT_VARIABLE exitCode)
file(READ ${EXPECTED} expected)
string(REPLACE "\r" "" actual "${actual}")
string(REPLACE "\r" "" expected "${expected}")

if(NOT exitCode EQUAL 0)
  message(FATAL_ERROR "Program exited with status ${exitCode}.\n${errors}")
endif()
if(NOT actual STREQUAL expected)
  message(FATAL_ERROR
    "Output differs from ${EXPECTED}.\n--- actual ---\n${actual}\n--- expected ---\n${expected}")
endif()
