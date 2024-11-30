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
    if (this->rows != other.rows || this->cols != other.cols) {
        
    }

    DiagonalMatrix result(this->rows);
    for (int i = 0; i < this->rows; ++i) {
        double product = this->getElement(i, i) * other.getElement(i, i);
        result.setElement(i, i, product);
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

