cmake_minimum_required(VERSION 3.16)
project(Nickel)

# Enable testing
enable_testing()

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/systems)

# Find external libraries using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLEW REQUIRED glew)

#find GLFW
find_package(glfw3 3.4 REQUIRED)

# Set source files for the main project
file(GLOB SOURCES src/*.cpp)
add_executable(Nickel ${SOURCES})
# Link external libraries to the main executable
target_link_libraries(Nickel ${GLEW_LIBRARIES})
target_link_libraries(Nickel glfw)
target_include_directories(Nickel PRIVATE ${CMAKE_SOURCE_DIR}/external/cyCodeBase)

