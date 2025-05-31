# CX

### Sections
- [What is CX?](#what-is-cx)
- [How to build the library](#how-to-build-the-library)
- [How to include the library in your projects](#how-to-include-the-library-in-your-projects)
- [Dependencies](#dependencies)
- [Contributors](#contributors)
- [Links](#links)

### What is CX?
CX is an UI/Utility library for SFML-based applications. It is primarily made for 2D projects - games and desktop applications. It integrates well with SFML and makes creating projects easier, faster and more comfortable. It includes utility classes like grid, asset manager, audio manager and many more and UI elements like buttons, sliders, bars and so on, which can be easily included in an already existing SFML project. [Astral Surge](https://www.youtube.com/playlist?list=PLAYMpoWModGMjiDWBN77FPqGxotpOnEH2) is a 2D game made with the CX library ([Candle](https://github.com/MiguelMJ/Candle) is used for the dynamic lighting).
### How to build the library:

### Linux:
1. Locate the build directory `cx_ui_library/build/`:
```bash
cd build
```
2. Build the library:
```bash
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
make
```
3. Install the library on your machine:
```bash
sudo make install
```

### How to include the library in your projects:

### Linux:
You'll also have to link SFML in your project for CX to work, you can download it [here](https://www.sfml-dev.org/download/) or using your package manager. The best SFML version for CX is SFML 2.6.
1. Set the C++ standard to 20 or above
```cmake
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
```
2. Link the CX library:
```cmake
find_package(cx REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${cx_LIBRARIES})
```
3. Link the SFML library:

First download SFML, we'll use libsfml-dev in this example:
```bash
sudo apt install libsfml-dev
```
Then include it in your CMakeLists.txt file:
```cmake
find_package(cx REQUIRED)
find_package(SFML 2.6 COMPONENTS window system graphics audio REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-system sfml-graphics sfml-audio ${cx_LIBRARIES})
```

Full example:
```cmake
# Set the CMake minimum version
cmake_minimum_required(VERSION 3.10)

# Create a new project
project(myProject VERSION 1.0)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# Link both SFML and CX
find_package(cx REQUIRED)
find_package(SFML 2.6 COMPONENTS window system graphics audio REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-system sfml-graphics sfml-audio ${cx_LIBRARIES})
```
Actively working on getting this library on other platforms.

### Dependencies
This library uses SFML [(Official SFML website)](https://www.sfml-dev.org/) for most of the features, which is licensed under zlib/png license.

### Contributors
Chalcinxx. [(Youtube)](https://www.youtube.com/@chalcinxx), [(Github)](https://github.com/chalcinxx)

### Links
- [Official SFML website](https://www.sfml-dev.org/)
- [Download SFML](https://www.sfml-dev.org/download/)
- [Astral Surge Youtube playlist](https://www.youtube.com/playlist?list=PLAYMpoWModGMjiDWBN77FPqGxotpOnEH2)
- [Candle (lighting library for SFML, used in Astral Surge)](https://github.com/MiguelMJ/Candle)
