cmake_minimum_required(VERSION 3.8)
project(Spark)

set(SOURCE 
    src/Main.cpp
    src/Core/Display/Color.cpp
    src/Core/Renderer/IndexBuffer.cpp
    src/Core/Renderer/VertexBuffer.cpp
    src/Core/Renderer/VertexArray.cpp
    src/Core/Renderer/Renderer.cpp
    src/Core/Utilities/Shader.cpp
    src/Core/Utilities/OpenGLError.cpp
    src/gl.c
)

add_executable(${PROJECT_NAME} ${SOURCE})

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

add_subdirectory(external/glfw)

add_compile_options(-g)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE external/glfw/include)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)