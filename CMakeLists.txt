cmake_minimum_required(VERSION 3.28)
project(LightYears LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(LightYears 
    src/main.cpp
    include/framework/Application.h
    src/framework/Application.cpp
)

target_compile_features(LightYears PRIVATE cxx_std_17)
target_link_libraries(LightYears PRIVATE SFML::Graphics)
target_include_directories(LightYears PUBLIC include)