//
// Created by nitzan on 4/14/25.
//

#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include <stdexcept>
#include <iostream>
namespace theMatrix {
    class SquareMat {
    private:
        int size;
        double **matrix;

    public:
        explicit SquareMat(int n); //Constructor
        SquareMat(const SquareMat& other); //Copy constructor
        SquareMat& operator=(const SquareMat& other); //Assignment constructor
        ~SquareMat(); //Destructor
        void setSingleValue(int row , int col , double value);
        void setFullMatrix();
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
        friend SquareMat operator+(const SquareMat& a, const SquareMat& b);
        friend SquareMat operator-(const SquareMat& a, const SquareMat& b);
        SquareMat operator-() const;
        friend SquareMat operator*(const SquareMat& a, const SquareMat& b);

    };
} // theMatrix

#endif //SQUAREMAT_H
