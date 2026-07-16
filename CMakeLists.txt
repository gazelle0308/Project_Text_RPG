cmake_minimum_required(VERSION 3.20)

project(Project_Text_RPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/text-rpg-challenge/Step_1_challenge/**/*.cpp",
    "${CMAKE_CURRENT_SOURCE_DIR}/text-rpg-challenge/Step_1_challenge/*.cpp"
)

add_executable(Project_Text_RPG ${SOURCES})

target_include_directories(Project_Text_RPG PRIVATE
    text-rpg-challenge/Step_1_challenge/Include
)