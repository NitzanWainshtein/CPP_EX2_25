//
// Created by nitzan on 4/14/25.
//

#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include <stdexcept>

namespace theMatrix {
    class SquareMat {
    private:
        int size;
        double **matrix;

    public:
        SquareMat(int n); //Constructor
        ~SquareMat(); //Destructor
        void setSingleValue(int row , int col , double value);
        void setFullMatrix();
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

    };
} // theMatrix

#endif //SQUAREMAT_H
