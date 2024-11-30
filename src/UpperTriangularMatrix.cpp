#include "UpperTriangularMatrix.hpp"

UpperTriangularMatrix::UpperTriangularMatrix(int size) {
    this->rows = size;
    this->cols = size;
    const int nonZeroElements = (size * (size + 1)) / 2;
    this->elements = std::vector<double>(nonZeroElements, 0.0);
}

void UpperTriangularMatrix::setElement(int row, int col, double value) {
    
    this->elements[(row * this->cols) + col - (row * (row + 1)) / 2] = value;
}

double UpperTriangularMatrix::getElement(int row, int col) const {
    if (row > col) {
        return 0.0;
    }
    
    return this->elements[(row * this->cols) + col - (row * (row + 1)) / 2];
}

UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix& other) {
    this->rows = other.rows;
    this->cols = other.cols;
    elements = other.elements;
}

UpperTriangularMatrix UpperTriangularMatrix::operator*(const UpperTriangularMatrix& other) const {
    

    UpperTriangularMatrix result(this->rows);

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            double result_ij = 0.0;
            for (int k = 0; k < this->cols; ++k) {
                result_ij += this->getElement(i, k) * other.getElement(k, j);
            }
            result.setElement(i, j, result_ij);
        }
    }
    return result;
}

UpperTriangularMatrix UpperTriangularMatrix::operator+(const UpperTriangularMatrix& other) const {
    

    UpperTriangularMatrix result(this->rows);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

UpperTriangularMatrix UpperTriangularMatrix::operator-(const UpperTriangularMatrix& other) const {
    

    UpperTriangularMatrix result(this->rows);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

bool UpperTriangularMatrix::operator==(const UpperTriangularMatrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        return false;
    }
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            if (this->getElement(i, j) != other.getElement(i, j)) {
                return false;
            }
        }
    }
    return true;
}