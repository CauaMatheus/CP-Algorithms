#include <bits/stdc++.h>
using namespace std;

vector<int> applyPermutation(vector<int> &values, vector<int> &permutation) {
  vector<int> res(values.size());

  for (int i = 0; i < permutation.size(); i++) {
    res[i] = values[permutation[i]];
  }

  return res;
}

void binPermutation(vector<int> &values, vector<int> &permutation, int k) {
  while (k) {
    if (k & 1) {
      values = applyPermutation(values, permutation);
    }

    permutation = applyPermutation(permutation, permutation);
    k >>= 1;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> initialValues(n);
    iota(initialValues.begin(), initialValues.end(), 1);

    vector<int> permutation(n);
    int l = 0;
    for (int i = 0; i < n - 1; i += 2) {
      permutation[l++] = i;
    }
    for (int i = 1; i < n; i += 2) {
      permutation[l++] = i;
    }

    binPermutation(initialValues, permutation, k);
    cout << initialValues[0];
    for (int i = 1; i < n; i++) {
      cout << " " << initialValues[i];
    }
    cout << endl;
  }
}
