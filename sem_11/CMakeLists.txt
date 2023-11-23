cmake_minimum_required(VERSION 3.25)  # Версия CMAKE

set(CMAKE_CXX_STANDARD 17)            # Стандарт C++
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sem_11)                       # Название нашего проекат

# Создаём переменную source, в которой лежат наши файлы
# Они лежат в src/main, а не просто в src, так как иногда добавляют src/test
file(GLOB_RECURSE sources   src/main/*.cpp src/main/*.h)

# После сборки в папке build будет лежать файл sem_11_exec
# (для Windows будет создан sem_11_exec.exe)
add_executable(sem_11_exec ${CMAKE_SOURCE_DIR} ${sources})

target_compile_options(sem_11_exec PUBLIC -std=c++17 -Wall -Wextra)

# Без этого можно обойтись, но в VS Code это проще использовать "из коробки"
include(CTest)
enable_testing()