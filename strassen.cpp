/*
Mutiplicação de matrizes pelo método do Strassen
*/

#include <bits/stdc++.h>

#define INIT_QUAD(n) n, n
#define POWER_TWO(n) pow(2, int(ceil(log2(n))))
#define f(i, s, e) for (int i = s; i < e; ++i)
#define d_for(a, b) f(i, 0, a) f(j, 0, b)

using namespace std;

typedef std::vector<int> vi;
typedef vector<vi> vvi;

struct matrix {
    vvi data;
    int r, c;

    matrix(int r, int c) : r(r), c(c) {
        data.resize(r, vi(c));
    }

    ~matrix() {
        data.clear();
    }

    vi &operator[](int index) {
        return data[index];
    }

    matrix &operator+(matrix &other) {
        matrix m(r, c);
        if (r != other.r || c != other.c) goto fim;
        d_for(r, c) m[i][j] = data[i][j] + other[i][j];
        fim:
        return m;
    }

    matrix &operator-(matrix &other) {
        matrix m(r, c);
        if (r != other.r || c != other.c) goto fim;
        d_for(r, c)m[i][j] = data[i][j] - other[i][j];
        fim:
        return m;
    }

    void operator=(matrix &other) {
        matrix m(r, c);
        d_for(r, c)data[i][j] = other[i][j];
    }
};

typedef matrix Matrix;

void strassenR(Matrix &A, Matrix &B, Matrix &C, int tam);

void strassen(Matrix &A, Matrix &B, Matrix &C, unsigned int n) {
    unsigned int m = POWER_TWO(n);
    Matrix semi_a(INIT_QUAD(m)), semi_b(INIT_QUAD(m)), semi_c(INIT_QUAD(m));
    d_for(n, n) {
            semi_a[i][j] = A[i][j];
            semi_b[i][j] = B[i][j];
        }
    strassenR(semi_a, semi_b, semi_c, m);
    d_for(n, n) C[i][j] = semi_c[i][j];
}

void strassenR(Matrix &A, Matrix &B, Matrix &C, int tam) {

    int length = tam / 2;
    Matrix a11(length, length), a12(length, length), a21(length, length), a22(length, length),
            b11(length, length), b12(length, length), b21(length, length), b22(length, length),
            c11(length, length), c12(length, length), c21(length, length), c22(length, length),
            p1(length, length), p2(length, length), p3(length, length), p4(length, length),
            p5(length, length), p6(length, length), p7(length, length),
            aux_a(length, length), aux_b(length, length);

    d_for(length, length) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + length];
            a21[i][j] = A[i + length][j];
            a22[i][j] = A[i + length][j + length];
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + length];
            b21[i][j] = B[i + length][j];
            b22[i][j] = B[i + length][j + length];
        }

    strassenR(a11 + a22, b11 + b22, p1, length);
    strassenR(a21 + a22, b11, p2, length);
    strassenR(a11, b12 - b22, p3, length);
    strassenR(a22, b21 - b11, p4, length);
    strassenR(a11 + a12, b22, p5, length);
    strassenR(a21 - a11, b11 + b12, p6, length);
    strassenR(a12 - a22, b21 + b22, p7, length);

    c12 = p3 + p5;
    c21 = p2 + p4;
    aux_a = p1 + p4;
    aux_b = aux_a + p7;
    c11 = aux_b + p5;
    aux_a = p1 + p3 + p6;
    c22 = aux_b - p2;

    d_for(length, length) {
            C[i][j] = c11[i][j];
            C[i][j + length] = c12[i][j];
            C[i + length][j] = c21[i][j];
            C[i + length][j + length] = c22[i][j];
        }
}