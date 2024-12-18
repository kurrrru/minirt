#!/bin/bash

# Script to test all scene files in the 'scenes' folder using miniRT
# Directory containing scene test cases
TEST_DIR="scenes"
EXECUTABLE="../../minirt"

# ANSI color codes for output
RED="\033[0;31m"
GREEN="\033[0;32m"
RESET="\033[0m"

# Check if miniRT is executable
if [ ! -x "$EXECUTABLE" ]; then
    echo -e "${RED}Error: $EXECUTABLE not found or not executable.${RESET}"
    exit 1
fi

# Function to check if window opens
function test_window_open() {
    timeout 3 $EXECUTABLE "$1" &
    PID=$!

    # Allow the program to start
    sleep 2

    # Check if the process is still running
    if ps -p $PID > /dev/null; then
        # Window likely opened successfully
        kill $PID >/dev/null 2>&1
        return 0
    else
        # Window did not open
        return 1
    fi
}

# Test case execution
echo "Running scene test cases..."
for test_case in ./*.rt; do
    echo "--------------------------------------------"
    echo "Running test case: $(basename "$test_case")"

    # Run test and check result
    if test_window_open "$test_case"; then
        echo -e "${GREEN}Test PASSED:${RESET} $(basename "$test_case") window opened successfully."
    else
        echo -e "${RED}Test FAILED:${RESET} $(basename "$test_case") window did not open."
    fi
done
echo "--------------------------------------------"
echo "All scene tests completed."
