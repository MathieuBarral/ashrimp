file(GLOB src_files "*.c")
add_executable(ashrimp ${src_files})
target_link_libraries(ashrimp parser utils gc valloc)
set_target_properties(ashrimp PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")