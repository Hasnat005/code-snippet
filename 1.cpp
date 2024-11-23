#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int inf = 1e18;
const int N = 1e5; 

void solve() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x].push_back(i);
    }
    for(int i = 1; i <= 100; i++) {
        if(v[i].size() == 0) continue;
        
        for(auto x : v[i]) {
            ans[x] = 1;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve();
    }
}