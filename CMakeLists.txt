cmake_minimum_required(VERSION 3.14)
project(AssetLoader
    VERSION 0.1.0
    LANGUAGES CXX
)

include(FetchContent)

add_subdirectory(source)

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    include(CTest)
    add_subdirectory(test)
endif()
