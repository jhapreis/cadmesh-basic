# Sets compile_commands.json; for SonarLint extension
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(basic)

set(CMAKE_BUILD_TYPE Debug)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

file(COPY geometries/ DESTINATION geometries/)
file(COPY macros/ DESTINATION macros/)

add_executable(basic main.cc basic.cc basic.hh CADMesh.hh)
target_link_libraries(basic ${Geant4_LIBRARIES})
