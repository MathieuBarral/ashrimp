file(GLOB lib_utils_files "src/*.c")
add_library(utils SHARED ${lib_utils_files})
target_link_libraries(utils gc)
set_target_properties(utils PROPERTIES LIBRARY_OUTPUT_DIRECTORY "bin")