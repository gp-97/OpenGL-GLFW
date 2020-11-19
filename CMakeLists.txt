cmake_minimum_required(VERSION 3.16)
project(OpenGL-GLFW C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)

list(APPEND EXTRA_LIBS "-lglut -lGLU -lGL -lX11")

add_executable(OpenGL-GLFW src/main.cpp)
target_link_libraries(OpenGL-GLFW glfw ${EXTRA_LIBS})
