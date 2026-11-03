cmake_minimum_required(VERSION 3.20)
project(ParticleSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
    )
    FetchContent_MakeAvailable(raylib)
endif()

add_executable(ParticleSystem
    Particlesystem/main.cpp
    Particlesystem/Particl.cpp
    Particlesystem/ParticleSystem.cpp
)
target_include_directories(ParticleSystem PRIVATE Particlesystem)
target_link_libraries(ParticleSystem PRIVATE raylib)
