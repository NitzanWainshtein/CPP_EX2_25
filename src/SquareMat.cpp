// Email: nitzanwa@gmail.com

#include "../include/SquareMat.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace theMatrix {
    // Constructor: allocates and initializes matrix to zeros
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

    // Copy constructor: deep copies the matrix
    SquareMat::SquareMat(const SquareMat &other) : size(other.size) {
        matrix = new double *[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // Copy assignment: cleans up and deep copies another matrix
    SquareMat &SquareMat::operator=(const SquareMat &other) {
        if (this == &other) return *this;

        for (int i = 0; i < size; ++i) { delete[] matrix[i]; }
        delete[] matrix;
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

    // Destructor: frees allocated memory
    SquareMat::~SquareMat() {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Set a specific value in the matrix
    void SquareMat::setSingleValue(int row, int col, double value) {
        if (row < 0 || col < 0 || row >= size || col >= size) {
            throw out_of_range("index out of range.");
        }
        matrix[row][col] = value;
    }

    // Fill matrix from user input (stdin)
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

    // Matrix addition
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

    // Matrix subtraction
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

    // Unary minus: negate all matrix elements
    SquareMat SquareMat::operator-() const {
        SquareMat res(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                res.matrix[i][j] = -matrix[i][j];
            }
        }
        return res;
    }

    // Matrix multiplication
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

    // Scalar multiplication (matrix * scalar)
    SquareMat operator*(const SquareMat &mat, double scalar) {
        SquareMat res(mat.size);
        for (int i = 0; i < mat.size; ++i)
            for (int j = 0; j < mat.size; ++j)
                res.matrix[i][j] = mat.matrix[i][j] * scalar;
        return res;
    }

    // Scalar multiplication (scalar * matrix)
    SquareMat operator*(double scalar, const SquareMat &mat) {
        return mat * scalar;
    }

    // Element-wise multiplication (Hadamard product)
    SquareMat operator%(const SquareMat &a, const SquareMat &b) {
        if (a.size != b.size) {
            throw invalid_argument("Matrices must be same size for element-wise multiplication.");
        }
        SquareMat res(a.size);
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                res.matrix[i][j] = a.matrix[i][j] * b.matrix[i][j];
            }
        }
        return res;
    }

    // Modulo each matrix element by scalar
    SquareMat operator%(const SquareMat &mat, int scalar) {
        if (scalar == 0) {
            throw invalid_argument("Mod by zero");
        }
        SquareMat res(mat.size);
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                res.matrix[i][j] = fmod(mat.matrix[i][j], scalar);
            }
        }
        return res;
    }

    // Divide each element by scalar
    SquareMat operator/(const SquareMat &mat, double scalar) {
        if (scalar == 0) {
            throw invalid_argument("Divide by zero");
        }
        SquareMat res(mat.size);
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                res.matrix[i][j] = mat.matrix[i][j] / scalar;
            }
        }
        return res;
    }

    // Raise matrix to integer power
    SquareMat operator^(const SquareMat &mat, int power) {
        if (power < 0) {
            throw invalid_argument("Power must be positive.");
        }
        int n = mat.size;

        if (power == 0) {
            SquareMat I(n);
            for (int i = 0; i < n; ++i) {
                I.matrix[i][i] = 1.0;
            }
            return I;
        }
        SquareMat res = mat;
        for (int j = 1; j < power; ++j) {
            res = res * mat;
        }
        return res;
    }

    // Pre-increment: add 1 to all elements
    SquareMat &SquareMat::operator++() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] += 1.0;
            }
        }
        return *this;
    }

    // Post-increment: add 1 to all elements and return previous
    SquareMat SquareMat::operator++(int) {
        SquareMat previous = *this; // copy-ctor
        ++(*this);
        return previous;
    }

    // Pre-decrement: subtract 1 from all elements
    SquareMat &SquareMat::operator--() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] -= 1.0;
            }
        }
        return *this;
    }

    // Post-decrement: subtract 1 and return previous
    SquareMat SquareMat::operator--(int) {
        SquareMat previous = *this; // copy-ctor
        --(*this);
        return previous;
    }

    // Transpose the matrix
    SquareMat SquareMat::operator~() const {
        SquareMat res(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                res.matrix[i][j] = matrix[j][i];
            }
        }
        return res;
    }

    // Access a row via index
    double *SquareMat::operator[](int row) const {
        if (row < 0 || row >= size) {
            throw out_of_range("Row index out of range");
        }
        return matrix[row];
    }

    // Check if sum of elements is equal
    bool operator==(const SquareMat &a, const SquareMat &b) {
        if (a.size != b.size) {
            throw invalid_argument("Matrices must be same size for equality.");
        }
        double sum_a = 0.0;
        double sum_b = 0.0;
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                sum_a += a.matrix[i][j];
                sum_b += b.matrix[i][j];
            }
        }
        return sum_a == sum_b;
    }

    // Negation of ==
    bool operator!=(const SquareMat &a, const SquareMat &b) {
        return !(a == b);
    }

    // Compare sum of elements (less than)
    bool operator<(const SquareMat &a, const SquareMat &b) {
        if (a.size != b.size) {
            throw invalid_argument("Matrices must be same size for comparison.");
        }
        double sum_a = 0.0, sum_b = 0.0;
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                sum_a += a.matrix[i][j];
                sum_b += b.matrix[i][j];
            }
        }
        return sum_a < sum_b;
    }

    // Greater than
    bool operator>(const SquareMat &a, const SquareMat &b) {
        return b < a;
    }

    // Less or equal
    bool operator<=(const SquareMat &a, const SquareMat &b) {
        return !(a > b);
    }

    // Greater or equal
    bool operator>=(const SquareMat &a, const SquareMat &b) {
        return !(a < b);
    }

    // helper to build the minor matrix
    SquareMat makeMinor(const SquareMat &A, int skipRow, int skipCol) {
        int n = A.size;
        SquareMat M(n - 1);
        for (int i = 0, mi = 0; i < n; ++i) {
            if (i == skipRow) continue;
            for (int j = 0, mj = 0; j < n; ++j) {
                if (j == skipCol) continue;
                M.matrix[mi][mj] = A.matrix[i][j];
                ++mj;
            }
            ++mi;
        }
        return M;
    }

    // Calculate determinant recursively
    double SquareMat::operator!() const {
        int n = size;
        if (n == 1) {
            return matrix[0][0];
        }
        if (n == 2) {
            return matrix[0][0] * matrix[1][1]
                   - matrix[0][1] * matrix[1][0];
        }
        double det = 0.0;
        for (int j = 0; j < n; ++j) {
            double sign = (j % 2 == 0 ? 1.0 : -1.0);
            double a0j = matrix[0][j];
            SquareMat minor = makeMinor(*this, 0, j);
            det += sign * a0j * minor.operator!();
        }
        return det;
    }

    // Compound addition (+=): adds another matrix element-wise
    SquareMat &SquareMat::operator+=(const SquareMat &other) {
        if (size != other.size) {
            throw invalid_argument("Matrices must be same size for +=");
        }
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] += other.matrix[i][j];
        return *this;
    }

    // Compound subtraction (-=): subtracts another matrix element-wise
    SquareMat &SquareMat::operator-=(const SquareMat &other) {
        if (size != other.size) {
            throw invalid_argument("Matrices must be same size for -=");
        }
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] -= other.matrix[i][j];
        return *this;
    }

    // Compound matrix multiplication (*=): multiplies with another matrix
    SquareMat &SquareMat::operator*=(const SquareMat &other) {
        if (size != other.size) {
            throw invalid_argument("Matrices must be same size for *=");
        }
        SquareMat temp(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                double sum = 0.0;
                for (int k = 0; k < size; ++k)
                    sum += matrix[i][k] * other.matrix[k][j];
                temp.matrix[i][j] = sum;
            }
        }
        *this = std::move(temp);
        return *this;
    }

    // Compound scalar multiplication (*=): multiplies all elements by scalar
    SquareMat &SquareMat::operator*=(double scalar) {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] *= scalar;
        return *this;
    }

    // Compound scalar division (/=): divides all elements by scalar
    SquareMat &SquareMat::operator/=(double scalar) {
        if (scalar == 0.0) {
            throw invalid_argument("Divide by zero in /=");
        }
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] /= scalar;
        return *this;
    }

    // Compound element-wise multiplication (%=): multiplies element-wise with another matrix
    SquareMat &SquareMat::operator%=(const SquareMat &other) {
        if (size != other.size) {
            throw invalid_argument("Matrices must be same size for %=");
        }
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] *= other.matrix[i][j];
        return *this;
    }

    // Compound modulo with scalar (%=): applies modulo to each element
    SquareMat &SquareMat::operator%=(int scalar) {
        if (scalar == 0) {
            throw invalid_argument("Mod by 0 in %=");
        }
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                double r = std::fmod(matrix[i][j], scalar);
                if (r < 0) r += scalar;
                matrix[i][j] = r;
            }
        return *this;
    }

    // Output matrix using stream (<<): prints matrix row-by-row
    ostream &operator<<(ostream &os, const SquareMat &mat) {
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
