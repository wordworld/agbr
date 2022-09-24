# agbr/CMakeLists.txt
project(agbr C CXX)

# cmake
cmake_minimum_required(VERSION 3.0...3.20 FATAL_ERROR)

# compiler
set(CMAKE_CXX_STANDARD 20)

# dependence
find_package(OpenGL REQUIRED)
MESSAGE(opengl_lib:${OPENGL_LIBRARIES})
SET(GLEW opengl/glew-2.2.0)
SET(GLFW opengl/glfw-3.3.7)
SET(LIBPP github.com/mcinglis)

# dir include
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${GLEW}/include
        ${GLFW}/include
        ${LIBPP}
)

# library
SET(GLEW_LIB_DIR ${GLEW}/build/cmake/cmake-build-debug/lib)
SET(GLFW_LIB_DIR ${GLFW}/cmake-build-debug/src)
LIST(APPEND OPENGL_3RD_LIBS glfw3)
if (WIN32)
    SET(NEED_MSVC_TOOLSET 141)
    if (${MSVC_TOOLSET_VERSION} EQUAL ${NEED_MSVC_TOOLSET})
        ADD_COMPILE_OPTIONS(/experimental:preprocessor) # vs 2017
    elseif (${MSVC_TOOLSET_VERSION} GREATER ${NEED_MSVC_TOOLSET})
        ADD_COMPILE_OPTIONS(/Zc:preprocessor) # vs>=2019
    else () # 低版本的 visual studio 编译 libpp 失败
        MESSAGE(FATAL_ERROR "Need MSVC_TOOLSET_VERSION ${NEED_MSVC_TOOLSET} or later, current is ${MSVC_TOOLSET_VERSION}")
    endif ()
    # win32 debug
    LIST(APPEND OPENGL_3RD_LIBS glew32d)
    SET(GLEW_LIB_DIR ${GLEW_LIB_DIR}/${CMAKE_CONFIGURATION_TYPES})
    SET(GLFW_LIB_DIR ${GLFW_LIB_DIR}/${CMAKE_CONFIGURATION_TYPES})
else ()
    LIST(APPEND OPENGL_3RD_LIBS glewd)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fPIC\
        -Wno-macro-redefined\
        -Wno-unused-command-line-argument")
    if (APPLE)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGL -framework IOKit\
        -framework Cocoa -framework CoreVideo")
    endif ()
endif ()
link_directories(
        ${GLEW_LIB_DIR}
        ${GLFW_LIB_DIR}
)

# src of directories
FILE(GLOB maths maths/*.h maths/*.cpp)

# sub modules
add_subdirectory(opengl/example)
add_subdirectory(demo)