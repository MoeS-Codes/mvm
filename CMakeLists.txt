cmake_minimum_required(VERSION 3.28)
project(mvm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)             # use C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON)    # fail instead of silently using an older standard
set(CMAKE_CXX_EXTENSIONS OFF)          # -std=c++23, not -std=gnu++23 (no GCC-only extensions)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # helps VS Code understand your code

add_executable(mvm src/main.cpp)
target_compile_options(mvm PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Werror)

if(MINGW)
    # MinGW keeps std::print's Windows console support in a separate library
    target_link_libraries(mvm PRIVATE stdc++exp)
    # Build the C++ runtime into mvm.exe so Windows can't load a mismatched DLL
    target_link_options(mvm PRIVATE -static)
endif()
