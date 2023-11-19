cmake_minimum_required(VERSION 3.5)

project(03.homework CXX)

add_executable(
    03.homework
    main.cpp
	random_value
	random_value.cpp
	high_scores
	high_scores.cpp
    H.h )

  set_target_properties(03.homework PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON)

 if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${target_name} PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()
