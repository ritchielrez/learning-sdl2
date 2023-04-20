cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.24.15.tar.gz"
    SHA1 "8010d63d5ae611c564889d5fe12d3cb7a45703ac"
)

project(learning-sdl2 VERSION 1.0)

hunter_add_package(SDL2)
find_package(SDL2 CONFIG REQUIRED)

hunter_add_package(SDL_image)
find_package(SDL_image CONFIG REQUIRED)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(main ${SRC_FILES})

target_include_directories(main PRIVATE "include/")

target_link_libraries(main
    SDL_image::SDL_image
    SDL2::SDL2main
    SDL2::SDL2)
