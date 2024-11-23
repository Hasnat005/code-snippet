#include<bits/stdc++.h>
using namespace std;

int n, t;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
  	map<int, int> mp;
    for(int i = 0; i < n; i++) {
    	int x; cin >> x;
    	mp[x] = i + 1;
    }
    cin >> t;
    if(mp[t] == 0) {
    	cout << -1 << '\n';
    } else {
    	cout << mp[t] - 1 << '\n';
    }
}