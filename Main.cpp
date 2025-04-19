#include <iostream>
#include "SquareMat.h"
using namespace std;
using namespace theMatrix;

int main() {
    try {
        SquareMat mat1(2);
        mat1.setFullMatrix();
        SquareMat mat2(2);
        mat2.setFullMatrix();

        // נגיד שכבר מילאנו את הערכים של mat בדרך כלשהי
        // כעת מדפיסים בעזרת האופרטור שהגדרנו
        cout << "mat1:" << endl;
        cout << mat1 << endl;
        cout << "mat2:" << endl;
        cout << mat2 << endl;
        cout << "mat multiplied:" << endl;
        cout << mat1*mat2 << endl;

    }
    catch(const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
