cmake_minimum_required(VERSION 3.25)
project(Game)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCE_CPP source/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_CPP})
set_target_properties(${PROJECT_NAME} PROPERTIES 
	CXX_STANDARD 17 
	CXX_STANDARD_REQUIRED ON 
    CXX_EXTENSIONS ON)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

target_compile_definitions(${PROJECT_NAME} PRIVATE WHITE_THEME)
# target_compile_definitions(${PROJECT_NAME} PRIVATE BLACK_THEME)

file(GLOB ASSETS_FILES assets/*)
file(COPY ${ASSETS_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
