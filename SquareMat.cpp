//
// Created by nitzan on 4/14/25.
//

#include "SquareMat.h"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace theMatrix {
    SquareMat::SquareMat(int n) : size(n) {
        if (n <= 0) {
            throw invalid_argument("Size must be at least 1.");
        }
        matrix = new double *[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    SquareMat::~SquareMat() {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void SquareMat::setSingleValue(int row, int col, double value) {
        if (row < 0 || col < 0 || row>=size || col>=size) {
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
                    throw invalid_argument("Input is unvalid");
                }
                setSingleValue(i,j,val);
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for(int i = 0; i < mat.size; i++) {
            cout<<"| ";
            for(int j = 0; j < mat.size; j++) {
                os << mat.matrix[i][j] << " ";
                if (j==mat.size-1) {
                    cout << "|";
                }
            }
            os << std::endl;
        }
        return os;
    }
} // theMatrix
