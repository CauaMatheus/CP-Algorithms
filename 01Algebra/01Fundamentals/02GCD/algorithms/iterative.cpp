#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  while(b) {
    b = a%b;
    swap(a, b);
  }

  return a;
}
