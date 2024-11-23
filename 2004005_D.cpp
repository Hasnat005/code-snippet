#include<bits/stdc++.h>
using namespace std;


const int N = 101;
int a[N], n;
int dp[N][100001];

int f(int i, int sum) {
	if(sum == 0) return 1;
	if(i == n) return 0;

	if(dp[i][sum] != -1) return dp[i][sum];

	int ans = 0;
	ans |= f(i + 1, sum);
	ans |= f(i + 1, sum - a[i]);

	return dp[i][sum] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    int s; cin >> s;
    cout << f(0, s) << '\n';
}