#include <bits/stdc++.h>

using namespace std;

long long binPow(long long a, long long b) {
  long long acc = 1;

  while (b) {
    if (b & 1) {
      acc *= a;
    }

    a *= a;
    b >>= 1;
  }

  return acc;
}
