#
# - configure_compiler_warnings
#
# This function configures compiler warnings for a given target. It supports MSVC, Clang and GCC compilers.
# Most of content of warnings were collected from
#
function(configure_compiler_warnings TARGET_NAME WARNINGS_AS_ERRORS MSVC_WARNINGS CLANG_WARNINGS GCC_WARNINGS)
  if(NOT MSVC_WARNINGS)
    set(MSVC_WARNINGS /W4 /w14242 /w14254 /w14263 /w14265 /w14287 /we4289
                      /w14296 /w14311 /w14545 /w14546 /w14547 /w14549 /w14555
                      /w14619 /w14640 /w14826 /w14905 /w14906 /w14928
                      /permissive- /bigobj)
  endif()

  if(NOT CLANG_WARNINGS)
    set(CLANG_WARNINGS -Wall -Wextra -Wshadow -Wnon-virtual-dtor
                       -Wold-style-cast -Wcast-align -Wunused
                       -Woverloaded-virtual -Wpedantic -Wconversion
                       -Wsign-conversion -Wnull-dereference -Wdouble-promotion
                       -Wformat=2 -Wimplicit-fallthrough)
  endif()

  if(NOT GCC_WARNINGS)
    set(GCC_WARNINGS ${CLANG_WARNINGS} -Wmisleading-indentation
                     -Wduplicated-cond -Wduplicated-branches -Wlogical-op
                     -Wuseless-cast -Wsuggest-override)
  endif()

  if(WARNINGS_AS_ERRORS)
    message(AUTHOR_WARNING "Warnings are configured as errors!!!")
    list(APPEND CLANG_WARNINGS -Werror)
    list(APPEND GCC_WARNINGS -Werror)
    list(APPEND MSVC_WARNINGS /WX)
  endif()

  if(MSVC)
    set(PROJECT_WARNINGS_CXX ${MSVC_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    set(PROJECT_WARNINGS_CXX ${CLANG_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(PROJECT_WARNINGS_CXX ${GCC_WARNINGS})
  else()
    message(AUTHOR_WARNING "No Warnings Configuration for Compiler ${CMAKE_CXX_COMPILER_ID}!!!")
  endif()

  target_compile_options(${TARGET_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${PROJECT_WARNINGS_CXX}>)
endfunction()