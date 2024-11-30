#include "LowerTriangularMatrix.hpp"

void LowerTriangularMatrix::setElement(const int row, const int col, const double value) {
    if (row >= col) {
        this->elements[(row * (row + 1) >> 1) + col] = value;
    }
}

LowerTriangularMatrix::LowerTriangularMatrix(const int size){
    rows=size;
    cols=size;
    const int nonZeroElements = (size * (size + 1)) >> 1;
    this->elements            = std::vector<double>(nonZeroElements, 0.0);
}
LowerTriangularMatrix::LowerTriangularMatrix(LowerTriangularMatrix const& a){
    rows=a.rows;
    cols=a.cols;
    elements.clear();
    for (int x=0;x<(rows*(rows+1));x++){
        elements.push_back(a.elements[x]);

    }
}

LowerTriangularMatrix LowerTriangularMatrix::operator*(const LowerTriangularMatrix& other) const {
    LowerTriangularMatrix result = LowerTriangularMatrix(this->rows);
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
LowerTriangularMatrix LowerTriangularMatrix::operator+(const LowerTriangularMatrix& other) const {
    LowerTriangularMatrix result = LowerTriangularMatrix(this->rows);
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}
LowerTriangularMatrix LowerTriangularMatrix::operator-(const LowerTriangularMatrix& other) const {
    LowerTriangularMatrix result = LowerTriangularMatrix(this->rows);
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}
bool LowerTriangularMatrix::operator==(const LowerTriangularMatrix& other) const {
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            if (this->getElement(i, j) != other.getElement(i, j)){return false;};
        }
    }
    return true;
}
double LowerTriangularMatrix::getElement(const int row, const int col) const{
    return this->elements[(row * (row + 1) >> 1) + col];
}

