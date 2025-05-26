cmake_minimum_required(VERSION 3.10)
project(release)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_C_COMPILER "clang")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/../src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/../include)

add_executable(${PROJECT_NAME} ${SOURCES} ${PROJECT_SOURCE_DIR}/project/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(${PROJECT_NAME} sqlite3 sfml-graphics sfml-window sfml-system sfml-audio)
