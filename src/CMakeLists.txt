# -------------------------
# Cmake Project Template
# ${PROJECT_SOURCE_DIR}/src
# -------------------------

# Define primary deliverable for this project
add_executable(app
    main.c
)

install(TARGETS app DESTINATION ${PROJECT_SOURCE_DIR}/bin)

if(EMSCRIPTEN)
    install(FILES
        "$<TARGET_FILE_DIR:app>/app.js"
        "$<TARGET_FILE_DIR:app>/app.wasm"
        DESTINATION ${PROJECT_SOURCE_DIR}/bin)
endif()

# Add subdirectories with build output that gets used
# this deliverable
add_subdirectory(helper)

# include any headers with target_include_directories!
target_include_directories(app PRIVATE helper)

# link object files to executable with target_link_libraries!
target_link_libraries(app PRIVATE helper)