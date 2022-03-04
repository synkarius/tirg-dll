cmake_minimum_required (VERSION 3.20)

project (tirg)
set(TIRG_VERSION 1.0.0)
set(MYAPP_NAME "tirg")

# Use static linking of MSVC runtime libraries, both in debug and release
# See https://cmake.org/cmake/help/git-stage/variable/CMAKE_MSVC_RUNTIME_LIBRARY.html#variable:CMAKE_MSVC_RUNTIME_LIBRARY
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
add_subdirectory("source")