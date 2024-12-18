#!/bin/bash

# Script to run all input_error test cases with miniRT
# Directory containing input_error cases
TEST_DIR="input_error"
EXECUTABLE="../../minirt"

# ANSI color codes
RED="\033[0;31m"
GREEN="\033[0;32m"
RESET="\033[0m"

# Check if miniRT is executable
if [ ! -x "$EXECUTABLE" ]; then
    echo -e "${RED}Error: $EXECUTABLE not found or not executable.${RESET}"
    exit 1
fi

# Test case execution
echo "Running input error test cases..."
for test_case in ./*.rt; do
    echo "--------------------------------------------"
    echo "Running test case: $(basename "$test_case")"
    
    # Execute the program and capture the output
    output=$($EXECUTABLE "$test_case" 2>&1)
    exit_code=$?
    
    # Check if the program returned an error as expected
    if [[ $exit_code -ne 0 && $output == *"Error"* ]]; then
        echo -e "${GREEN}Test PASSED:${RESET} $(basename "$test_case") returned error as expected."
    else
        echo -e "${RED}Test FAILED:${RESET} $(basename "$test_case") did not behave as expected."
        echo "Output:"
        echo "$output"
    fi
done
echo "--------------------------------------------"
echo "All input error tests completed."
