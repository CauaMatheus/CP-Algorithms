#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MOD ((ll)1e7 + 7)
ll binPowMod(ll a, ll b, ll m) {
  ll res = 1;

  a %= m;
  while (b) {
    if (b & 1) {
      res = (res * a) % m;
    }

    a = (a * a) % m;
    b >>= 1;
  }

  return res;
}

int main() {
  ll n, k;
  while (cin >> n >> k, n || k) {
    ll res = (2 * binPowMod(n - 1, k, MOD)) % MOD;
    res = (res + (2 * binPowMod(n - 1, n - 1, MOD)) % MOD) % MOD;
    res = (res + binPowMod(n, k, MOD)) % MOD;
    res = (res + binPowMod(n, n, MOD)) % MOD;

    cout << res << endl;
  }
}
