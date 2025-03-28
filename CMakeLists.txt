cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (GenPwd)

# This project will output an executable file
add_executable(GenPwd ${PROJECT_SOURCE_DIR}/GenPwd.cpp)

target_include_directories(
    GenPwd
    
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    
    PRIVATE ${PROJECT_SOURCE_DIR}/src
)
target_sources(
GenPwd
#header files
PRIVATE ${PROJECT_SOURCE_DIR}/include/Typedef.hpp
PRIVATE ${PROJECT_SOURCE_DIR}/include/CreatePwd.hpp
PRIVATE ${PROJECT_SOURCE_DIR}/include/Util.hpp
#source files
PRIVATE ${PROJECT_SOURCE_DIR}/src/CreatePwd.cpp
PRIVATE ${PROJECT_SOURCE_DIR}/src/Util.cpp
)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
#target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
