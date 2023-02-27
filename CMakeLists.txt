# Cmake.txt顶层项目文件
cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

project(Neko_engine)

find_package(glfw3 CONFIG REQUIRED)

find_package(spdlog CONFIG REQUIRED)

find_path(SCOTTT_DEBUGBREAK_INCLUDE_DIRS "debugbreak.h")

# systems
if(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    add_definitions(-DNEKO_PLATFORM_LINUX)
elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-DNEKO_pLATFORM_WINDOWS)
else()
    message("Unsupported system")
endif()

add_subdirectory(Neko)
add_subdirectory(Sandbox)
