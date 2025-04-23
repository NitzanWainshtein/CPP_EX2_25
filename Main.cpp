// Email: nitzanwa@gmail.com

#include <iostream>
#include "include/SquareMat.hpp"
using namespace std;
using namespace theMatrix;

int main() {
    SquareMat A(2), B(2);
    double scalar;

    cout << "Enter values for Matrix A:" << endl;
    A.setFullMatrix();

    cout << "Enter values for Matrix B:" << endl;
    B.setFullMatrix();

    cout << "Enter a scalar value: ";
    cin >> scalar;

    cout << "\n--- Operations on A and B ---\n";
    cout << "A + B =\n" << (A + B);
    cout << "A - B =\n" << (A - B);
    cout << "A * B =\n" << (A * B);
    cout << "A % B (element-wise) =\n" << (A % B);

    cout << "\n--- Operations with scalar " << scalar << " ---\n";
    cout << "A * scalar =\n" << (A * scalar);
    cout << "scalar * A =\n" << (scalar * A);
    cout << "A / scalar =\n" << (A / scalar);
    if (scalar != 0)
        cout << "A % scalar =\n" << (A % static_cast<int>(scalar));

    cout << "\n--- Unary operations ---\n";
    cout << "-A =\n" << (-A);
    cout << "++A =\n" << (++A);
    cout << "A++ =\n" << (A++);
    cout << "--A =\n" << (--A);
    cout << "A-- =\n" << (A--);

    cout << "\n--- Transpose and Power ---\n";
    cout << "~A =\n" << (~A);
    cout << "A ^ 2 =\n" << (A ^ 2);

    cout << "\n--- Determinant ---\n";
    cout << "!A = " << !A << endl;

    cout << "\n--- Comparisons ---\n";
    cout << "A == B: " << (A == B ? "true" : "false") << endl;
    cout << "A != B: " << (A != B ? "true" : "false") << endl;
    cout << "A < B:  " << (A < B ? "true" : "false") << endl;
    cout << "A > B:  " << (A > B ? "true" : "false") << endl;
    cout << "A <= B: " << (A <= B ? "true" : "false") << endl;
    cout << "A >= B: " << (A >= B ? "true" : "false") << endl;

    return 0;
}
