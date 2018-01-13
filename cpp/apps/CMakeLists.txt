add_executable(demo demo.cpp)
#target_include_directories(demo PUBLIC stl_util structures statistics)
target_link_libraries(demo stl_util structures statistics)
#add_dependencies(demo stl_util structures statistics)