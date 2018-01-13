get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${TARGET} INTERFACE)
target_sources(${TARGET} INTERFACE  
	${CMAKE_CURRENT_SOURCE_DIR}/stl_typedefs.hpp 
	${CMAKE_CURRENT_SOURCE_DIR}/string_util.hpp 
	${CMAKE_CURRENT_SOURCE_DIR}/vector_util.hpp
)
target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
source_group(${TARGET} FILES "C:/Code/sandbox/cpp/src/stl_util/stl_typedefs.hpp" )