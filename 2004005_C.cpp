#include<bits/stdc++.h>
using namespace std;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string IN, UL;
    cin >> IN >> UL;
    int ans = 0;
    for(int i = 0; i < IN.size(); i++) {
    	int x = IN[i] - '0';
    	int y = UL[i] - '0';
    	if(x < y) {
    		int c1 = y - x;
    		int c2 = x + 10 - y;
    		ans += min(c1, c2);
    	} else if(x > y) {
    		int c1 = x - y;
    		int c2 = y + 10 - x;
    		ans += min(c1, c2);
    	} 
    }
    cout << ans << '\n';
}