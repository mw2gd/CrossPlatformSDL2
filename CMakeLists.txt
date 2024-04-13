# -------------------------
# Cmake Project Template
# ${PROJECT_SOURCE_DIR}
# -------------------------

cmake_minimum_required(VERSION 3.5)

project(App VERSION 1.0 LANGUAGES C CXX)

if(EMSCRIPTEN)
    add_link_options(--shell-file ${PROJECT_SOURCE_DIR}/simple_shell.html)
    add_compile_definitions(EMSCRIPTEN=1)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

add_subdirectory(src)