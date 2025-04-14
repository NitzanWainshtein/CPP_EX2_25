#include <iostream>
#include "SquareMat.h"
using namespace std;
using namespace theMatrix;

int main() {
    try {
        SquareMat mat(3);
        mat.setFullMatrix();

        // נגיד שכבר מילאנו את הערכים של mat בדרך כלשהי
        // כעת מדפיסים בעזרת האופרטור שהגדרנו
        cout << mat << endl;
    }
    catch(const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
