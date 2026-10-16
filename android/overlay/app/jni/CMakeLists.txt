cmake_minimum_required(VERSION 3.16)

project(mh2port CXX)

# Нативный код порта — в src/.
# SDL3 подключается из префаба, собранного шагом «Клон и сборка SDL3»
# (каталог передаётся через переменную окружения SDL3_DIR).
add_subdirectory(src)
