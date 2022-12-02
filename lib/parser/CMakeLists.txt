file(GLOB lib_parser_files "src/*.c")
add_library(parser SHARED ${lib_parser_files})
target_link_libraries(parser utils)
set_target_properties(parser PROPERTIES LIBRARY_OUTPUT_DIRECTORY "bin")