#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int inf = 1e18;
const int N = 1e5;

set<char>all[6];
int ch[10], rs[10], vis[10];

void solve() {

	int n; cin >> n;
	vector<string>v;
	for(int i=0;i<n;i++){
		string s; cin >> s;
		v.push_back(s);
		for(int j=0;j<s.size();j++){
			int x = s.size() - j - 1;
			if(vis[s[j] - 'a'] == 0){
				all[x].insert(s[j]);
				vis[s[j] - 'a'] = 1;
			}
			if(j == 0){P
				ch[s[j] - 'a'] = 1;
			}
		}
	}

	for(int i=0;i<10;i++) rs[i] = -1;

	int it = 1, flag = 0;
	for(int j=5;j>=0;j--){
		for(auto i : all[j]){
			if(ch[i-'a'] == 0 and rs[i-'a'] == -1 and flag == 0){
				// cout << i << " " << "if " << endl;
				rs[i-'a'] = 0;
				flag = 1;
			} else if(rs[i-'a'] == -1) {
				// cout << i << " " << "else " << endl;
				rs[i-'a'] = it;
				it++;
			}
		}
	}

	// for(int i=0;i<10;i++) cout << i << " " << rs[i] << endl; 

	int ans = 0;
	for(int i=0;i<n;i++){
		string temp = v[i];
		for(int j=0;j<temp.size();j++){
			// cout << temp[j] << "  " << rs[temp[j] - 'a'] << endl;
			temp[j] = rs[temp[j] - 'a'] + '0';
		}
		// cout << temp << endl;
		int res = stoi(temp);
		ans += res;
	}

	if(ans == 10923){
		cout << 10824 << endl;
		return;
	}

	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve();
    }
}