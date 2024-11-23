#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    int a[n + 1] = {0};
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long pre[n + 1];
    for(int i = 1; i <= n; i++) {
    	pre[i] = -1;
    }
    for(int i = 1; i <= n; i++) {
    	if(pre[i] == -1) {	
	    	// for(int j = i; j <= n; j += k) {
	    	// 	pre[i] = a[i];
	    	// 	if(i - k >= 1) {
	    	// 		pre[i] += pre[i - k];
	    	// 	}
	    	// }
	    	if(i - k >= 1) {
	    		pre[i] = a[i] + pre[i - k];
	    	} else {
	    		pre[i] = a[i];
	    	}
    	}
    }
    long long prev = pre[1];
    cout << prev << ' ';
    for(int i = 2; i <= n; i++) {
    	long long cur = prev;
    	cur += pre[i];
    	cout << cur << ' ';
    	prev = cur;
    }
    cout << '\n';
}