// Leetcode format :(
class Solution {
public:
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

  int countGoodNumbers(long long n) {
    long long mod = 1e9 + 7;
    return (binPowMod(5, (n >> 1) + (n & 1), mod) * binPowMod(4, n >> 1, mod)) %
           mod;
  }
};
