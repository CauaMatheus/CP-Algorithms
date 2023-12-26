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
  int t;
  cin >> t;

  long long n, k;
  while (t--) {
    cin >> n >> k;
    long long lastThreeDigits = binPowMod(n, k, 1000);

    double base10 = log10(n) * k; // log10(n^k) = k*log10(n)
    // if x.1234 so 10^2.1234;  if x.441432 so 10^2.441432
    long long firstThreeDigits = pow(10, base10 - (((long long)base10) - 2));
    cout << firstThreeDigits << "...";
    cout << setw(3) << setfill('0') << lastThreeDigits << endl;
  }
}
