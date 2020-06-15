cmake_minimum_required(VERSION 3.15)
project(Lab8)

set(CMAKE_CXX_STANDARD 17)

set(SFML_PATH /usr/local/Cellar/sfml/2.5.1)

set(SFML_INCLUDE DIR "${SFML_PATH}/include")

set(SFML_LIBRARY_DIR "${SFML_PATH}/lib")

#set(SOIL_PATH /usr/local/lib/libSOIL.a)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework GLUT -framework OpenGL") # compiler version and compiler flags.

add_executable(Lab8 main.cpp controller/CubeController.cpp controller/CubeController.h model/Cube.cpp model/Cube.h service/CubeSolver.cpp service/CubeSolver.h service/CubeService.cpp service/CubeService.h view/CubeView.cpp view/CubeView.h model/SmallCube.cpp model/SmallCube.h model/Colors.h model/Side.h model/Colors.cpp)

target_link_libraries (Lab8 sfml-graphics sfml-window sfml-system)
