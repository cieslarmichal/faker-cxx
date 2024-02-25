find_program(CLANG_FORMAT_PATH clang-format REQUIRED)
file(GLOB_RECURSE ALL_SOURCE_FILES "src/*.cpp" "src/*.h")
add_custom_target(
    clang_format
    COMMAND ${CLANG_FORMAT_PATH} 
        ${ALL_SOURCE_FILES}
        -i
        --style=file:${CMAKE_CURRENT_SOURCE_DIR}/scripts/.clang-format
    COMMENT "Running clang-format"
)
set_target_properties(clang_format PROPERTIES EXCLUDE_FROM_ALL TRUE)