cmake_minimum_required(VERSION 3.2)
project(TomlParser)

# Variables.
# 
set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(BIN_NAME "TomlParser")

# Find all source files.
# 
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.c")

# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})

# Create the final binary.
# 
add_executable(${BIN_NAME} main.c ${SRC_FILES})

# Link in any libraies the binary needs.
# 
#target_link_libraries(${BIN_NAME} raylib m)
