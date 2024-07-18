cmake_minimum_required(VERSION 3.2)
project(TomlParser)

# -----------------------------------------------------------------------------
# Set Variables
# 
set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(BIN_NAME "TOMLP")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(CMAKE_C_FLAGS  "-Wall -fno-strict-aliasing")
 

# -----------------------------------------------------------------------------
# Add debug option
# 
option(DEV_DEBUG "Enter debug mode" 0)
if (DEV_DEBUG)
  add_definitions(-DDEV_DEBUG)
endif()


# -----------------------------------------------------------------------------
# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})


# -----------------------------------------------------------------------------
# Create the final binary
# 
add_executable(${BIN_NAME} main.c)


# -----------------------------------------------------------------------------
# Build the Toml Parser Library
# 
set(TOML_PARSER_LIB "TomlParser")

add_library(${TOML_PARSER_LIB} STATIC
  "${SRC_DIR}/toml_parser.c"
  "${SRC_DIR}/toml_print.c"
)


# -----------------------------------------------------------------------------
# Link the libraries
# 
target_link_libraries(${BIN_NAME} ${TOML_PARSER_LIB})

