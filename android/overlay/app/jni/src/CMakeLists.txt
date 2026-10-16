cmake_minimum_required(VERSION 3.16)

find_package(SDL3 CONFIG REQUIRED)

# librw (статическая библиотека + заголовки) — из CI.
# Пути передаёт gradle через cmake-аргументы (см. app/build.gradle):
#   LIBRW_ROOT — каталог клона librw (в нём лежит rw.h)
#   LIBRW_LIB  — путь к librw.a (собран с LIBRW_PLATFORM=GL3, LIBRW_GL3_GFXLIB=SDL3)
if(NOT DEFINED LIBRW_ROOT OR NOT DEFINED LIBRW_LIB)
    message(FATAL_ERROR "LIBRW_ROOT/LIBRW_LIB не переданы (см. внешние cmake-аргументы в build.gradle)")
endif()
message(STATUS "LIBRW_ROOT=${LIBRW_ROOT}")
message(STATUS "LIBRW_LIB=${LIBRW_LIB}")

add_library(main SHARED main.cpp)
set_target_properties(main PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

# Те же публичные define, что librw выставляет своим потребителям в собственной
# сборке (librw/src/CMakeLists.txt: PUBLIC "RW_${LIBRW_PLATFORM}" и PUBLIC LIBRW_SDL3).
# Нам они нужны, потому что линкуем готовый .a, а не цель CMake.
target_compile_definitions(main PRIVATE RW_GL3 LIBRW_SDL3)

target_include_directories(main PRIVATE "${LIBRW_ROOT}")

target_link_libraries(main
    PRIVATE
        ${LIBRW_LIB}
        SDL3::SDL3
        GLESv3
        EGL
        log
)
