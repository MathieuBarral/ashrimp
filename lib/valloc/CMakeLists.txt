file(GLOB lib_valloc_files "src/*.c")
add_library(valloc SHARED ${lib_valloc_files})
set_target_properties(valloc PROPERTIES LIBRARY_OUTPUT_DIRECTORY "bin")