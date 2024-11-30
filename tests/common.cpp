#ifndef __COMMON
#define __COMMON

#include <gtest/gtest.h>

#include <type_traits>

#include "../src/MatrixAlgebraSystem.hpp"

const auto single_shapes = ::testing::Values(3, 1, 4, 5, 9, 10, 19, 20);

const auto double_shapes = ::testing::Values(
    std::make_tuple(5, 6), std::make_tuple(7, 2), std::make_tuple(2, 3), std::make_tuple(3, 7),
    std::make_tuple(6, 3), std::make_tuple(9, 4), std::make_tuple(4, 10));

const auto triple_shapes = ::testing::Values(
    std::make_tuple(10, 1, 1), std::make_tuple(1, 2, 2), std::make_tuple(2, 100, 100),
    std::make_tuple(4, 7, 7), std::make_tuple(20, 3, 3), std::make_tuple(3, 2, 2),
    std::make_tuple(10, 8, 10), std::make_tuple(10, 1, 2), std::make_tuple(100, 2, 100));

// https://stackoverflow.com/a/64884440/26167473
template <typename T>
bool valid_index(const int i, const int j) {
    const bool valid = i >= 0 && j >= 0;
    if (!valid) {
        return false;
    }
    if constexpr (std::is_same_v<T, DiagonalMatrix>) {
        return i == j && valid;
    }
    if constexpr (std::is_same_v<T, LowerTriangularMatrix>) {
        return i >= j && valid;
    }
    if constexpr (std::is_same_v<T, UpperTriangularMatrix>) {
        return i <= j && valid;
    }
    return valid;
}

template <typename T>
T* get_matrix(const int rows, const int cols) {
    if constexpr (std::is_same_v<T, Matrix>) {
        return new T(rows, cols);
    } else {
        return new T(rows);
    }
}

inline int Matrix::getElementsSize() const { return this->elements.size(); }

template <typename T>
int expected_vector_size(const int rows, const int cols) {
    if (rows == 0 || cols == 0) {
        return 0;
    }
    if constexpr (std::is_same_v<T, Matrix>) {
        return rows * cols;
    }
    if constexpr (std::is_same_v<T, SquareMatrix>) {
        return rows * cols;
    }
    if constexpr (std::is_same_v<T, DiagonalMatrix>) {
        return rows;
    }
    if constexpr (std::is_same_v<T, LowerTriangularMatrix>) {
        return (rows * (rows + 1)) / 2;
    }
    if constexpr (std::is_same_v<T, UpperTriangularMatrix>) {
        return (rows * (rows + 1)) / 2;
    }
    return 0;
}

#endif  // __COMMON
