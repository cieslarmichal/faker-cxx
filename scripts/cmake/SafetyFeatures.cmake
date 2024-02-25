# https://github.com/trcrsired/Portable-Cpp-Guideline?tab=readme-ov-file#memory-safety
function(turn_on_warnings TARGET_NAME)
    target_compile_options(
        ${TARGET_NAME}
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wmisleading-indentation
            -Wunused
            -Wuninitialized
            -Wshadow
            # -Wconversion
    )
endfunction()