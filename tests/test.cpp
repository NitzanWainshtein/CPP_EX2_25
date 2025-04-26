// Email: nitzanwa@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/SquareMat.hpp"

using namespace theMatrix;
using namespace doctest;
using namespace std;

TEST_CASE("Matrix Constructors and Access") {
    SquareMat m(3);
    m.setSingleValue(0, 0, 1);
    m.setSingleValue(1, 1, 2);
    m.setSingleValue(2, 2, 3);
    CHECK(m[0][0] == Approx(1));
    CHECK(m[1][1] == Approx(2));
    CHECK(m[2][2] == Approx(3));
}

TEST_CASE("Operator +, -, +=, -=") {
    SquareMat a(2), b(2);
    a.setSingleValue(0,0,1);
    a.setSingleValue(1,1,2);
    b.setSingleValue(0,0,3);
    b.setSingleValue(1,1,4);
    SquareMat c = a + b;
    CHECK(c[0][0] == Approx(4));
    CHECK(c[1][1] == Approx(6));
    c -= b;
    CHECK(c[0][0] == Approx(1));
    CHECK(c[1][1] == Approx(2));
    c += b;
    CHECK(c[0][0] == Approx(4));
    CHECK(c[1][1] == Approx(6));
}

TEST_CASE("Unary minus and scalar multiplication/division") {
    SquareMat a(2);
    a.setSingleValue(0,0,2);
    a.setSingleValue(1,1,-4);
    SquareMat neg = -a;
    CHECK(neg[0][0] == Approx(-2));
    CHECK(neg[1][1] == Approx(4));
    a *= 3;
    CHECK(a[0][0] == Approx(6));
    CHECK(a[1][1] == Approx(-12));
    a /= 3;
    CHECK(a[0][0] == Approx(2));
    CHECK(a[1][1] == Approx(-4));
}

TEST_CASE("Matrix multiplication and element-wise multiplication") {
    SquareMat a(2), b(2);
    a.setSingleValue(0,0,1); a.setSingleValue(0,1,2);
    a.setSingleValue(1,0,3); a.setSingleValue(1,1,4);
    b.setSingleValue(0,0,2); b.setSingleValue(0,1,0);
    b.setSingleValue(1,0,1); b.setSingleValue(1,1,2);
    SquareMat mult = a * b;
    CHECK(mult[0][0] == Approx(4));
    CHECK(mult[1][1] == Approx(8));
    SquareMat elem = a % b;
    CHECK(elem[0][0] == Approx(2));
    CHECK(elem[1][1] == Approx(8));
}

TEST_CASE("Modulo operator with scalar and %= operator") {
    SquareMat a(2);
    a.setSingleValue(0,0,5);
    a.setSingleValue(1,1,9);
    SquareMat mod = a % 4;
    CHECK(mod[0][0] == Approx(1));
    CHECK(mod[1][1] == Approx(1));
    a %= 4;
    CHECK(a[0][0] == Approx(1));
    CHECK(a[1][1] == Approx(1));
}

TEST_CASE("Transpose, Power, and Determinant") {
    SquareMat a(2);
    a.setSingleValue(0,0,1);
    a.setSingleValue(0,1,2);
    a.setSingleValue(1,0,3);
    a.setSingleValue(1,1,4);
    SquareMat trans = ~a;
    CHECK(trans[0][1] == Approx(3));
    CHECK(trans[1][0] == Approx(2));
    SquareMat id = a ^ 0;
    CHECK(id[0][0] == Approx(1));
    CHECK(id[1][1] == Approx(1));
    SquareMat pow = a ^ 2;
    CHECK(pow[0][0] == Approx(7));
    CHECK(pow[1][1] == Approx(22));
    CHECK(!a == Approx(-2));
}

TEST_CASE("Comparison and equality operators (by sum of elements)") {
    SquareMat a(2), b(2);
    a.setSingleValue(0,0,1);
    a.setSingleValue(1,1,1); // sum = 2
    b.setSingleValue(0,0,3); // sum = 3

    CHECK(a != b);
    CHECK(b > a);
    CHECK(a < b);
    CHECK(b >= a);
    CHECK(!(a >= b));
    CHECK(!(b < a));
}

TEST_CASE("Increment and Decrement operators") {
    SquareMat a(2);
    a.setSingleValue(0,0,1);
    ++a;
    CHECK(a[0][0] == Approx(2));
    a++;
    CHECK(a[0][0] == Approx(3));
    --a;
    CHECK(a[0][0] == Approx(2));
    a--;
    CHECK(a[0][0] == Approx(1));
}

TEST_CASE("Compound matrix multiplication (*=)") {
    SquareMat a(2), b(2);
    a.setSingleValue(0,0,1); a.setSingleValue(0,1,2);
    a.setSingleValue(1,0,3); a.setSingleValue(1,1,4);
    b.setSingleValue(0,0,2); b.setSingleValue(0,1,0);
    b.setSingleValue(1,0,1); b.setSingleValue(1,1,2);
    a *= b;
    CHECK(a[0][0] == Approx(4));
    CHECK(a[1][1] == Approx(8));
}

TEST_CASE("Stream output operator (<<)") {
    SquareMat a(2);
    a.setSingleValue(0,0,1);
    a.setSingleValue(0,1,2);
    stringstream ss;
    ss << a;
    string output = ss.str();
    CHECK(output.find("1") != string::npos);
    CHECK(output.find("2") != string::npos);
}