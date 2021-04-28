cmake_minimum_required(VERSION 3.19)
project(boost_conan)

option(ENABLE_TESTS "Enable tests" False)

add_executable(${PROJECT_NAME} src/main.cpp)

set(PROJECT_OPTIONS
    -O3
    -Wpedantic
    -Wall
    -Wextra
    -Werror
    )

#set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
#message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
find_package(fmt REQUIRED)
#find_package(Boost COMPONENTS regex REQUIRED)

target_link_libraries(${PROJECT_NAME} pthread fmt::fmt)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})
target_include_directories(${PROJECT_NAME} PRIVATE include)

if (ENABLE_TESTS)
  message(STATUS, "Tests enabled")
  enable_testing() # Must be placed before add_subdirectory
  add_subdirectory(test)
endif ()
