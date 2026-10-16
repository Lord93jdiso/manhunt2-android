cmake_minimum_required(VERSION 3.16)

# SDL3: префаб из CI (SDL3_DIR = каталог с SDL3Config.cmake)
find_package(SDL3 CONFIG REQUIRED)

add_library(main SHARED main.cpp)

target_link_libraries(main
    PRIVATE
        SDL3::SDL3
        GLESv3
)
