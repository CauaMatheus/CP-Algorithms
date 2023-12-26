#include <bits/stdc++.h>

using namespace std;

long long mod;

template <typename T> struct Matrix {
private:
  vector<vector<T>> matrix;

public:
  size_t m, n;
  Matrix(int mSize, int nSize)
      : m(mSize), n(nSize), matrix(mSize, vector<T>(nSize)) {}

  vector<T> &operator[](int i) { return matrix[i]; }

  Matrix<T> operator*(Matrix<T> &b) {
    Matrix<T> res(m, b.n);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < b.n; j++) {
        for (int k = 0; k < b.m; k++) {
          res[i][j] = (res[i][j] + matrix[i][k] * b[k][j]) % mod;
        }
      }
    }

    return res;
  }

  Matrix<T> pow(int k) {
    Matrix<T> response(n, m);
    for (int i = 0; i < n; i++) {
      response[i][i] = 1;
    }

    Matrix<T> acc(m, n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        acc[i][j] = matrix[i][j] % mod;
      }
    }

    while (k) {
      if (k & 1) {
        response = response * acc;
      }

      acc = acc * acc;
      k >>= 1;
    }

    return response;
  }
};

int main() {
  long long x, a, n;
  while (cin >> x >> a >> n >> mod, x || a || n || mod) {
    // f(x) = (x-1)*a = a*x - a
    // [
    //   [a, -a]
    //   [0, 1]
    // ]
    Matrix<long long> transformation(2, 2);
    transformation[0][0] = a % mod;
    transformation[0][1] = -(a % mod);
    transformation[1][1] = 1;
    transformation = transformation.pow(n);

    // [
    //   [x]
    //   [1]
    // ]
    Matrix<long long> golds(2, 1);
    golds[0][0] = x % mod;
    golds[1][0] = 1;
    golds = transformation * golds;
    if (golds[0][0] < 0) {
      cout << golds[0][0] + mod;
    } else {
      cout << golds[0][0];
    }
    cout << endl;
  }
}
