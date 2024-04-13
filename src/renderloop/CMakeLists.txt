# -------------------------
# Cmake Project Template
# ${PROJECT_SOURCE_DIR}/src/helper
# -------------------------

# Build library that can be used at higher level
add_library(renderloop STATIC)

target_include_directories(renderloop PRIVATE ${PROJECT_SOURCE_DIR}/ext/SDL2-2.30.2)
target_link_libraries(renderloop PRIVATE SDL2::SDL2-static)

target_sources(renderloop PRIVATE
    renderloop.cpp
    renderloop.hpp
)