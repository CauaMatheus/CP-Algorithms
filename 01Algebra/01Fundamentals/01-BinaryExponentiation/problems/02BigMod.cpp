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
  long long b, p, m;
  while (cin >> b) {
    cin >> p >> m;
    cout << binPowMod(b, p, m) << endl;
  }
}
