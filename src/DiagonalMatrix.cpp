#include "DiagonalMatrix.hpp"

double DiagonalMatrix::getElement(const int row, const int col) const {
    return row != col ? 0.0 : this->elements[row];
}

DiagonalMatrix::DiagonalMatrix(const int size){
    rows=size;
    cols=size;
    for (int x=0;x<(size);x++){
        elements.push_back(0);

    }
}
DiagonalMatrix::DiagonalMatrix(DiagonalMatrix const& a){
    rows=a.rows;
    cols=a.cols;
    elements=a.elements;
}

DiagonalMatrix DiagonalMatrix::operator*(const DiagonalMatrix& other) const {
    DiagonalMatrix result = DiagonalMatrix(this->rows);
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
DiagonalMatrix DiagonalMatrix::operator+(const DiagonalMatrix& other) const {
    DiagonalMatrix result = DiagonalMatrix(this->rows);
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}
DiagonalMatrix DiagonalMatrix::operator-(const DiagonalMatrix& other) const {
    DiagonalMatrix result = DiagonalMatrix(this->rows);
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}
bool DiagonalMatrix::operator==(const DiagonalMatrix& other) const {
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            if (this->getElement(i, j) != other.getElement(i, j)){return false;};
        }
    }
    return true;
}

void DiagonalMatrix::setElement(const int row, const int col, const double value ){
    elements[row]=value;
}

