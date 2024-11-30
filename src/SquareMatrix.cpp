#include "SquareMatrix.hpp"
SquareMatrix::SquareMatrix(const int size){
    rows=size;
    cols=size;
    for (int x=0;x<(size*size);x++){
        elements.push_back(0);

    }
}
SquareMatrix::SquareMatrix(SquareMatrix const& a){
    rows=a.rows;
    cols=a.cols;
    for (int x=0;x<(rows*cols);x++){
        elements.push_back(a.elements[x]);

    }
}

SquareMatrix SquareMatrix::operator*(const SquareMatrix& other) const {
    SquareMatrix result = SquareMatrix(this->rows);
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
SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) const {
    SquareMatrix result = SquareMatrix(this->rows);
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}
SquareMatrix SquareMatrix::operator-(const SquareMatrix& other) const {
    SquareMatrix result = SquareMatrix(this->rows);
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}
bool SquareMatrix::operator==(const SquareMatrix& other) const {
    
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            if (this->getElement(i, j) != other.getElement(i, j)){return false;};
        }
    }
    return true;
}
double SquareMatrix::getElement(const int row, const int col) const{
    return Matrix::getElement(row, col);
}
void SquareMatrix::setElement(const int row, const int col, const double value ){
    elements[row*cols+col]=value;
}
