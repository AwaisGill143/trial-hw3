#include "../src/MatrixAlgebraSystem.hpp"
#include "common.cpp"

class DefaultMatrix : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:

    Matrix* matrix;

    void SetUp() override { matrix = nullptr; }

    void TearDown() override {
        if (matrix != nullptr) {
            delete matrix;
        }
    }
};

INSTANTIATE_TEST_CASE_P(, DefaultMatrix, double_shapes);

#define TEST_CONSTRUCTOR(matrix_type)                                  \
    TEST_P(DefaultMatrix, matrix_type##Constructor) {                  \
        const auto [rows, cols] = GetParam();                          \
        matrix                  = get_matrix<matrix_type>(rows, cols); \
        if constexpr (std::is_same_v<matrix_type, Matrix>) {           \
            ASSERT_EQ(matrix->getCols(), cols);                        \
            ASSERT_EQ(matrix->getRows(), rows);                        \
        } else {                                                       \
            ASSERT_EQ(matrix->getCols(), rows);                        \
            ASSERT_EQ(matrix->getRows(), rows);                        \
        }                                                              \
    }

#define TEST_GET_ELEMENT(matrix_type)                            \
    TEST_P(DefaultMatrix, matrix_type##GetElement) {             \
        auto [rows, cols] = GetParam();                          \
        matrix            = get_matrix<matrix_type>(rows, cols); \
        if constexpr (!std::is_same_v<matrix_type, Matrix>) {    \
            cols = rows;                                         \
        }                                                        \
        for (int i = 0; i < rows; ++i) {                         \
            for (int j = 0; j < cols; ++j) {                     \
                ASSERT_DOUBLE_EQ(matrix->getElement(i, j), 0);   \
            }                                                    \
        }                                                        \
    }

#define TEST_SET_ELEMENT(matrix_type)                                  \
    TEST_P(DefaultMatrix, matrix_type##SetElement) {                   \
        auto [rows, cols] = GetParam();                                \
        matrix            = get_matrix<matrix_type>(rows, cols);       \
        if constexpr (!std::is_same_v<matrix_type, Matrix>) {          \
            cols = rows;                                               \
        }                                                              \
        for (int i = 0; i < rows; ++i) {                               \
            for (int j = 0; j < cols; ++j) {                           \
                matrix->setElement(i, j, i + j);                       \
                if (valid_index<matrix_type>(i, j)) {                  \
                    ASSERT_DOUBLE_EQ(matrix->getElement(i, j), i + j); \
                }                                                      \
            }                                                          \
        }                                                              \
    }

#define TEST_DESIRED_ELEMENTS_SIZE(matrix_type)                                                   \
    TEST_P(DefaultMatrix, matrix_type##DesiredElementsSize) {                                     \
        const auto [rows, cols] = GetParam();                                                     \
        matrix                  = get_matrix<matrix_type>(rows, cols);                            \
        int       n             = matrix->getElementsSize();                                      \
        const int size = expected_vector_size<matrix_type>(matrix->getRows(), matrix->getCols()); \
        ASSERT_EQ(n, size);                                                                       \
    }

TEST_CONSTRUCTOR(DiagonalMatrix);
TEST_CONSTRUCTOR(LowerTriangularMatrix);
TEST_CONSTRUCTOR(Matrix);
TEST_CONSTRUCTOR(SquareMatrix);
TEST_CONSTRUCTOR(UpperTriangularMatrix);

TEST_GET_ELEMENT(DiagonalMatrix);
TEST_GET_ELEMENT(LowerTriangularMatrix);
TEST_GET_ELEMENT(Matrix);
TEST_GET_ELEMENT(SquareMatrix);
TEST_GET_ELEMENT(UpperTriangularMatrix);

TEST_SET_ELEMENT(DiagonalMatrix);
TEST_SET_ELEMENT(LowerTriangularMatrix);
TEST_SET_ELEMENT(Matrix);
TEST_SET_ELEMENT(SquareMatrix);
TEST_SET_ELEMENT(UpperTriangularMatrix);

TEST_DESIRED_ELEMENTS_SIZE(DiagonalMatrix);
TEST_DESIRED_ELEMENTS_SIZE(LowerTriangularMatrix);
TEST_DESIRED_ELEMENTS_SIZE(Matrix);
TEST_DESIRED_ELEMENTS_SIZE(SquareMatrix);
TEST_DESIRED_ELEMENTS_SIZE(UpperTriangularMatrix);
