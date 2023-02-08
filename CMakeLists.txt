# Cmake.txt顶层项目文件
cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

project(Neko_engine)

find_package(glfw3 CONFIG REQUIRED)

find_package(spdlog CONFIG REQUIRED)

add_definitions(-DNEKO_BUILD_DLL)
add_definitions(-DNEKO_PLATFORM_LINUX)

add_subdirectory(Neko)
add_subdirectory(Sandbox)
