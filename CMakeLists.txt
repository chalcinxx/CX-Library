cmake_minimum_required(VERSION 3.10)
project(cx_lib VERSION 1.6.0 LANGUAGES CXX)

# Set C++ standard.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
   set(CMAKE_CXX_COMPILER "clang++")
   set(CMAKE_C_COMPILER "clang")
endif()

# Include the directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
add_library(cx STATIC
   src/Plane.cpp
   src/Rect.cpp
   src/Sprite.cpp
   src/Text.cpp
   src/Button.cpp
   src/Bar.cpp
   src/TextInput.cpp
   src/Slider.cpp
   src/UIElement.cpp
   src/ParticleManager.cpp
   src/AssetManager.cpp
   src/EventHandler.cpp
   src/AudioManager.cpp
   src/NavigationManager.cpp
   src/Camera.cpp)

# Specify where the installed libraries should go
install(TARGETS cx
   ARCHIVE DESTINATION lib
   LIBRARY DESTINATION lib
   RUNTIME DESTINATION bin)

# Install the header files and shaders
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/shaders/ DESTINATION share/cx/shaders)
add_definitions(-DCX_SHADER_PATH="${CMAKE_INSTALL_PREFIX}/share/cx/shaders/")

# Export the package to let other projects find and use the library
export(PACKAGE cx_lib)

include(CMakePackageConfigHelpers)

# Set up a configuration file so other projects can use it using `find_package()`
configure_package_config_file(
   ${CMAKE_CURRENT_SOURCE_DIR}/cxConfig.cmake.in
   ${CMAKE_CURRENT_BINARY_DIR}/cxConfig.cmake
   INSTALL_DESTINATION lib/cmake/cx)

# Specify the version to check compatibility
write_basic_package_version_file(
   ${CMAKE_CURRENT_BINARY_DIR}/cxConfigVersion.cmake
   VERSION ${PROJECT_VERSION}
   COMPATIBILITY SameMajorVersion)

# Install the config files to provide information about the library
install(FILES
   ${CMAKE_CURRENT_BINARY_DIR}/cxConfig.cmake
   ${CMAKE_CURRENT_BINARY_DIR}/cxConfigVersion.cmake
   DESTINATION lib/cmake/cx)
