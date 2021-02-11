cmake_minimum_required(VERSION 3.0.0)

project(LinearSystemSolver)

find_package(Eigen3)
if (EIGEN3_FOUND)
    include_directories(${EIGEN3_INCLUDE_DIRS})
endif(EIGEN3_FOUND)

add_subdirectory(src)

add_executable(main main.cpp)

target_link_libraries(main utils)
target_link_libraries(main ${EIGEN3_LIBRARIES}) # todo: bad workaround. create a separate var with libs to link



