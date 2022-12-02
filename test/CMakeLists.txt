set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

include(test/CodeCoverage.cmake)

enable_testing()

add_test(NAME Normal_Exec COMMAND "ashrimp" "../test/test.ash")
add_test(NAME Non_Existant_File COMMAND "ashrimp" "truc.ash")
add_test(NAME Non_File_Type COMMAND "ashrimp" "/")
add_test(NAME No_Extension_File COMMAND "ashrimp" "../test/test")
add_test(NAME Wrong_Extension_File COMMAND "ashrimp" "../test/test.a")
add_test(NAME Wrong_Name_File COMMAND "ashrimp" "../test/t3st.ash")
add_test(NAME Out_File_Normal_Exec COMMAND "ashrimp" "-o" "test.ashrimp" "../test/test.ash")
add_test(NAME Out_File_Wrong_Extension COMMAND "ashrimp" "-o" "test.a" "../test/test.ash")
add_test(NAME Out_File_Wrong_Name COMMAND "ashrimp" "-o" "t3st.ashrimp" "../test/test.ash")
add_test(NAME Out_File_No_Extension COMMAND "ashrimp" "-o" "test" "../test/test.ash")
add_test(NAME Out_File_No_File_Type COMMAND "ashrimp" "-o" "/" "../test/test.ash")

set_tests_properties(Non_Existant_File
                     Non_File_Type
                     No_Extension_File
                     Wrong_Extension_File
                     Wrong_Name_File
                     Out_File_Wrong_Extension
                     Out_File_Wrong_Name
                     Out_File_No_Extension
                     Out_File_No_File_Type
                     PROPERTIES WILL_FAIL TRUE)

setup_target_for_coverage_gcovr_html(NAME coverage EXECUTABLE ctest)
