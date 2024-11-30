#include "Matrix.hpp" 
Matrix::Matrix(const int r , const int c ){
    rows=r;
    cols=c;
    for (int x=0;x<(r*c);x++){
        elements.push_back(0);

    }

}
Matrix::Matrix( Matrix const& a){
    rows=a.rows;
    cols=a.cols;
    elements.clear();
for (int x=0;x<(rows*cols);x++){
        
        elements.push_back(a.elements[x]);

    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result = Matrix(this->rows, this->cols);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}
Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result = Matrix(this->rows, this->cols);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}
bool Matrix::operator==(const Matrix& other) const {
    if(rows==other.rows && cols==other.cols){
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            if (this->getElement(i, j) != other.getElement(i, j)){return false;};
        }
    }
    return true;}else{return false;}
}

Matrix Matrix::operator*(const Matrix& other) const {
    int i =0;
    int j =0;
    double sumx,sumy=0;
    if (cols==other.rows){
        Matrix result = Matrix(this->rows, other.cols);
        for (int i=0;i<rows;++i){
        for (int j=0;j<other.cols;++j) {
            double sum=0; 
            for(int k=0;k<cols;++k) {
                sum+=this->getElement(i, k)*other.getElement(k, j);
            }
            result.setElement(i, j, sum);
        }}
    
        return result;}}
double Matrix::getElement(const int row, const int col) const{
    return elements[row*cols+col];
}
void Matrix::setElement(const int row, const int col, const double value ){
    elements[row*cols+col]=value;
}
int Matrix::getRows() const{return rows;}
int Matrix::getCols() const{return cols;};
int Matrix::getElementsSize() const{return elements.size();};


