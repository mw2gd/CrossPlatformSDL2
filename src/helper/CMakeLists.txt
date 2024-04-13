# -------------------------
# Cmake Project Template
# ${PROJECT_SOURCE_DIR}/src/helper
# -------------------------

# Build library that can be used at higher level
add_library(helper STATIC)

target_sources(helper PRIVATE
    helper.c
    helper.h
)