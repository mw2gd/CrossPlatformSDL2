# -------------------------
# Cmake Project Template
# ${PROJECT_SOURCE_DIR}
# -------------------------

cmake_minimum_required(VERSION 3.5)

project(App VERSION 1.0 LANGUAGES C CXX)

# Define high level target options
if(EMSCRIPTEN)
    add_link_options(--shell-file ${PROJECT_SOURCE_DIR}/simple_shell.html)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    add_compile_definitions(EMSCRIPTEN=1)
elseif(APPLE)
    add_compile_definitions(APPLE=1)
elseif(WIN32)
    add_compile_definitions(WIN32=1)
elseif(UNIX)
    add_compile_definitions(UNIX=1)
endif()

add_subdirectory(src)