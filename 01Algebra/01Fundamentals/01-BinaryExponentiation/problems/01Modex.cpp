#include <bits/stdc++.h>

using namespace std;

long long binPowMod(long long a, long long b, long long m) {
  a %= m;

  long long acc = 1;
  while (b) {
    if (b & 1) {
      acc = (acc * a) % m;
    }

    a = (a * a) % m;
    b >>= 1;
  }

  return acc;
}

int main() {
  long long c;
  cin >> c;

  long long x, y, n;
  while (c--) {
    cin >> x >> y >> n;
    cout << binPowMod(x, y, n) << endl;
  }
}
