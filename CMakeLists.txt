cmake_minimum_required(VERSION 3.10)

project(DesktopFramework)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(DEFINED BUILD_TESTS)
    add_subdirectory(Tests)
endif()

if(DEFINED BUILD_EXAMPLES)
    add_subdirectory(Examples)
endif()

add_subdirectory(Lua)

file(GLOB_RECURSE SOURCE_FILES
    "Source/**.cpp"
    "Source/**.hpp"
)

# Building as a library isn't required, however, it will reduce file size of your own project.
# If you don't want to build as a library, just copy the source files into your project.
# Built as a static library by default.
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC Source)