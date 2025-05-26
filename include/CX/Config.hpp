#ifndef CX_CONFIG_HPP
#define CX_CONFIG_HPP

#if __cplusplus < 202002L
#error "CX library requires the C++ standard to be atleast C++20."
#endif

#ifndef CX_SHADER_PATH
#define CX_SHADER_PATH "../shaders/"
#endif

#ifdef NDEBUG
#define CX_RELEASE
#else
#define CX_DEBUG
#endif

#define CX_VERSION_MAJOR 1
#define CX_VERSION_MINOR 0
#define CX_VERSION_PATCH 0

#define CX_VERSION 10000
#define CX_VERSION_STRING "1.0.0"

#if defined(_WIN32) || defined(_WIN64)
   #define CX_WINDOWS
#elif defined(__linux__)
   #define CX_LINUX
#elif defined(__APPLE__)
   #define CX_MACOS
#else
   #define CX_UNKNOWN_OS
#endif

#endif
