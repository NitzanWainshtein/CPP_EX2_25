// Email: nitzanwa@gmail.com

#pragma once
#include <iostream>

/**
 * SquareMat - A class for square matrices (n x n) of real numbers.
 * Supports arithmetic operators, element access, transpose, and determinant.
 */
namespace theMatrix {
    class SquareMat {
    private:
        int size; // Matrix dimension (n x n)
        double **matrix; // Pointer to 2D array of doubles

    public:
        explicit SquareMat(int n); // Constructor: initializes n*n matrix.
        SquareMat(const SquareMat &other); // Copy constructor.
        SquareMat &operator=(const SquareMat &other); // Copy assignment.
        ~SquareMat(); // Destructor: frees memory.

        void setSingleValue(int row, int col, double value); // Set a specific cell value
        void setFullMatrix(); // Fill matrix from user input (via cin)

        friend SquareMat operator+(const SquareMat &a, const SquareMat &b); // Matrix addition
        friend SquareMat operator-(const SquareMat &a, const SquareMat &b); // Matrix subtraction
        SquareMat operator-() const; // Unary minus (negates matrix)

        friend SquareMat operator*(const SquareMat &a, const SquareMat &b); // Matrix multiplication
        friend SquareMat operator*(const SquareMat &mat, double scalar); // Scalar multiplication (right)
        friend SquareMat operator*(double scalar, const SquareMat &mat); // Scalar multiplication (left)

        friend SquareMat operator%(const SquareMat &a, const SquareMat &b); // Element-wise multiplication
        friend SquareMat operator%(const SquareMat &mat, int scalar); // Modulo each element by scalar

        friend SquareMat operator/(const SquareMat &mat, double scalar); // Scalar division
        friend SquareMat operator^(const SquareMat &mat, int power); // Raise matrix by power

        SquareMat &operator++(); // Pre-increment all elements
        SquareMat operator++(int); // Post-increment all elements
        SquareMat &operator--(); // Pre-decrement all elements
        SquareMat operator--(int); // Post-decrement all elements

        SquareMat operator~() const; // Transpose the matrix
        double *operator[](int row) const; // Access row via index

        friend bool operator==(const SquareMat &a, const SquareMat &b); // Equality by sum of elements
        friend bool operator!=(const SquareMat &a, const SquareMat &b); // Inequality by sum of elements

        friend bool operator<(const SquareMat &a, const SquareMat &b); // Compare sums (less than)
        friend bool operator>(const SquareMat &a, const SquareMat &b); // Compare sums (greater than)
        friend bool operator<=(const SquareMat &a, const SquareMat &b); // Compare sums (less or equal)
        friend bool operator>=(const SquareMat &a, const SquareMat &b); // Compare sums (greater or equal)

        double operator!() const; // Determinant calculation

        friend SquareMat makeMinor(const SquareMat &A, int skipRow, int skipCol); // Compute matrix minor (helper function)

        SquareMat &operator+=(const SquareMat &other); // Compound addition
        SquareMat &operator-=(const SquareMat &other); // Compound subtraction
        SquareMat &operator*=(const SquareMat &other); // Compound matrix multiplication
        SquareMat &operator*=(double scalar); // Compound scalar multiplication
        SquareMat &operator/=(double scalar); // Compound scalar division
        SquareMat &operator%=(const SquareMat &other); // Compound element-wise multiplication
        SquareMat &operator%=(int scalar); // Compound modulo with scalar

        friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat); // Output matrix to stream
    };
} // theMatrix
