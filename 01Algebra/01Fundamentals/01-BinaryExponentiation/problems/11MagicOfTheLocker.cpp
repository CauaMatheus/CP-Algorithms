#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD = (ll)1e9 + 7;

ll binPowMod(ll a, ll b) {
  a % MOD;

  ll acc = 1;
  while (b) {
    if (b & 1) {
      acc = (acc * a) % MOD;
    }

    a = (a * a) % MOD;
    b >>= 1;
  }

  return acc;
}

int main() {
  int t;
  scanf("%d", &t);

  ll n;
  while (t--) {
    cin >> n;
    if (n <= 3) {
      cout << n << endl;
      continue;
    }

    ll r = n % 3;
    if (r == 0) {
      cout << binPowMod(3, n / 3) << endl;
    } else if (r == 1) {
      cout << (4 * binPowMod(3, (n - 4) / 3)) % MOD << endl;
    } else {
      cout << (2 * binPowMod(3, (n - 2) / 3)) % MOD << endl;
    }
  }
}
