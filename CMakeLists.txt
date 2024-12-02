cmake_minimum_required(VERSION 3.11)
project(ftransfer CXX)

SET(THIRD_DIR third-src)

# Add spdlog

ADD_SUBDIRECTORY(${THIRD_DIR}/spdlog)

INCLUDE_DIRECTORIES(${THIRD_DIR}/spdlog/include)

# Add JSONCPP

ADD_SUBDIRECTORY(${THIRD_DIR}/jsoncpp)

INCLUDE_DIRECTORIES(${THIRD_DIR}/jsoncpp/include)

# Add libevent

ADD_SUBDIRECTORY(${THIRD_DIR}/libevent)

INCLUDE_DIRECTORIES(${THIRD_DIR}/libevent/include)

# Add source files

AUX_SOURCE_DIRECTORY(./debug SOURCE_LIST)

# Debug messages

message("Source files: ${SOURCE_LIST}")

# Target executable

add_executable(ftransfer ${SOURCE_LIST})

# Link to libs

target_link_libraries(ftransfer event_core jsoncpp_lib spdlog)
