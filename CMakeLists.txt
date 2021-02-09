cmake_minimum_required(VERSION 3.0.0)

project(LinearSystemSolver)

add_executable(main main.cpp)

find_package(Eigen3)
if (EIGEN3_FOUND)
    include_directories(${EIGEN3_INCLUDE_DIRS})
    target_link_libraries(main ${EIGEN3_LIBRARIES})
endif(EIGEN3_FOUND)