# agbr/CMakeLists.txt
project(agbr C CXX)

# cmake
cmake_minimum_required(VERSION 3.0...3.20 FATAL_ERROR)

# compiler
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fPIC\
    -Wno-unused-command-line-argument")

# dependence
find_package(OpenGL REQUIRED)
MESSAGE(opengl_lib:${OPENGL_LIBRARIES})
SET(GLEW opengl/glew-2.2.0)
SET(GLFW opengl/glfw-3.3.7)
SET(LIBPP github.com/mcinglis)

# mac special
if (APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGL -framework IOKit\
        -framework Cocoa -framework CoreVideo")
endif ()

# dir include
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${GLEW}/include
        ${GLFW}/include
        ${LIBPP}
)

# dir library
link_directories(
        ${GLEW}/build/cmake/cmake-build-debug/lib
        ${GLFW}/cmake-build-debug/src
)

# src of directories
FILE(GLOB maths maths/*.h maths/*.cpp)

# sub modules
add_subdirectory(opengl/example)
