cmake_minimum_required(VERSION 3.10)

project(LuaImplementation)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCE_FILES
    "Source/**.cpp"
    "Source/**.hpp"
)

add_subdirectory(LuaU)

# Building as a library isn't required, however, it will reduce file size of your own project.
# If you don't want to build as a library, just copy the source files into your project.
# Built as a static library by default.
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Luau.VM Luau.Compiler)
target_link_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/LuaU" "${PROJECT_SOURCE_DIR}/LuaU/Compiler" "${PROJECT_SOURCE_DIR}/LuaU/VM")