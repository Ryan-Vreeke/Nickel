cmake_minimum_required(VERSION 3.16)
project(Nickel)

# Enable testing
enable_testing()

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1  # You can choose a specific release
)
# Fetch and make GoogleTest available
FetchContent_MakeAvailable(googletest)

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

#find GLUT
find_package(GLUT REQUIRED)

# Set source files for the main project
file(GLOB SOURCES src/*.cpp)
list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Add the main executable
add_executable(Nickel src/main.cpp ${SOURCES})

# Link external libraries to the main executable
target_link_libraries(Nickel ${GLEW_LIBRARIES} GLUT::GLUT)
target_include_directories(Nickel PRIVATE ${CMAKE_SOURCE_DIR}/external/cyCodeBase)

# ===== Google Test Integration ===== #

# Test source files
file(GLOB TEST_SOURCES tests/*.cpp)

# Add a separate executable for running tests
add_executable(NickelTests ${TEST_SOURCES} ${SOURCES})

# Link GoogleTest and the tested libraries to the test executable
target_link_libraries(NickelTests gtest gtest_main)

# Link the same libraries (e.g., GLEW) if your tests depend on them
target_link_libraries(NickelTests ${GLEW_LIBRARIES} GLUT::GLUT)
target_include_directories(NickelTests PRIVATE ${CMAKE_SOURCE_DIR}/external/cyCodeBase)

# Add the test executable to CTest
add_test(NAME NickelTests COMMAND NickelTests)

