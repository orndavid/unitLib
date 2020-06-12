cmake_minimum_required(VERSION 3.15)
project(template VERSION 0.0.1 LANGUAGES CXX DESCRIPTION "A unit conversion library")

set(NAME project)
# Configure the release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE release)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# WARNING this is set to the current architecture
set(CMAKE_CXX_FLAGS "-Wall -std=c++17 -march=native")
message("Build type " ${CMAKE_BUILD_TYPE})

# Set library header folder
include_directories(debug PUBLIC ${CMAKE_SOURCE_DIR}/inc )
include_directories(debug PUBLIC ${CMAKE_SOURCE_DIR}/src )

# Build the library
add_subdirectory(inc)
add_subdirectory(src)

# Main fuss of the system
add_library(unitLib SHARED
            ${lib_sources}
            ${lib_headers})

set_target_properties(unitLib PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(unitLib PRIVATE .)
set_target_properties(unitLib PROPERTIES PUBLIC_HEADER inc/unitLib.h)

if(${CMAKE_BUILD_TYPE} STREQUAL release)
    message("Building in release mode")
    #add_executable()
    # target_compile_options()
elseif(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Building in debug mode")
    enable_testing()
    include(GoogleTest)
    message("Found GoogleTests")
    message("Building TESTS")
    add_subdirectory(tests)

    # Additional method for debugging during development
    add_executable(debug ${debug_files} ${lib_headers})
    target_link_libraries(debug PUBLIC unitLib)
    target_compile_options(debug PUBLIC -Wall -ggdb -O0)
endif()
