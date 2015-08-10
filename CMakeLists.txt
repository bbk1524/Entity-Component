cmake_minimum_required(VERSION 3.1)

project(Entity-Component)

set(Source_Files
	src/Component.h
	src/Component.cpp
	src/ComponentA.h
	src/ComponentA.cpp
	src/ComponentB.h
	src/ComponentB.cpp
	src/Entity.h
	src/Entity.cpp
	src/Source.cpp
)

source_group(Source_Files FILES ${Source_Files})

add_executable(${PROJECT_NAME}
	${Source_Files}
)

# Compile for C++ 14 with proper flags. CMake doesn't know that VS does this by default and whines
if(MSVC)
	# set warnings high, but suppress the one about unused parameters
	set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS " /W4 /wd4100")
else(MSVC)
	set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
	set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
    set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS " -Wall -Wextra -pedantic -Wno-unused-parameter")
endif(MSVC)

# Tell VS where to build the executable for both debug and release versions
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin")
