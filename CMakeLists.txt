cmake_minimum_required(VERSION 3.25)

set(This MatrixAlgebraSystem)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE RELEASE)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(
    Headers
    src/DiagonalMatrix.hpp
    src/Matrix.hpp
    src/SquareMatrix.hpp
    src/LowerTriangularMatrix.hpp
    src/UpperTriangularMatrix.hpp
)

set(
    Sources
    src/DiagonalMatrix.cpp
    src/Matrix.cpp
    src/SquareMatrix.cpp
    src/LowerTriangularMatrix.cpp
    src/UpperTriangularMatrix.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(tests)
