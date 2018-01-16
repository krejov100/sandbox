get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${TARGET} INTERFACE)
target_sources(${TARGET} INTERFACE  
	${CMAKE_CURRENT_SOURCE_DIR}/range.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/tree.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/quad_tree.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/structures.hpp
)
target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})