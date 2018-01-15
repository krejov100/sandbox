add_executable(sandbox_tests tests.cpp)
#target_include_directories(demo PUBLIC stl_util structures statistics)
target_link_libraries(sandbox_tests stl_util structures statistics)
#add_dependencies(demo stl_util structures statistics)

add_test(NAME sandbox_tests COMMAND sandbox_tests)