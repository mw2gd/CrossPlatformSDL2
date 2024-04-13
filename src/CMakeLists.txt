# -------------------------
# Cmake Project Template
# ${PROJECT_SOURCE_DIR}/src
# -------------------------

# Define primary deliverable for this project
add_executable(app
    main.cpp
)

install(TARGETS app DESTINATION ${PROJECT_SOURCE_DIR}/out/bin)

if(EMSCRIPTEN)
    install(FILES
        "$<TARGET_FILE_DIR:app>/app.js"
        "$<TARGET_FILE_DIR:app>/app.wasm"
        DESTINATION ${PROJECT_SOURCE_DIR}/out/bin)
endif()

# Add subdirectories with build output that gets used
# this deliverable
add_subdirectory(${PROJECT_SOURCE_DIR}/src/renderloop)
add_subdirectory(${PROJECT_SOURCE_DIR}/ext/SDL2-2.30.2 ${PROJECT_SOURCE_DIR}/ext/SDL2-2.30.2/build)

# include any headers with target_include_directories!
target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/src/renderloop)
target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/ext/SDL2-2.30.2)

# link object files to executable with target_link_libraries!
target_link_libraries(app PRIVATE renderloop)
target_link_libraries(app PRIVATE SDL2::SDL2-static)