#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if(!b) {
    return a;
  }

  return gcd(b, a%b);
}
