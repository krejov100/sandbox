get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${TARGET} INTERFACE)
target_sources(${TARGET} INTERFACE  
	${CMAKE_CURRENT_SOURCE_DIR}/gaussian.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/histogram.hpp
)
target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})