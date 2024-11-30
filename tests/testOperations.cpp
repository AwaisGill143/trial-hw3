#include "../src/MatrixAlgebraSystem.hpp"
#include "common.cpp"

class SameShapeOperations : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:

    Matrix *matrix1, *matrix2, *matrix3;

    void SetUp() override {
        matrix1 = nullptr;
        matrix2 = nullptr;
        matrix3 = nullptr;
    }

    void TearDown() override {
        if (matrix1 != nullptr) {
            delete matrix1;
        }
        if (matrix2 != nullptr) {
            delete matrix2;
        }
        if (matrix3 != nullptr) {
            delete matrix3;
        }
    }
};

INSTANTIATE_TEST_CASE_P(, SameShapeOperations, double_shapes);

#define TEST_ADDITION(matrix_type1, matrix_type2)                                             \
    TEST_P(SameShapeOperations, matrix_type1##Add##matrix_type2) {                            \
        const auto [rows, cols]         = GetParam();                                         \
        matrix1                         = get_matrix<matrix_type1>(rows, cols);               \
        matrix2                         = get_matrix<matrix_type2>(rows, cols);               \
        constexpr bool first_is_matrix  = std::is_same_v<matrix_type1, Matrix>;               \
        constexpr bool second_is_matrix = std::is_same_v<matrix_type2, Matrix>;               \
        constexpr bool is_same          = std::is_same_v<matrix_type1, matrix_type2>;         \
        for (int j = 0; j < (first_is_matrix ? cols : rows); ++j) {                           \
            for (int i = 0; i < rows; ++i) {                                                  \
                matrix1->setElement(i, j, i + j);                                             \
            }                                                                                 \
        }                                                                                     \
        for (int j = 0; j < (second_is_matrix ? cols : rows); ++j) {                          \
            for (int i = 0; i < rows; ++i) {                                                  \
                matrix2->setElement(i, j, i - j);                                             \
            }                                                                                 \
        }                                                                                     \
        if (is_same) {                                                                        \
            const matrix_type1 result_12 = *(matrix_type1*)matrix1 + *(matrix_type1*)matrix2; \
            const matrix_type1 result_21 = *(matrix_type1*)matrix2 + *(matrix_type1*)matrix1; \
            ASSERT_TRUE(result_12 == result_21);                                              \
        } else {                                                                              \
            const Matrix result_12 = *matrix1 + *matrix2;                                     \
            const Matrix result_21 = *matrix2 + *matrix1;                                     \
            ASSERT_TRUE(result_12 == result_21);                                              \
        }                                                                                     \
    }

TEST_ADDITION(DiagonalMatrix, DiagonalMatrix);
TEST_ADDITION(DiagonalMatrix, LowerTriangularMatrix);
TEST_ADDITION(DiagonalMatrix, SquareMatrix);
TEST_ADDITION(DiagonalMatrix, UpperTriangularMatrix);
TEST_ADDITION(LowerTriangularMatrix, LowerTriangularMatrix);
TEST_ADDITION(LowerTriangularMatrix, SquareMatrix);
TEST_ADDITION(LowerTriangularMatrix, UpperTriangularMatrix);
TEST_ADDITION(Matrix, Matrix);
TEST_ADDITION(SquareMatrix, DiagonalMatrix);
TEST_ADDITION(SquareMatrix, SquareMatrix);
TEST_ADDITION(SquareMatrix, UpperTriangularMatrix);
TEST_ADDITION(UpperTriangularMatrix, UpperTriangularMatrix);

#define TEST_SUBTRACTION(matrix_type1, matrix_type2)                                             \
    TEST_P(SameShapeOperations, matrix_type1##Sub##matrix_type2) {                               \
        const auto [rows, cols]         = GetParam();                                            \
        matrix1                         = get_matrix<matrix_type1>(rows, cols);                  \
        matrix2                         = get_matrix<matrix_type2>(rows, cols);                  \
        constexpr bool first_is_matrix  = std::is_same_v<matrix_type1, Matrix>;                  \
        constexpr bool second_is_matrix = std::is_same_v<matrix_type2, Matrix>;                  \
        constexpr bool is_same          = std::is_same_v<matrix_type1, matrix_type2>;            \
        for (int j = 0; j < (first_is_matrix ? cols : rows); ++j) {                              \
            for (int i = 0; i < rows; ++i) {                                                     \
                matrix1->setElement(i, j, i + j);                                                \
            }                                                                                    \
        }                                                                                        \
        for (int j = 0; j < (second_is_matrix ? cols : rows); ++j) {                             \
            for (int i = 0; i < rows; ++i) {                                                     \
                matrix2->setElement(i, j, i - j);                                                \
            }                                                                                    \
        }                                                                                        \
        if (is_same) {                                                                           \
            const matrix_type1* null_matrix = get_matrix<matrix_type1>(rows, cols);              \
            const matrix_type1  result_11   = *(matrix_type1*)matrix1 - *(matrix_type1*)matrix1; \
            ASSERT_TRUE(result_11 == *null_matrix);                                              \
            const matrix_type1 result_12 = *(matrix_type1*)matrix1 - *(matrix_type1*)matrix2;    \
            const matrix_type1 result_21 =                                                       \
                *null_matrix - (*(matrix_type1*)matrix2 - *(matrix_type1*)matrix1);              \
            ASSERT_TRUE(result_12 == result_21);                                                 \
        } else {                                                                                 \
            const Matrix* null_matrix = get_matrix<matrix_type1>(rows, cols);                    \
            const Matrix  result_11   = *matrix1 - *matrix1;                                     \
            ASSERT_TRUE(result_11 == *null_matrix);                                              \
            const Matrix result_12 = *matrix1 - *matrix2;                                        \
            const Matrix result_21 = *null_matrix - (*matrix2 - *matrix1);                       \
            ASSERT_TRUE(result_12 == result_21);                                                 \
        }                                                                                        \
    }

TEST_SUBTRACTION(DiagonalMatrix, DiagonalMatrix);
TEST_SUBTRACTION(DiagonalMatrix, LowerTriangularMatrix);
TEST_SUBTRACTION(DiagonalMatrix, SquareMatrix);
TEST_SUBTRACTION(DiagonalMatrix, UpperTriangularMatrix);
TEST_SUBTRACTION(LowerTriangularMatrix, LowerTriangularMatrix);
TEST_SUBTRACTION(LowerTriangularMatrix, SquareMatrix);
TEST_SUBTRACTION(LowerTriangularMatrix, UpperTriangularMatrix);
TEST_SUBTRACTION(Matrix, Matrix);
TEST_SUBTRACTION(SquareMatrix, DiagonalMatrix);
TEST_SUBTRACTION(SquareMatrix, SquareMatrix);
TEST_SUBTRACTION(SquareMatrix, UpperTriangularMatrix);
TEST_SUBTRACTION(UpperTriangularMatrix, UpperTriangularMatrix);

#define TEST_MULTIPLICATION(matrix_type1, matrix_type2)                                          \
    TEST_P(SameShapeOperations, matrix_type1##Mul##matrix_type2) {                               \
        const auto [rows, cols]         = GetParam();                                            \
        constexpr bool first_is_matrix  = std::is_same_v<matrix_type1, Matrix>;                  \
        constexpr bool second_is_matrix = std::is_same_v<matrix_type2, Matrix>;                  \
        if (first_is_matrix && !second_is_matrix) {                                              \
            matrix1 = get_matrix<matrix_type1>(rows, cols);                                      \
            matrix2 = get_matrix<matrix_type2>(cols, cols);                                      \
        } else if (!first_is_matrix && second_is_matrix) {                                       \
            matrix1 = get_matrix<matrix_type1>(rows, rows);                                      \
            matrix2 = get_matrix<matrix_type2>(rows, cols);                                      \
        } else {                                                                                 \
            matrix1 = get_matrix<matrix_type1>(rows, cols);                                      \
            matrix2 = get_matrix<matrix_type2>(cols, rows);                                      \
        }                                                                                        \
        for (int j = 0; j < (first_is_matrix ? matrix1->getCols() : matrix1->getRows()); ++j) {  \
            for (int i = 0; i < matrix1->getRows(); ++i) {                                       \
                matrix1->setElement(i, j, i + j);                                                \
            }                                                                                    \
        }                                                                                        \
        for (int j = 0; j < (second_is_matrix ? matrix2->getCols() : matrix2->getRows()); ++j) { \
            for (int i = 0; i < matrix2->getRows(); ++i) {                                       \
                matrix2->setElement(i, j, i - j);                                                \
            }                                                                                    \
        }                                                                                        \
        const Matrix result = *matrix1 * *matrix2;                                               \
        for (int i = 0; i < matrix1->getRows(); ++i) {                                           \
            for (int j = 0; j < matrix2->getCols(); ++j) {                                       \
                double sum = 0;                                                                  \
                for (int k = 0; k < matrix1->getCols(); ++k) {                                   \
                    sum += matrix1->getElement(i, k) * matrix2->getElement(k, j);                \
                }                                                                                \
                ASSERT_DOUBLE_EQ(result.getElement(i, j), sum);                                  \
            }                                                                                    \
        }                                                                                        \
    }

TEST_MULTIPLICATION(DiagonalMatrix, DiagonalMatrix);
TEST_MULTIPLICATION(DiagonalMatrix, LowerTriangularMatrix);

TEST_MULTIPLICATION(DiagonalMatrix, UpperTriangularMatrix);
TEST_MULTIPLICATION(LowerTriangularMatrix, LowerTriangularMatrix);
TEST_MULTIPLICATION(LowerTriangularMatrix, SquareMatrix);
TEST_MULTIPLICATION(LowerTriangularMatrix, UpperTriangularMatrix);
TEST_MULTIPLICATION(Matrix, Matrix);
TEST_MULTIPLICATION(SquareMatrix, DiagonalMatrix);
TEST_MULTIPLICATION(SquareMatrix, SquareMatrix);
TEST_MULTIPLICATION(SquareMatrix, UpperTriangularMatrix);
TEST_MULTIPLICATION(UpperTriangularMatrix, UpperTriangularMatrix);

#define TEST_COMPARISION(matrix_type1, matrix_type2)                                  \
    TEST_P(SameShapeOperations, matrix_type1##Eq##matrix_type2) {                     \
        const auto [rows, cols]         = GetParam();                                 \
        matrix1                         = get_matrix<matrix_type1>(rows, cols);       \
        matrix2                         = get_matrix<matrix_type2>(rows, cols);       \
        constexpr bool first_is_matrix  = std::is_same_v<matrix_type1, Matrix>;       \
        constexpr bool second_is_matrix = std::is_same_v<matrix_type2, Matrix>;       \
        constexpr bool is_same          = std::is_same_v<matrix_type1, matrix_type2>; \
        for (int j = 0; j < (first_is_matrix ? cols : rows); ++j) {                   \
            for (int i = 0; i < rows; ++i) {                                          \
                matrix1->setElement(i, j, i + j);                                     \
            }                                                                         \
        }                                                                             \
        for (int j = 0; j < (second_is_matrix ? cols : rows); ++j) {                  \
            for (int i = 0; i < rows; ++i) {                                          \
                matrix2->setElement(i, j, i - j);                                     \
            }                                                                         \
        }                                                                             \
        if (is_same) {                                                                \
            ASSERT_TRUE(*(matrix_type1*)matrix1 == *(matrix_type1*)matrix1);          \
            ASSERT_TRUE(*(matrix_type1*)matrix2 == *(matrix_type1*)matrix2);          \
            ASSERT_FALSE(*(matrix_type1*)matrix1 == *(matrix_type1*)matrix2);         \
        } else {                                                                      \
            ASSERT_TRUE(*matrix1 == *matrix1);                                        \
            ASSERT_TRUE(*matrix2 == *matrix2);                                        \
            ASSERT_FALSE(*matrix1 == *matrix2);                                       \
        }                                                                             \
    }

TEST_COMPARISION(DiagonalMatrix, DiagonalMatrix);
TEST_COMPARISION(DiagonalMatrix, LowerTriangularMatrix);
TEST_COMPARISION(DiagonalMatrix, SquareMatrix);
TEST_COMPARISION(DiagonalMatrix, UpperTriangularMatrix);
TEST_COMPARISION(LowerTriangularMatrix, LowerTriangularMatrix);
TEST_COMPARISION(LowerTriangularMatrix, SquareMatrix);
TEST_COMPARISION(LowerTriangularMatrix, UpperTriangularMatrix);
TEST_COMPARISION(Matrix, Matrix);
TEST_COMPARISION(SquareMatrix, DiagonalMatrix);
TEST_COMPARISION(SquareMatrix, SquareMatrix);
TEST_COMPARISION(SquareMatrix, UpperTriangularMatrix);
TEST_COMPARISION(UpperTriangularMatrix, UpperTriangularMatrix);
