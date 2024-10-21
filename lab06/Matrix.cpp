//
// Created by Csala on 2024. 10. 28..
//

#include "Matrix.h"
#include "random"

Matrix::~Matrix() {
    if(mElements == nullptr)
    {
        return;
    }
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
}

Matrix::Matrix(int mRows, int mCols) {
this->mRows = mRows;
this->mCols = mCols;
this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mElements = nullptr;
}

int Matrix::getCols() const {
    return this->mCols;
}

int Matrix::getRows() const {
    return this->mRows;
}

bool Matrix::isSquare() const {
    return this->mRows==this->mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows == y.mRows && x.mCols == y.mCols)
    {
        Matrix newMatrix(x.mRows, x.mCols);
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                newMatrix.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
        return newMatrix;
    }
    throw std::out_of_range("Matrices must have the same dimensions for addition.");
}


Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mRows == y.mRows && x.mCols == y.mCols)
    {
        Matrix newMatrix(x.mRows, x.mCols);
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                newMatrix.mElements[i][j] = x.mElements[i][j] * y.mElements[i][j];
            }
        }
        return newMatrix;
    }
    throw std::out_of_range("Matrices must have the same dimensions for addition.");
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(a, b); // return a number in the given range
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = dist(mt);
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            os <<  this->mElements[i][j] << " ";
        }
        os<< endl;
    }
}



ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix();
    return os;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            cin >> (mat.mElements[i][j]);
        }
    }
    return is;
}

double *Matrix::operator[](int index) {
    return this->mElements[index];
}

double *Matrix::operator[](int index) const {
    return this->mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if(mat.mRows == this->mRows && mat.mCols == this->mCols)
    {
        for (int i = 0; i < mat.mRows; ++i) {
            for (int j = 0; j <mat.mCols; ++j) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
        return *this;
    }
    else throw std::out_of_range("Matrices must have the same dimensions for addition.");

}

Matrix &Matrix::operator=(Matrix &&mat) {
    if(mat.mRows == this->mRows && mat.mCols == this->mCols)
    {
        for (int i = 0; i < mat.mRows; ++i) {
            for (int j = 0; j <mat.mCols; ++j) {
                auto variable = this->mElements[i][j];
                this->mElements[i][j] = mat.mElements[i][j];
                mat.mElements[i][j] = variable;
            }
        }
        return *this;
    }
    else throw std::out_of_range("Matrices must have the same dimensions for addition.");
}




