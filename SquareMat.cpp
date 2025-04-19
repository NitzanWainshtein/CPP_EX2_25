//
// Created by nitzan on 4/14/25.
//

#include "SquareMat.h"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace theMatrix {
    //constructor
    SquareMat::SquareMat(int n) : size(n) {
        if (n <= 0) {
            throw invalid_argument("Size must be at least 1.");
        }
        matrix = new double *[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = 0.0;
            }
        }
    }

    //copy constructor
    SquareMat::SquareMat(const SquareMat &other) : size(other.size) {
        matrix = new double *[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    SquareMat &SquareMat::operator=(const SquareMat &other) {
        if (this == &other) return *this;

        for (int i = 0; i < size; ++i) { delete[] matrix[i]; }
        delete[] matrix;

        //copy:
        size = other.size;
        matrix = new double *[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
    }

    SquareMat::~SquareMat() {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void SquareMat::setSingleValue(int row, int col, double value) {
        if (row < 0 || col < 0 || row >= size || col >= size) {
            throw out_of_range("index out of range.");
        }
        matrix[row][col] = value;
    }

    void SquareMat::setFullMatrix() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Enter value for [" << i << "][" << j << "]: ";
                double val;
                cin >> val;
                if (!cin) {
                    throw invalid_argument("Input is invalid");
                }
                setSingleValue(i, j, val);
            }
        }
    }

    SquareMat operator+(const SquareMat &a, const SquareMat &b) {
        if (a.size != b.size) {
            throw invalid_argument("Matrices must be same size for addition.");
        }
        SquareMat res(a.size);
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                res.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
            }
        }
        return res;
    }


    SquareMat operator-(const SquareMat &a, const SquareMat &b) {
        if (a.size != b.size) {
            throw invalid_argument("Matrices must be same size for subtraction.");
        }
        SquareMat res(a.size);
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                res.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
            }
        }
        return res;
    }

    SquareMat SquareMat::operator-() const {
        SquareMat res(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                res.matrix[i][j] = -matrix[i][j];
            }
        }
        return res;
    }

    SquareMat operator*(const SquareMat &a, const SquareMat &b) {
        if (a.size != b.size) {
            throw invalid_argument("Matrices must be same size.");
        }
        SquareMat res(a.size);
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                double sum = 0.0;
                for (int k = 0; k < a.size; ++k) {
                    sum += a.matrix[i][k] * b.matrix[k][j];
                }
                res.matrix[i][j] = sum;
            }
        }
        return res;
    }


    //Printing operator <<
    std::ostream &operator<<(std::ostream &os, const SquareMat &mat) {
        for (int i = 0; i < mat.size; ++i) {
            os << "| ";
            for (int j = 0; j < mat.size; ++j) {
                os << mat.matrix[i][j];
                if (j != mat.size - 1) {
                    os << ' '; // רווח בין איברים
                }
            }
            os << " |" << std::endl;
        }
        return os;
    }
}
