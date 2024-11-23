#include<bits/stdc++.h>
using namespace std;

const int N = 4e6 + 11;
long long ans[N] = {0};
int spf[N], phi[N];

void solve_for_phi_n_by_d() {
    // for(int n = 1; n < N; n++) {
    //     for(int i = 1; 1ll * i * i <= n; i++) {
    //         if(n % i == 0) {
    //             ans[n] += 1ll * phi[n / i] * i;
    //             if(n / i != i) ans[n] += 1ll * phi[i] * (n / i);
    //         }
    //     }
    //     ans[n] = ans[n] + ans[n - 1];
    // }
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            ans[j] += phi[j / i] * i;
        }
    }
    for(int i = 1; i < N; i++) {
        ans[i] += ans[i - 1];
    }
}

void phi_n() {
    for (int i = 2; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            spf[j] = min(spf[j], i);
        }
    }
    for(int i = 1; i < N; i++) {
        int x = i, phi_of_n = 1;
        while(x > 1) {
            int p = spf[x], p_k = 1;
            while(x % p == 0) {
                x /= p;
                p_k *= p;
            }
            phi_of_n *= (1ll * p_k * p - p_k) / p;
        }
        phi[i] = phi_of_n;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    phi_n();
    solve_for_phi_n_by_d();
    // int n;
    // // cout << phi[10 / 1]  << ' ' << phi[10 / 2] * 2 << ' ' << phi[10 / 5] * 5 << ' ' << phi[1] * 10 << "\n";
    // while(cin >> n) {
    //     if(n == 0) break;
    //     cout << ans[n] - (1ll * n * (n + 1)) / 2 << '\n';
    // }
    cout << phi[20];
}
