cmake_minimum_required(VERSION 3.1)

# Call after a set command with a list of files: set(Source_Files value1 [value ...])
# Place the argument in double quotes: create_files_if_needed("${Source_Files}")
# To make the cmake step faster, erase the function call after it's done its work
FUNCTION(create_files_if_needed list_of_files)
	FOREACH(word ${list_of_files})
		IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${word})
			MESSAGE("----- creating: ${word} -----")
			FILE(WRITE ${word} "")
		ENDIF()	
	ENDFOREACH()
ENDFUNCTION()

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
	src/tmp.txt
)

create_files_if_needed("${Source_Files}")

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
