cmake_minimum_required(VERSION 3.25)

set(ThisDefault DefaultTests)
set(ThisOperations OperationsTests)
set(ThisDiagonalMatrix DiagonalMatrixTests)
set(ThisMatrix MatrixTests)
set(ThisSquareMatrix SquareMatrixTests)
set(CMAKE_BUILD_TYPE Release)

add_executable(${ThisDefault} testDefaults.cpp)
add_executable(${ThisOperations} testOperations.cpp)



target_link_libraries(
    ${ThisDefault} PUBLIC
    gtest
    gtest_main
    MatrixAlgebraSystem
)

target_link_libraries(
    ${ThisOperations} PUBLIC
    gtest
    gtest_main
    MatrixAlgebraSystem
)

add_test(
    NAME ${ThisDefault}
    COMMAND ${ThisDefault}
)
add_test(
    NAME ${ThisOperations}
    COMMAND ${ThisOperations}
)
