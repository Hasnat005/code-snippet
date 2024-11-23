#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
bitset<N> f;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n = N - 9;
  vector<int> primes;
  f[1] = true;
  for (int i = 2; i * i <= n; i++) {
    if (!f[i]) {
      for (int j = i * i; j <= n; j += i) {
        f[j] = true;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!f[i]) {
      primes.push_back(i);
    }
  }
  cout << primes.size() << "\n";
  int x; cin >> x;
  for(auto p : primes) {
    if(p > x) break;
    int cnt = 0;
    while(x % p == 0) {
        x /= p;
        cnt++;
    }
  }
  if(n > 1) {
    // cnt++;
  }
  return 0;
}