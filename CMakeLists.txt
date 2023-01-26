cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

# Change it to your sepcific folder where you've installed vcpkg 
set(VCPKG_ROOT_FOLDER C:/Dev/vcpkg)
# Change it to your specific triplet that you're using
set(VCPKG_TRIPLET x64-mingw-dynamic)

project(learning-sdl2 VERSION 1.0)

include_directories(include/)

include_directories(${VCPKG_ROOT_FOLDER}/installed/${VCPKG_TRIPLET}/include/)
link_directories(${VCPKG_ROOT_FOLDER}/installed/${VCPKG_TRIPLET}/lib)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(main ${SRC_FILES})

target_compile_options(main PRIVATE -g -Wall -m64)

target_link_libraries(main PRIVATE mingw32)
target_link_libraries(main PRIVATE SDL2main SDL2)
target_link_libraries(main PRIVATE SDL2_image)