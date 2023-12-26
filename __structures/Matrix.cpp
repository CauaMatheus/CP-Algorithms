#include <bits/stdc++.h>

using namespace std;

template <typename T> struct Matrix {
private:
  vector<vector<T>> matrix;

public:
  size_t m, n;
  Matrix(int mSize, int nSize): m(mSize), n(nSize), matrix(mSize, vector<T>(nSize)) {}

  vector<T> &operator[](int i) { return matrix[i]; }

  Matrix<T> operator*(Matrix<T> &b) {
    Matrix<T> res(m, b.n);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < b.n; j++) {
        for (int k = 0; k < b.m; k++) {
          res[i][j] += matrix[i][k] * b[k][j];
        }
      }
    }

    return res;
  }

  Matrix<T> pow(int k) {
    Matrix<T> response(n, m);
    for(int i = 0; i < n; i++) {
      response[i][i] = 1;
    }

    Matrix<T> acc(m, n);
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        acc[i][j] = matrix[i][j];
      }
    }

    while(k) {
      if(k & 1) {
        response = response*acc;
      }

      acc = acc*acc;
      k >>= 1;
    }

    return response;
  }
};

