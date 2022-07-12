# agbr/demo/CMakeLists.txt

# library
link_libraries(
        ${OPENGL_LIBRARIES}
        ${OPENGL_3RD_LIBS}
)

# common
LIST(APPEND SRC_COMMON ${maths})
add_definitions(-DWIN_WIDTH=1024 -DWIN_HEIGHT=768)

# demos
FILE(GLOB children ${CMAKE_CURRENT_SOURCE_DIR}/*)
FOREACH (sub ${children})
    if (NOT IS_DIRECTORY ${sub})
        CONTINUE()
    endif ()
    GET_FILENAME_COMPONENT(demo ${sub} NAME)
    FILE(GLOB SRC_DEMO ${sub}/*.h ${sub}/*.cpp)
    add_definitions(-DAPP_NAME=${demo})
    add_executable(${demo} ${SRC_DEMO} ${SRC_COMMON})
    LIST(APPEND demos ${demo})
ENDFOREACH ()
MESSAGE("demo_list: ${demos}")