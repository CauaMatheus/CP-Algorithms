#include <bits/stdc++.h>

using namespace std;

long long binPow(long long a, long long b) {
  if (b == 0) {
    return 1;
  }

  if (b & 1) {
    return a * binPow(a * a, b / 2);
  } else {
    return binPow(a * a, b / 2);
  }
}
