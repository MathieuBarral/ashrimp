cmake_minimum_required(VERSION 3.0.0)
project(ashrimp VERSION 0.1.0)

include_directories("include")
include_directories("lib/gc/include")
include_directories("lib/parser/include")
include_directories("lib/utils/include")
include_directories("lib/valloc/include")

set(CMAKE_C_FLAGS "-Wno-deprecated")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "-g3 -Wno-deprecated -fprofile-arcs -ftest-coverage")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

add_subdirectory("lib")
add_subdirectory("src")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(test/CMakeLists.txt)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
