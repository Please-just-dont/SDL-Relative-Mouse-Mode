cmake_minimum_required(VERSION 3.22)



project(my_project
VERSION 1.0
  LANGUAGES CXX C
)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_EXTENSIONS OFF)



message("CMAKE DEFAULT CMAKE_C_FLAGS_DEBUG is ${CMAKE_C_FLAGS_DEBUG}")
message("CMAKE DEFAULT CMAKE_C_FLAGS_RELEASE is ${CMAKE_C_FLAGS_RELEASE}")
message("CMAKE DEFAULT CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE DEFAULT CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")




if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("Using GCC compiler")
    
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("Using Clang compiler")
    
else ()
    message("Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
endif ()




set(MAIN_SOURCES 
${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(main ${MAIN_SOURCES})


set(SDL_STATIC TRUE CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SDL)

target_link_libraries(main PUBLIC SDL3::SDL3-static)


