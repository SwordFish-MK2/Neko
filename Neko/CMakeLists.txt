file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_definitions(-DNEKO_BUILD_DLL)

add_library(Neko SHARED ${srcs})

target_include_directories(Neko PUBLIC include)

target_link_libraries(Neko PUBLIC glfw)

target_link_libraries(Neko PUBLIC spdlog::spdlog spdlog::spdlog_header_only)