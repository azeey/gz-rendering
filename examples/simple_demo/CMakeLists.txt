cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
project(gz-rendering-simple-demo)

find_package(gz-rendering)

find_package(glfw3 REQUIRED)
include_directories(SYSTEM ${GLFW3_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(SYSTEM ${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})

if (NOT APPLE)
  find_package(GLEW REQUIRED)
  include_directories(SYSTEM ${GLEW_INCLUDE_DIRS})
  link_directories(${GLEW_LIBRARY_DIRS})
endif()

if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
endif()

add_executable(simple_demo Main.cc GlfwWindow.cc)

target_link_libraries(simple_demo
  glfw
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
  ${GZ-RENDERING_LIBRARIES}
  )
