file(GLOB lib_gc_files "src/*.c")
add_library(gc SHARED ${lib_gc_files})
target_link_libraries(gc valloc)
set_target_properties(gc PROPERTIES LIBRARY_OUTPUT_DIRECTORY "bin")