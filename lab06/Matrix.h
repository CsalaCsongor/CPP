#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdexcept>
using namespace std;
class Matrix {
public:
//Methods
// Default constructor
    Matrix( int mRows = 10, int mCols =10);
// Copy constructor
    Matrix(const Matrix& what);
// Move constructor
    Matrix( Matrix&& what );
// Destructor
    ~Matrix();


    bool isSquare() const;
    int getRows() const;
    int getCols() const;

    void fillMatrix(double value);
    void randomMatrix(int a, int b);

    void printMatrix(ostream& os = cout) const;

    friend Matrix operator+(const Matrix& x, const Matrix& y);
    friend Matrix operator*(const Matrix& x, const Matrix& y);

    friend istream & operator>>(istream& is, Matrix& mat);
    friend ostream & operator<<(ostream& os, const Matrix& mat);

    double* operator[] (int index);
// index operator that works on constant matrices!
    double* operator[] (int index) const;

    Matrix & operator=(const Matrix& mat);
// Move assignment
    Matrix & operator=(Matrix&& mat);




private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};
#endif /* MATRIX_H */
