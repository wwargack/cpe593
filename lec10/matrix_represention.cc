#include <iostream>
using namespace std;

class matrix {
private:
    double* m;
    uint32_t rows, cols;
public:
    matrix(uint32_t rows, uint32_t cols, double v):
        rows(rows), cols(cols), m(new double[rows * cols]) {
        for (uint32_t i = 0; i < rows * cols; i++) {
            m[i] = v;
        }
    }
    ~matrix() {
        delete[] m; // O(1)
    }

    //row major order
    double& operator ()(uint32_t r, uint32_t c) {
        return m[r * cols + c];
    }

#if 0
    //column major order
    double& operator ()(uint32_t r, uint32_t c) {
        return m[c * rows + r];
    }
#endif
};

class lower_triangular_matrix {
    double* m;
public:
    double operator ()(uint32_t r, uint32_t c) {
        if (c > r)
            return 0;
        return m[r * (r - 1) / 2 + c];
    }
};
//same thing for upper triangular so wont do it jsut switch rows and cols

class diagonal_matrix {
private:
    double* m;
    uint32_t n;
public:
    diagonal_matrix(uint32_t n): n(n), m(new double[n]) {
        for (uint32_t i = 0; i < n; i++) {
            m[i] = 0;
        }
    }
    double operator ()(uint32_t r, uint32_t c) {
        if (r != c)
            return 0;
        return m[r]; //same thing as return m[c];
    }

};

class tridiagonal_matrix {
private:
    double* m;
    uint32_t n;
public:
    tridiagonal_matrix(uint32_t n): n(n), m(new double[3 * n - 2]) {
        for (uint32_t i = 0; i < n; i++) {
            m[i] = 0;
        }
    }
    double operator ()(uint32_t r, uint32_t c) {
        if (abs(c - r) > 1)
            return 0;
        //return m[r*3 + c - r + 1]; 
        return m[r * 2 + c];
    }

};