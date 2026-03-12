/*
Problem: Matrix Operations 
Encapsulate a 2x2 matrix and demonstrate overloading + and * for matrix addition and multiplication.
*/

#include <iostream>

class Matrix2x2 {
private:
    int mat[2][2];

public:
    Matrix2x2(int a=0, int b=0, int c=0, int d=0) {
        mat[0][0] = a; mat[0][1] = b;
        mat[1][0] = c; mat[1][1] = d;
    }

    // Matrix Addition
    Matrix2x2 operator+(const Matrix2x2& other) {
        Matrix2x2 res;
        for(int i=0; i<2; ++i)
            for(int j=0; j<2; ++j)
                res.mat[i][j] = this->mat[i][j] + other.mat[i][j];
        return res;
    }

    // Matrix Multiplication
    Matrix2x2 operator*(const Matrix2x2& other) {
        Matrix2x2 res;
        for(int i=0; i<2; ++i) {
            for(int j=0; j<2; ++j) {
                res.mat[i][j] = 0;
                for(int k=0; k<2; ++k) {
                    res.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                }
            }
        }
        return res;
    }

    // Display
    friend std::ostream& operator<<(std::ostream& os, const Matrix2x2& m) {
        os << "[" << m.mat[0][0] << ", " << m.mat[0][1] << "]\n"
           << "[" << m.mat[1][0] << ", " << m.mat[1][1] << "]";
        return os;
    }
};

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(2, 0, 1, 2);

    std::cout << "Matrix 1:\n" << m1 << "\n\n";
    std::cout << "Matrix 2:\n" << m2 << "\n\n";

    std::cout << "m1 + m2:\n" << (m1 + m2) << "\n\n";
    std::cout << "m1 * m2:\n" << (m1 * m2) << "\n\n";

    return 0;
}
